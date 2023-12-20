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

    //链表的长度
    int len;

} LinkList;




//链表初始化
int LinkListInit();

//链表头插法
int LinkListHeadInsert();

//尾插法
int LinkListTailInsert();

//任意位置插入
int LinkListAppointPosInsert();

//






#endif