//
// Created by NaterStrat on 2019/12/23.
//

#ifndef LIST_FIND_NUMBER_ADD_OR_DELETE_DATA_H
#define LIST_FIND_NUMBER_ADD_OR_DELETE_DATA_H

#include "create list.h"

void add_list(datalist a , int i , datalist *add_data) //第三个元素是指针是因为，为了改变其中的成员指针的指向
{
    int l = 1;
    datalist b = a;

    while (b && l<i)  //实际上是要在第i个位置插入，然后第五个位置变成了第六个位置，然后因为编程是从0开始的
        // 但是我们设定成1开始，那么第i个位置相当于第i-1个位置，插入在i后面的位置，相当于真正意义上要插入的第i个位置
    {
        b = b->next_list;
        l++;
    }
    if(!b) //找到的时候，检测找到的位置是否为空
    {
        return ;
    }

    (*add_data)->next_list = b->next_list;
    b->next_list = (*add_data);
}

void delete_list(datalist a , int i) {
    int l = 1;
    datalist b = a;

    while (b->next_list && l < i) //因为从0开始的，但是我们是从1开始的，那么要删除的位置实际上是i+1，然后我们定位到i，然后把i+1删除掉
        //i扮演的角色在数组中实际是i前一个位置，删除要删除的i的位置，并且第一个条件是检测，要删除的值是否为空，b-next，因为是要删指定位置后面的位置
        //所以要检测后面的位置是否为空
        //不用检测b是否为空是因为b是头指针，要删除的是b后面的位置，只要b后面的位置不为空，就可以了
    {
        b = b->next_list;
        l++;
    }

    if (!b) //上面的条件如果是城里的话，那么这个本身应该不会为空，感觉可以舍弃
    {
        return;
    }

    b->next_list = (b->next_list)->next_list;
}
#endif //LIST_FIND_NUMBER_ADD_OR_DELETE_DATA_H
