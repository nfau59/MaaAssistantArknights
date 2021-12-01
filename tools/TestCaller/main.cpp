﻿#include "AsstCaller.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    void* ptr = AsstCreate();
    auto ret = AsstCatchEmulator(ptr);
    if (!ret) {
        getchar();
        if (ptr) {
            AsstDestory(ptr);
            ptr = nullptr;
        }
        return -1;
    }

    char ch = 0;
    while (ch != 'q') {
        //AsstAppendFight(ptr, 0, 0, 99999);
        //AsstAppendVisit(ptr, true);
        //{
        //    const int required[] = { 3, 4, 5, 6 };
        //    AsstStartRecruitCalc(ptr, required, sizeof(required) / sizeof(int), true);
        //}
        //AsstAppendDebug(ptr);
        //{
        //    const char* order[] = { "Trade", "Mfg", "Dorm" };
        //    AsstAppendInfrast(ptr, 1, order, 3, 0, 0);
        //}
        //AsstAppendProcessTask(ptr, "AwardBegin");
        {
            const int required[] = { 4 };
            const int confirm[] = { 3, 4 };
            AsstAppendRecruit(ptr, 2, required, sizeof(required) / sizeof(int), confirm, sizeof(confirm) / sizeof(int));
        }
        AsstStart(ptr);

        ch = getchar();
    }

    if (ptr) {
        AsstDestory(ptr);
        ptr = nullptr;
    }

    return 0;
}