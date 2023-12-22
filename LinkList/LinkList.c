#include <stdio.h>
#include "LinkList.h"
#include <stdlib.h>
#include <string.h>

//静态函数只在本文件使用
//静态函数前置声明
static int LinkListAccordAppintValGetPos(LinkList *pList, ELEMENTTYPE val, int* pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));


enum STATUS_CODE
{
    NOT_FIND = -1,
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

    list->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);
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

//指定位置插入
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
    LinkNode * NewNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
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
        flag = 1;
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
    int flag = 0;
    //需要修改尾指针
    if (pos == pList->len)
    {
        flag = 1;
    }
    LinkNode * needDelNode = NULL;
    //*pPos = NOT_FIND; 
    while (--pos)
    {
        //向后移动位置
        travelNode = travelNode->next;
    }

    //跳出循环找到的结点

    needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;
    //travelNode->next = travelNode->next->next;

    if (flag)
    {
        //调整尾指针
        pList->tail = travelNode;
    }
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

//根据指定的元素得到在链表中所在的位置
static int LinkListAccordAppintValGetPos(LinkList *pList, ELEMENTTYPE val, int* pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{   
    //静态函数只给本源文件函数使用不需要判断合法性
    int ret;
#if 1
    LinkNode *travelNode = pList->head->next;
    int pos = 1;
#else
    LinkNode *travelNode = pList->head;
    int pos = 0;
#endif
    int cmp = 0;
    while (travelNode != NULL)
    {
        #if 0
        if (travelNode->data == val)
        {
            *pPos = pos;
            return pos;
        }

    #else
    cmp = compareFunc(val, travelNode->data);

    if (cmp == 0)
    {
        *pPos = pos;
        return pos;
    }

    #endif
        travelNode = travelNode->next;
        pos++;
    }
    
    *pPos = NOT_FIND;
    return NOT_FIND;
}

//删除指定元素
int LinkListDelAppointData(LinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    int ret = 0;
    //元素在链表中的位置
    int pos = 0;

    //链表的长度
    int size = 0;
    while (LinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        //LinkListDelAppointPos(pList, LinkListAccordAppintValGetPos(pList, val, &pos));
        LinkListAccordAppintValGetPos(pList, val, &pos);
        LinkListDelAppointPos(pList, pos);
    }
    
    
    return ret;
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
    int ret = 0; 
    //使用头删
    int size = 0;
    while (LinkListGetLength(pList,&size))
    {
        LinkListDelHead(pList);
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
int LinkListForeach(LinkList *pList, int (*printFunc)(ELEMENTTYPE))
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
        #if 0
        printf("travelNode->data:%d\n", travelNode->data);
        #else
        //包装器 钩子 回调函数
        printFunc(travelNode->data);
        #endif
        travelNode = travelNode->next;

    }
    
#endif
   
    return ret;
}