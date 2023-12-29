#ifndef __DOUBLELINKLIST_QUEUE_H_
#define __DOUBLELINKLIST_QUEUE_H_

#include "doubleLinkList.h"

typedef DoubleLinkList DoubleLinkListQueue;
//队列初始化
int DoubleLinkListQueueInit(DoubleLinkListQueue **pQueue);

//队列入队
int DoubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val);

//查看队头元素
int DoubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal);

//出队
int DoubleLinkListQueuePop(DoubleLinkListQueue *pQueue);

//查看队尾元素
int DoubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal);

//队列大小
int DoubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize);

//队列是否为空
int DoubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue);

//队列销毁
int DoubleLinkListQueueDestroy(DoubleLinkListQueue *pQueue);



#endif