#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_

#include "common.h"



//链表初始化
int DoubleLinkListInit(DoubleLinkList** pList);

//链表头插法
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val);

//尾插法
int DoubleLinkListTailInsert(DoubleLinkList *pList, ELEMENTTYPE val);

//任意位置插入
int DoubleLinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTYPE val);

//头删
int DoubleLinkListDelHead(DoubleLinkList *pList);

//尾删
int DoubleLinkListDelTail(DoubleLinkList *pList);

//指定位置删
int DoubleLinkListDelAppointPos(DoubleLinkList *pList, int pos);

//删除指定元素
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

//获取链表长度
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize);

//链表的销毁
int DoubleLinkListDestroy(DoubleLinkList *pList);

//链表遍历接口
int DoubleLinkListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

//链表逆序
int DoubleLinkListReverseForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

//获取头的值
int DoubleLinkListGetHeadVal(DoubleLinkList *pList, ELEMENTTYPE *pVal);
//获取尾的值

int DoubleLinkListGetTailVal(DoubleLinkList *pList, ELEMENTTYPE *pVal);

//获取指定位置的值
int DoubleLinkListGetAppointPosVal(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal);

#endif