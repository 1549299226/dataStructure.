#include "doubleLinkListQueue.h"

int DoubleLinkListQueueInit(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListInit(pQueue);
}

//队列入队
int DoubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return DoubleLinkListTailInsert(*pQueue, val);
}

//查看队头元素
int DoubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return DoubleLinkListGetHeadVal(pQueue, pVal);

}

//出队
int DoubleLinkListQueuePop(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListDelHead(pQueue);
}

//查看队尾元素
int DoubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return DoubleLinkListGetTailVal(pQueue,pVal);
}

//队列大小
int DoubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize)
{
    return DoubleLinkListGetLength(pQueue, pSize);
}

//队列是否为空
int DoubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue)
{
    int size = 0;
    DoubleLinkListGetLength(pQueue, &size);
    return szie == 0 ? 1 : 0;
}

//队列销毁
int DoubleLinkListQueueDestroy(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListDestroy(pQueue);
}
