#include <stdio.h>
#include "LinkList.h"
#include <stdlib.h>
#include <string.h>


enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};
//链表初始化
int LinkListInit(LinkList** pList)
{
    int ret = 0;
    LinkList *list = (LinkList*)malloc(sizeof(LinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    //清空脏数据
    memset(list, 0, sizeof(LinkList) * 1);

    list0->head = (LinkList *)malloc(sizeof(LinkList) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    //清空脏数据
    memset(list->head, 0, sizeof(LinkList) * 1);
    list->head->data = 0;
    list->head->next = NULL;
    //链表的长度为零
    list->len = 0;

    //二级指针
    *pList = list;

    return ret;
}

//链表头插法
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val)
{

}

//尾插法
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val)
{

}

//任意位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val)
{

}

//头删
int LinkListDelHead(LinkList *pList)
{

}

//尾删
int LinkListDelTail(LinkList *pList)
{

}

//指定位置删
int LinkListDelAppointPos(LinkList *pList, int pos)
{

}

//删除指定元素
int LinkListDelAppointData(LinkList *pList, ELEMENTTYPE val)
{

}

//获取链表长度
int LinkListGetLength(LinkList *pList, int *pSize)
{

}

//链表的销毁
int LinkListDestroy(LinkList *pList)
{

}

//链表遍历接口
int LinkListForeach(LinkList *pList)
{

}