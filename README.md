# MultiNanopolish

Nanopolish is a software package for signal-level analysis of Oxford Nanopore sequencing data. Nanopolish can calculate an improved consensus sequence for a draft genome assembly, detect base modifications, call SNPs and indels with respect to a reference genome and more (see [Nanopolish](https://github.com/jts/nanopolish) for more details).

We present an efficient  implementation of Nanopolish, called MultiNanopolish. MultiNanopolish use a different iterative calculation strategy to reduce redundant calculations.  We present an independent computing unit(GroupTask) and distribute them to the thread pool for multi-thread concurrent computing.

## Method
###  Iterative calculation in parallel
In the iterative calculation stage of the original Nanopolish program, it is mainly divided into two steps, filter and combination. In the filter step, all variants with negative scores will be filtered out; the combination step is to combine variants into sets that maximize their HMM score. In the combination step, the variants are divided into sets of different sizes. The basis for forming the sets is that the distance between the variants in a single set (the distance between the variants ref positions) is less than a threshold min_distance_between_variants. These two steps will repeat until the called variants set no longer changes.

The ref position corresponding to the variants in sets will not change, once the sets are formed, they can exist as an independent calculation unit. The ref position corresponding to the sets has a certain range, that is, it no longer depends on the variants in other sets. However, the sets may split, because some variants will be filtered out in the filter step, resulting in the distance between adjacent variants increasing by more than min_distance_between_variants.

After ensuring that variants set can exist as an independent calculation unit, we abstract it into a class, GroupTask. After stage two, we closely follow a filter step, which is to initially reduce the number of variants and unnecessary computing. After the filter step, all the variants are divided into independent group tasks. We hand these independent tasks to the thread pool for processing. Each thread processes a batch of tasks with the size of Q. After each iteration, the thread will check whether the task is stable(called variants sets will not change any more). If it is, it will be removed from the calculation queue and a new task will be introduced for calculation; otherwise, it will continue to iterate until it is stable.

![parallel structure](https://github.com/BoredMa/MultiNanopolish/blob/master/test/MultiNanopolish.png)

## Result

MultiNanopolish speeds up the iterative calculation process almost 3 times and speeds up the
whole program more than 2 times based on 40 thread mode comparing to the original Nanopolish.

![MultiNanopolish experiment result](https://github.com/BoredMa/MultiNanopolish/blob/master/test/performance.png)