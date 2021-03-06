cmake_minimum_required(VERSION 3.5)
project(nanopolish)

set(CMAKE_CXX_STANDARD 14)

include_directories(fast5/include)
include_directories(fast5/include/fast5)
include_directories(fast5/src)
include_directories(htslib)
include_directories(htslib/cram)
include_directories(htslib/htslib)
include_directories(src)
include_directories(src/alignment)
include_directories(src/builtin_models)
include_directories(src/common)
include_directories(src/cuda_kernels)
include_directories(src/hmm)
include_directories(src/pore_model)
include_directories(src/test)
include_directories(src/thirdparty)
include_directories(src/thirdparty/scrappie)

add_executable(nanopolish
        docs/source/_static/nanopolish-workflow.png
        docs/source/_static/quickstart_methylation_results.png
        docs/source/conf.py
        docs/source/debug.rst
        docs/source/index.rst
        docs/source/installation.rst
        docs/source/manual.rst
        docs/source/quickstart_call_methylation.rst
        docs/source/quickstart_consensus.rst
        docs/source/quickstart_eventalign.rst
        docs/Makefile
        etc/r9-models/r9.4_450bps.cpg.6mer.template.model
        etc/r9-models/r9.4_450bps.nucleotide.5mer.template.model
        etc/r9-models/r9.4_450bps.nucleotide.6mer.template.model
        etc/r9-models/r9.4_70bps.u_to_t_rna.5mer.template.model
        etc/r9-models/r9_250bps.cpg.6mer.template.model
        etc/r9-models/r9_250bps.nucleotide.5mer.complement.pop1.model
        etc/r9-models/r9_250bps.nucleotide.5mer.complement.pop2.model
        etc/r9-models/r9_250bps.nucleotide.5mer.template.model
        etc/r9-models/r9_250bps.nucleotide.6mer.complement.pop1.model
        etc/r9-models/r9_250bps.nucleotide.6mer.complement.pop2.model
        etc/r9-models/r9_250bps.nucleotide.6mer.template.model
        fast5/include/fast5/Bit_Packer.hpp
        fast5/include/fast5/cwmap.fast5_ed_len_1.inl
        fast5/include/fast5/cwmap.fast5_ed_skip_1.inl
        fast5/include/fast5/cwmap.fast5_ev_move_1.inl
        fast5/include/fast5/cwmap.fast5_ev_rel_skip_1.inl
        fast5/include/fast5/cwmap.fast5_fq_bp_1.inl
        fast5/include/fast5/cwmap.fast5_fq_qv_1.inl
        fast5/include/fast5/cwmap.fast5_rw_1.inl
        fast5/include/fast5/fast5_version.hpp
        fast5/include/fast5/hdf5_tools.hpp
        fast5/include/fast5/Huffman_Packer.hpp
        fast5/include/fast5/logger.hpp
        fast5/include/fast5.hpp
        fast5/python/bin/f5ls
        fast5/python/bin/f5pack
        fast5/python/fast5/fast5.pyx
        fast5/python/Makefile
        fast5/python/setup.py
        fast5/src/f5-mod.cpp
        fast5/src/f5dump.cpp
        fast5/src/f5ls-full.cpp
        fast5/src/f5ls.cpp
        fast5/src/f5pack.cpp
        fast5/src/File_Packer.hpp
        fast5/src/hdf5-mod.cpp
        fast5/src/huffman-decode.cpp
        fast5/src/huffman-encode.cpp
        fast5/src/hufftk
        fast5/src/Makefile
        fast5/src/tmp.cpp
        fast5/Doxyfile
        fast5/LICENSE
        fast5/README.org
        fast5/VERSION
        htslib/cram/cram.h
        htslib/cram/cram_codecs.c
        htslib/cram/cram_codecs.h
        htslib/cram/cram_decode.c
        htslib/cram/cram_decode.h
        htslib/cram/cram_encode.c
        htslib/cram/cram_encode.h
        htslib/cram/cram_external.c
        htslib/cram/cram_index.c
        htslib/cram/cram_index.h
        htslib/cram/cram_io.c
        htslib/cram/cram_io.h
        htslib/cram/cram_samtools.c
        htslib/cram/cram_samtools.h
        htslib/cram/cram_stats.c
        htslib/cram/cram_stats.h
        htslib/cram/cram_structs.h
        htslib/cram/files.c
        htslib/cram/mFILE.c
        htslib/cram/mFILE.h
        htslib/cram/misc.h
        htslib/cram/open_trace_file.c
        htslib/cram/open_trace_file.h
        htslib/cram/os.h
        htslib/cram/pooled_alloc.c
        htslib/cram/pooled_alloc.h
        htslib/cram/rANS_byte.h
        htslib/cram/rANS_static.c
        htslib/cram/rANS_static.h
        htslib/cram/sam_header.c
        htslib/cram/sam_header.h
        htslib/cram/string_alloc.c
        htslib/cram/string_alloc.h
        htslib/cram/vlen.c
        htslib/cram/vlen.h
        htslib/cram/zfio.c
        htslib/cram/zfio.h
        htslib/htslib/bgzf.h
        htslib/htslib/cram.h
        htslib/htslib/faidx.h
        htslib/htslib/hfile.h
        htslib/htslib/hts.h
        htslib/htslib/hts_defs.h
        htslib/htslib/hts_endian.h
        htslib/htslib/kbitset.h
        htslib/htslib/kfunc.h
        htslib/htslib/khash.h
        htslib/htslib/khash_str2int.h
        htslib/htslib/klist.h
        htslib/htslib/knetfile.h
        htslib/htslib/kseq.h
        htslib/htslib/ksort.h
        htslib/htslib/kstring.h
        htslib/htslib/regidx.h
        htslib/htslib/sam.h
        htslib/htslib/synced_bcf_reader.h
        htslib/htslib/tbx.h
        htslib/htslib/thread_pool.h
        htslib/htslib/vcf.h
        htslib/htslib/vcf_sweep.h
        htslib/htslib/vcfutils.h
        "htslib/test/auxf#values.sam"
        "htslib/test/auxf#values_java.cram"
        htslib/test/auxf.fa
        htslib/test/auxf.fa.fai
        htslib/test/bgziptest.txt
        htslib/test/bgziptest.txt.gz
        htslib/test/bgziptest.txt.gz.gzi
        "htslib/test/c1#bounds.sam"
        "htslib/test/c1#clip.sam"
        "htslib/test/c1#noseq.sam"
        "htslib/test/c1#pad1.sam"
        "htslib/test/c1#pad2.sam"
        "htslib/test/c1#pad3.sam"
        "htslib/test/c1#unknown.sam"
        htslib/test/c1.fa
        htslib/test/c1.fa.fai
        "htslib/test/c2#pad.sam"
        htslib/test/c2.fa
        htslib/test/c2.fa.fai
        "htslib/test/ce#1.sam"
        "htslib/test/ce#2.sam"
        "htslib/test/ce#5.sam"
        "htslib/test/ce#5b.sam"
        "htslib/test/ce#5b_java.cram"
        "htslib/test/ce#large_seq.sam"
        "htslib/test/ce#supp.sam"
        "htslib/test/ce#tag_depadded.sam"
        "htslib/test/ce#tag_padded.sam"
        "htslib/test/ce#unmap.sam"
        "htslib/test/ce#unmap1.sam"
        "htslib/test/ce#unmap2.sam"
        htslib/test/ce.fa
        htslib/test/ce.fa.fai
        htslib/test/compare_sam.pl
        htslib/test/cross_validate.sh
        htslib/test/faidx.fa
        htslib/test/fieldarith.c
        htslib/test/fieldarith.sam
        htslib/test/formatcols.vcf
        htslib/test/formatmissing-out.vcf
        htslib/test/formatmissing.vcf
        htslib/test/hfile.c
        htslib/test/hts_endian.c
        "htslib/test/md#1.sam"
        htslib/test/md.fa
        htslib/test/md.fa.fai
        htslib/test/noroundtrip-out.vcf
        htslib/test/noroundtrip.vcf
        htslib/test/sam.c
        htslib/test/test-regidx.c
        htslib/test/test-vcf-api.c
        htslib/test/test-vcf-api.out
        htslib/test/test-vcf-hdr-in.vcf
        htslib/test/test-vcf-hdr.out
        htslib/test/test-vcf-sweep.c
        htslib/test/test-vcf-sweep.out
        htslib/test/test.pl
        htslib/test/test_view.c
        htslib/test/thrash_threads1.c
        htslib/test/thrash_threads2.c
        htslib/test/thrash_threads3.c
        htslib/test/thrash_threads4.c
        htslib/test/thrash_threads5.c
        htslib/test/thrash_threads6.c
        "htslib/test/xx#blank.sam"
        "htslib/test/xx#large_aux.sam"
        "htslib/test/xx#large_aux2.sam"
        "htslib/test/xx#large_aux_java.cram"
        "htslib/test/xx#minimal.sam"
        "htslib/test/xx#pair.sam"
        "htslib/test/xx#repeated.sam"
        "htslib/test/xx#rg.sam"
        "htslib/test/xx#tlen.sam"
        "htslib/test/xx#tlen2.sam"
        "htslib/test/xx#triplet.sam"
        "htslib/test/xx#unsorted.sam"
        htslib/test/xx.fa
        htslib/test/xx.fa.fai
        htslib/bgzf.c
        htslib/bgzip.c
        htslib/config.mk.in
        htslib/configure.ac
        htslib/errmod.c
        htslib/faidx.5
        htslib/faidx.c
        htslib/hfile.c
        htslib/hfile_gcs.c
        htslib/hfile_internal.h
        htslib/hfile_libcurl.c
        htslib/hfile_net.c
        htslib/hfile_s3.c
        htslib/hts.c
        htslib/hts_internal.h
        htslib/htsfile.1
        htslib/htsfile.c
        htslib/htslib.mk
        htslib/htslib.pc.in
        htslib/htslib_vars.mk
        htslib/INSTALL
        htslib/kfunc.c
        htslib/knetfile.c
        htslib/kstring.c
        htslib/LICENSE
        htslib/Makefile
        htslib/md5.c
        htslib/multipart.c
        htslib/NEWS
        htslib/plugin.c
        htslib/probaln.c
        htslib/README
        htslib/README.md
        htslib/realn.c
        htslib/regidx.c
        htslib/sam.5
        htslib/sam.c
        htslib/synced_bcf_reader.c
        htslib/tabix.1
        htslib/tabix.c
        htslib/tbx.c
        htslib/textutils.c
        htslib/thread_pool.c
        htslib/thread_pool_internal.h
        htslib/vcf.5
        htslib/vcf.c
        htslib/vcf_sweep.c
        htslib/vcfutils.c
        scripts/calculate_methylation_frequency.py
        scripts/consensus-preprocess.pl
        scripts/consensus.make
        scripts/convert_all_models.py
        scripts/convert_model_to_header.py
        scripts/dropmodel.py
        scripts/extract_reads_aligned_to_region.py
        scripts/import_ont_model.py
        scripts/import_ont_models_from_dir.sh
        scripts/nanopolish_makerange.py
        scripts/nanopolish_merge.py
        scripts/reestimate_polya_emissions.py
        src/alignment/nanopolish_alignment_db.cpp
        src/alignment/nanopolish_alignment_db.h
        src/alignment/nanopolish_anchor.cpp
        src/alignment/nanopolish_anchor.h
        src/alignment/nanopolish_eventalign.cpp
        src/alignment/nanopolish_eventalign.h
        src/builtin_models/r9_250bps_cpg_6mer_template_model.inl
        src/builtin_models/r9_250bps_nucleotide_5mer_complement_pop1_model.inl
        src/builtin_models/r9_250bps_nucleotide_5mer_complement_pop2_model.inl
        src/builtin_models/r9_250bps_nucleotide_5mer_template_model.inl
        src/builtin_models/r9_250bps_nucleotide_6mer_complement_pop1_model.inl
        src/builtin_models/r9_250bps_nucleotide_6mer_complement_pop2_model.inl
        src/builtin_models/r9_250bps_nucleotide_6mer_template_model.inl
        src/builtin_models/r9_4_450bps_cpg_6mer_template_model.inl
        src/builtin_models/r9_4_450bps_dam_6mer_template_model.inl
        src/builtin_models/r9_4_450bps_dcm_6mer_template_model.inl
        src/builtin_models/r9_4_450bps_nucleotide_5mer_template_model.inl
        src/builtin_models/r9_4_450bps_nucleotide_6mer_template_model.inl
        src/builtin_models/r9_4_70bps_u_to_t_rna_5mer_template_model.inl
        src/common/alg.hpp
        src/common/fs_support.cpp
        src/common/fs_support.hpp
        src/common/logger.hpp
        src/common/logsum.cpp
        src/common/logsum.h
        src/common/logsumset.hpp
        src/common/nanopolish_alphabet.cpp
        src/common/nanopolish_alphabet.h
        src/common/nanopolish_bam_processor.cpp
        src/common/nanopolish_bam_processor.h
        src/common/nanopolish_bam_utils.cpp
        src/common/nanopolish_bam_utils.h
        src/common/nanopolish_common.cpp
        src/common/nanopolish_common.h
        src/common/nanopolish_fast5_io.cpp
        src/common/nanopolish_fast5_io.h
        src/common/nanopolish_iupac.cpp
        src/common/nanopolish_iupac.h
        src/common/nanopolish_klcs.cpp
        src/common/nanopolish_klcs.h
        src/common/nanopolish_matrix.h
        src/common/nanopolish_variant.cpp
        src/common/nanopolish_variant.h
        src/common/profiler.h
        src/common/progress.h
        src/hmm/invgauss.hpp
        src/hmm/nanopolish_duration_model.cpp
        src/hmm/nanopolish_duration_model.h
        src/hmm/nanopolish_emissions.h
        src/hmm/nanopolish_hmm_input_sequence.h
        src/hmm/nanopolish_profile_hmm.cpp
        src/hmm/nanopolish_profile_hmm.h
        src/hmm/nanopolish_profile_hmm_r7.cpp
        src/hmm/nanopolish_profile_hmm_r7.h
        src/hmm/nanopolish_profile_hmm_r7.inl
        src/hmm/nanopolish_profile_hmm_r9.cpp
        src/hmm/nanopolish_profile_hmm_r9.h
        src/hmm/nanopolish_profile_hmm_r9.inl
        src/hmm/nanopolish_transition_parameters.cpp
        src/hmm/nanopolish_transition_parameters.h
        src/main/nanopolish.cpp
        src/pore_model/nanopolish_builtin_models.h
        src/pore_model/nanopolish_model_names.cpp
        src/pore_model/nanopolish_model_names.h
        src/pore_model/nanopolish_pore_model_set.cpp
        src/pore_model/nanopolish_pore_model_set.h
        src/pore_model/nanopolish_poremodel.cpp
        src/pore_model/nanopolish_poremodel.h
        src/test/catch.hpp
        src/test/nanopolish_test.cpp
        src/thirdparty/scrappie/event_detection.c
        src/thirdparty/scrappie/event_detection.h
        src/thirdparty/scrappie/scrappie_common.c
        src/thirdparty/scrappie/scrappie_common.h
        src/thirdparty/scrappie/scrappie_stdlib.h
        src/thirdparty/scrappie/scrappie_structures.h
        src/thirdparty/scrappie/sse_mathfun.h
        src/thirdparty/scrappie/util.c
        src/thirdparty/scrappie/util.h
        src/thirdparty/stdaln.c
        src/thirdparty/stdaln.h
        src/nanopolish_call_methylation.cpp
        src/nanopolish_call_methylation.h
        src/nanopolish_call_variants.cpp
        src/nanopolish_call_variants.h
        src/nanopolish_extract.cpp
        src/nanopolish_extract.h
        src/nanopolish_getmodel.cpp
        src/nanopolish_getmodel.h
        src/nanopolish_haplotype.cpp
        src/nanopolish_haplotype.h
        src/nanopolish_index.cpp
        src/nanopolish_index.h
        src/nanopolish_methyltrain.cpp
        src/nanopolish_methyltrain.h
        src/nanopolish_phase_reads.cpp
        src/nanopolish_phase_reads.h
        src/nanopolish_polya_estimator.cpp
        src/nanopolish_polya_estimator.h
        src/nanopolish_raw_loader.cpp
        src/nanopolish_raw_loader.h
        src/nanopolish_read_db.cpp
        src/nanopolish_read_db.h
        src/nanopolish_scorereads.cpp
        src/nanopolish_scorereads.h
        src/nanopolish_squiggle_read.cpp
        src/nanopolish_squiggle_read.h
        src/nanopolish_train_poremodel_from_basecalls.cpp
        src/nanopolish_train_poremodel_from_basecalls.h
        src/nanopolish_variant_db.cpp
        src/nanopolish_variant_db.h
        src/nanopolish_vcf2fasta.cpp
        src/nanopolish_vcf2fasta.h
        src/training_core.cpp
        src/training_core.hpp
        test/data/LomanLabz_PC_Ecoli_K12_R7.3_2549_1_ch8_file30_strand.fast5
        Dockerfile
        LICENSE
        Makefile
        README.md src/group_model/GroupTask.cpp src/group_model/GroupTask.h src/group_model/GroupsProcessor.cpp src/group_model/GroupsProcessor.h)
