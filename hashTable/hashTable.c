#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

#define BUFFER_SIZE 100

//哈希初始化
int hashTableInit(hashTable * hash)
{
    hash = (ELEMENTTYPE*)malloc(sizeof(ELEMENTTYPE) * BUFFER_SIZE);
    memset(hash, 0, sizeof(ELEMENTTYPE) * BUFFER_SIZE);
    hash->data = NULL;
    hash->hashKey = hashKey;
#if 0
    hash->List->root = NULL;
    hash->List->size = 0;
    hash->List->height = 0;
    hash->List->compareFunc = compareFunc;
    hash->List->printFunc = printFunc;
    hash->node->data = 0;
    hash->node->height = 0;
    hash->node = NULL;
    hash->node->left = NULL;
    hash->node->right = NULL;
    hash->node->parent = NULL;
#endif    
    balanceBinarySearchTreeInit(&hash->List, compareFunc, prontfunc);
    
}

//哈希插入
int hashTableInsert(hashTable * hash, ELEMENTTYPE val)
{

}

//哈希查找
int hashTableSelect(hashTable * hash, ELEMENTTYPE val)
{

}

//哈希删除
int hashTableDel(hashtable * hash, ELEMENTTYPE val)
{

}

//哈希修改
int hashTableAlter(hashTable * hash, ELEMENTTYPE val)
{

}

//遍历
int hashTableTraversal(hashTable hash)
{

}

//哈希销毁
int hashTableDestroy(hashTable * hash)
{

}