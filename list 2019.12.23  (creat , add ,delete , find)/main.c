#include <stdio.h>
#include "create list.h"
#include "add or delete data.h"


void add_list(datalist a , int i , datalist *add_data);

void delete_list(datalist a , int i);


int main() {
    datalist a;
    head_add(&a , 10);
    datalist b = a;
    for(int i = 0 ; i < 10 ;i++)
    {
        b = b->next_list; //读取第一个表的元素
        printf("%d  " , b->data);

    }

    datalist c = (datalist) malloc (sizeof(struct list));
    c ->data = 100;

    delete_list( a , 3);
    printf("\n");

    b = a;
    for(int i = 0 ; i < 9 ;i++)
    {
        b = b->next_list; //读取第一个表的元素
        printf("%d  " , b->data);

    }


}
