#ifndef __HASHTABLE_H_
#define __HASHTABLE_H_

#include "balanceBinarySearchTree .h"

#define REMAINDER_KEY 100
//typedef  void* ELEMENTTYPE
int hashKey(ELEMENTTYPE *age)
{
    return *age % REMAINDER_KEY;
}

typedef struct hashTable
{
    int (*hashKey)(ELEMENTTYPE *age); //哈希函数
    ELEMENTTYPE *data;     //哈希数组
    BalanceBinarySearchTree * List;
    AVLTreeNode * node;

}hashTable;

//哈希初始化
int hashTableInit(hashTable * hash);

//哈希插入
int hashTableInsert(hashTable * hash, ELEMENTTYPE val);

//哈希查找
int hashTableSelect(hashTable * hash, ELEMENTTYPE val);

//哈希删除
int hashTableDel(hashtable * hash, ELEMENTTYPE val);

//哈希修改
int hashTableAlter(hashTable * hash, ELEMENTTYPE val);

//遍历
int hashTableTraversal(hashTable hash);

//哈希销毁
int hashTableDestroy(hashTable * hash);

#endif 