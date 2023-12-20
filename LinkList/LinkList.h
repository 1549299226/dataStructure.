#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE int 

//链表节点取别名
typedef struct LinkNode
{
    ELEMENTTYPE data;
    //指向下一个结点的指针
    struct LinkNode *next; //指针类型

} LinkNode;


typedef struct LinkList
{   
    //链表的虚拟头节点
    LinkNode *head;
    LinkNode *tail; //为什么尾指针不需要分配空间
    //链表的长度
    int len;

} LinkList;




//链表初始化
int LinkListInit(LinkList** pList);

//链表头插法
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val);

//尾插法
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val);

//任意位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val);

//头删
int LinkListDelHead(LinkList *pList);

//尾删
int LinkListDelTail(LinkList *pList);

//指定位置删
int LinkListDelAppointPos(LinkList *pList, int pos);

//删除指定元素
int LinkListDelAppointData(LinkList *pList, ELEMENTTYPE val);

//获取链表长度
int LinkListGetLength(LinkList *pList, int *pSize);

//链表的销毁
int LinkListDestroy(LinkList *pList);

//链表遍历接口
int LinkListForeach(LinkList *pList);
#endif