//
// Created by NaterStrat on 2019/12/23.
//

#ifndef LIST_FIND_NUMBER_CREATE_LIST_H
#define LIST_FIND_NUMBER_CREATE_LIST_H

#include <stdlib.h>

typedef int datatype;

struct list
{
    datatype data;   //save data
    struct list *next_list; //point next list
};
typedef struct list *datalist ;

void tail_add (datalist *head , int n) //首元素传入指针是因为要改变它的指向，让它指向表头
{
    datalist to , temp;
    *head = (datalist) malloc (sizeof(struct list));
    to = *head;
    for(int i = 0 ; i < n ; i++)
    {
        temp = (datalist) malloc (sizeof(struct list));
        temp->data = rand() %100 +1; //生成一个(0到99) +1 的一个随机数
        to->next_list = temp;
        to = temp;
        //29行这一步是因为，先让前一个链表的指针指向这一个指针，那么前一个链表就指向了这个节点，然后让末尾指针(to)指向这个节点
        // ，然后让temp节点指向下一个结点，然后用to来索引to结点的指针指向下一个结点，然后让to变成下一个结点。
        //每次更换to的指向不会影响到to原来指向的结合，只是让to指向了下一个结点。
    }
}

void head_add (datalist *head , int n)
{
    datalist temp;
    *head = (datalist) malloc (sizeof(struct list));
    (*head)->next_list = NULL; //尾结点，指向空
    for( int i = 0 ; i < n ; i++)
    {
        temp = (datalist) malloc (sizeof(struct list));
        temp->data = rand() %100 +1;
        temp->next_list = (*head)->next_list; //循环第一次创建的就是在尾，指向了NULL
        (*head)->next_list = temp; //再把表头指向这个结点
        //每次插入的位置都在之前的结点的前一个位置
    }
}

int find_where( datalist a , int i , datatype *save_data)
{
    int l  = 1;
    datalist b = a->next_list;

    while( b && l<i)
    {
        b = b->next_list;
        l++;
    }
    if(!b)
    {
        return 0;
    }

    *save_data = b->data;
    return 1 ;
}


#endif //LIST_FIND_NUMBER_CREATE_LIST_H
