#include "doubleLinkListQueue.h"
#include <stdio.h>

#define BUFFER_SIZE 5

int main()
{
    DoubleLinkListQueue *queue = NULL;
    DoubleLinkListQueueInit(&queue);

    int buffer[BUFSIZ_SIZE] = {111,222,333,444,555};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        DoubleLinkListQueuePush(queue, (void*)&buffer[idx]);
    }
    
    int size = 0;
    DoubleLinkListQueueGetSize(queue,&size);
    printf("size:%d\n",size);

    int *val = NULL;

    while (!DoubleLinkListQueueIsEmpty(queue))
    {
        DoubleLinkListQueueTop(queue,(void **)&val);
        printf("val:%d\n",val);
        DoubleLinkListQueuePop(queue)
    }
    
    DoubleLinkListQueueDestroy(queue);

    return 0;
}