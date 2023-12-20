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

    list->head = (LinkList *)malloc(sizeof(LinkList) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    //清空脏数据
    memset(list->head, 0, sizeof(LinkList) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    //初始化时尾指针 = 头指针
    list->tail = list->head;
    
    //链表的长度为零
    list->len = 0;

    
    //二级指针
    *pList = list;

    return ret;
}

//链表头插法
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

//尾插法
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);

}

//任意位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    
    //封装结点
    LinkNode * NewNode = (LinkList *)malloc(sizeof(LinkList * 1));
    if (NewNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(NewNode, 0, sizeof(LinkList) * 1);
#if 1
    NewNode->data = 0;
    NewNode->next = NULL;
#endif

    //赋值
    NewNode->data = val;
#if 1
    LinkNode * travelNode = pList->head;
#else    
    LinkNode * travelNode = pList->head->next;
#endif   
    int flag = 0;
    //这种情况下需要更改指针
    if (pos == pList->len)
    {
        travelNode = pList->tail;
        flag = 1
    }
    else
    {
          while (pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }
    
    //改变结点方向
    NewNode->next = travelNode->next;
    travelNode->next = NewNode;
    if(flag)
    {
        pList->tail = NewNode;
    }

    //更新链表长度
    (pList->len)++;
    return ret;
}

//头删
int LinkListDelHead(LinkList *pList)
{
    return LinkListDelAppointPos(pList, 1);
}

//尾删
int LinkListDelTail(LinkList *pList)
{
    return LinkListDelAppointPos(pList, pList->len);
}

//指定位置删
int LinkListDelAppointPos(LinkList *pList, int pos)
{   
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
#if 1
    LinkNode * travelNode = pList->head;
#else


#endif
    while (--pos)
    {
        //向后移动位置
        travelNode = travelNode->next;
    }

    //跳出循环找到的结点

    LinkNode * needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;
    //travelNode->next = travelNode->next->next;

    //释放内存
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }
    //链表长度减一
    (pList->len)--;
    return ret;
    
}

//删除指定元素
int LinkListDelAppointData(LinkList *pList, ELEMENTTYPE val)
{

}

//获取链表长度
int LinkListGetLength(LinkList *pList, int *pSize)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pList->len;
    }

    // 返回链表的长度
    return pList->len;
    
}

//链表的销毁
int LinkListDestroy(LinkList *pList)
{
    int ret 
    //使用头删
    int size = 0;
    while (LinkListGetLength(pList,&size))
    {
        LinkListDelHead(pList;)
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
        pList->tail = NULL;

    }
    
    return ret;
}

//链表遍历接口
int LinkListForeach(LinkList *pList)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    //travelNode指向虚拟头结点
    LinkNode * travelNode = pList->head;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    //travelNode指向链表第一个元素
    LinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        printf("travelNode->data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
    
#endif
   
    return ret;
}