#include <stdio.h>
#include "balancBinarySearchTree.h"

#define BUFFR_SIZE 10

//测试二叉搜索树
int compareBasicDataFunc(void * arg1, void * arg2)
{
    int val1 = *(int *)arg1;
    int val2 = *(int *)arg2;

    return val1 - val2;
}

int printBasicData(void *arg)
{
    int ret = 0;
    int val = *(int *)arg;
    printf("val:%d\t",val);
    return ret;
}

int main()
{
    balanceBinarySearchTree * AVL = NULL;
    balanceBinarySearchTreeInit(&AVL, compareBasicDataFunc, printBasicData);

    int buffer[BUFFR_SIZE] = {56,28,75,73,77,13,7,26,100,12};
    
    for (int idx = 0; idx < BUFFR_SIZE; idx++)
    {
        balanceBinarySearchTreeInsert(AVL, (void *)&buffer[idx]);

    }

    //获取二叉搜索树的结点个数
    int size = 0;
    balanceBinarySearchTreeGetNodeSize(AVL, &size);
    printf("size:%d\n",size);

    //获取二叉搜索树的高度
    int height = 0;
    balanceBinarySearchTreeGetHeight(AVL, &height);
    printf("height:%d\n",height);
    
    // //中序遍历
    // balanceBinarySearchTreeInOrderTrave(AVL);
    // printf("\n");
    //层序遍历
    balanceBinarySearchTreeLevelOrderTrave(AVL);
    printf("\n");

    /* 删除 */
    int delVal = 56;
    balanceBinarySearchTreeDelete(AVL, &delVal);
    printf("\n");

    /* 层序遍历 */
    balanceBinarySearchTreeLevelOrderTrave(AVL);
    printf("\n");

    /* 获取二叉搜索树的节点个数 */
    size = 0;
    balanceBinarySearchTreeGetNodeSize(AVL, &size);
    printf("size = %d\n", size);

    /* 获取二叉搜索树的高度 */
    height = 0;
    balanceBinarySearchTreeGetHeight(AVL, &height);
    printf("height = %d\n", height);

    return 0;
}