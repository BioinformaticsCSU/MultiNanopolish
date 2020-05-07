//
// Created by 胡康 on 2019/10/24.
//

#ifndef NANOPOLISH02_GROUPTASK_H
#define NANOPOLISH02_GROUPTASK_H

#include <vector>
#include <set>
#include "nanopolish_haplotype.h"
#include "nanopolish_variant.h"

enum TaskStatus{ready=0, running=1, finished=2};

class GroupTask {
public:
    size_t m_group_id;
    TaskStatus m_status;
    std::vector<Variant> m_candidate_variants;
    std::vector<Variant> m_called_variants;
    std::set<std::string> m_last_round_variant_keys;
    std::set<std::string> m_this_round_variant_keys;
    Haplotype m_calling_haplotype;
    std::vector<HMMInputData> m_event_sequences;
    int m_compute_round = 0;
    std::string key() const
    {
        std::stringstream out;
        int i=0;
        for(;i<m_candidate_variants.size()-1; i++){
            Variant v = m_candidate_variants[i];
            out << v.key() << "-";
        }
        out << m_candidate_variants[i].key();
        return out.str();
    }

public:
    GroupTask(size_t group_id, TaskStatus status,
            Haplotype calling_haplotype, std::vector<HMMInputData> event_sequences,
            std::vector<Variant> candidate_variants);

    GroupTask(TaskStatus status,
              Haplotype calling_haplotype, std::vector<HMMInputData> event_sequences,
              std::vector<Variant> candidate_variants);

    GroupTask();

    GroupTask(const GroupTask& groupTask);

    ~GroupTask();
};


#endif //NANOPOLISH02_GROUPTASK_H
