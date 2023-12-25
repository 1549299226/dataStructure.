#ifndef __DOUBLELINKLIST_QUEUE_H_
#define __DOUBLELINKLIST_QUEUE_H_


//队列初始化
int DoubleLinkListQueueInit();

//队列入队
int DoubleLinkListQueuePush();

//查看队头元素
int DoubleLinkListQueueTop();

//出队
int DoubleLinkListQueuePop();

//查看队尾元素
int DoubleLinkListQueueRear();

//队列大小
int DoubleLinkListQueueGetSize();

//队列是否为空
int DoubleLinkListQueueIsEmpty();

//队列销毁
int DoubleLinkListQueueDestroy();
#endif