#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_

#define ELEMENTTYPE void * 

//链表结点取别名
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    //指向前一个结点的指针
    struct DoubleLinkNode *prev;
    //指向下一个结点的指针
    struct DoubleLinkNode *next; //指针类型

} DoubleLinkNode;


typedef struct DoubleLinkList
{   
    //链表的虚拟头结点
    DoubleLinkNode *head;
    DoubleLinkNode *tail; //为什么尾指针不需要分配空间
    //链表的长度
    int len;

} DoubleLinkList;




//链表初始化
int LinkListInit(DoubleLinkList** pList);

//链表头插法
int LinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val);

//尾插法
int LinkListTailInsert(DoubleLinkList *pList, ELEMENTTYPE val);

//任意位置插入
int LinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTYPE val);

//头删
int LinkListDelHead(DoubleLinkList *pList);

//尾删
int LinkListDelTail(DoubleLinkList *pList);

//指定位置删
int LinkListDelAppointPos(DoubleLinkList *pList, int pos);

//删除指定元素
int LinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

//获取链表长度
int LinkListGetLength(DoubleLinkList *pList, int *pSize);

//链表的销毁
int LinkListDestroy(DoubleLinkList *pList);

//链表遍历接口
int LinkListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

//链表逆序
int DoubleLinkListReverseForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

#endif