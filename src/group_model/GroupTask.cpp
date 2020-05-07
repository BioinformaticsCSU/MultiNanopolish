//
// Created by 胡康 on 2019/10/24.
//

#include "GroupTask.h"

GroupTask::GroupTask(size_t group_id, TaskStatus status,
        Haplotype calling_haplotype, std::vector<HMMInputData> event_sequences,
        std::vector<Variant> candidate_variants)
 {
    m_group_id = group_id;
    m_status = status;
    m_calling_haplotype = calling_haplotype;
    m_event_sequences = event_sequences;
    m_candidate_variants = candidate_variants;
}

GroupTask::GroupTask(TaskStatus status,
                     Haplotype calling_haplotype, std::vector<HMMInputData> event_sequences,
                     std::vector<Variant> candidate_variants)
{
    m_status = status;
    m_calling_haplotype = calling_haplotype;
    m_event_sequences = event_sequences;
    m_candidate_variants = candidate_variants;
}

GroupTask::GroupTask(const GroupTask& groupTask){
    this->m_group_id = groupTask.m_group_id;
    this->m_status = groupTask.m_status;
    this->m_candidate_variants = groupTask.m_candidate_variants;
    this->m_called_variants = groupTask.m_called_variants;
    this->m_last_round_variant_keys = groupTask.m_last_round_variant_keys;
    this->m_this_round_variant_keys = groupTask.m_this_round_variant_keys;
    this->m_calling_haplotype = groupTask.m_calling_haplotype;
    this->m_event_sequences = groupTask.m_event_sequences;
    this->m_compute_round = groupTask.m_compute_round;
}

GroupTask::GroupTask() {}

GroupTask::~GroupTask() {}
