//
// Created by 胡康 on 2019/10/24.
//

#ifndef NANOPOLISH02_GROUPSPROCESSOR_H
#define NANOPOLISH02_GROUPSPROCESSOR_H

#include "GroupTask.h"
#include <queue>

class GroupsProcessor {
public:
    std::vector<GroupTask> runningQueue;
    std::queue<GroupTask> totalQueue;
    std::vector<GroupTask> finishedQueue;

public:
    GroupsProcessor();
    ~GroupsProcessor();
};


#endif //NANOPOLISH02_GROUPSPROCESSOR_H
