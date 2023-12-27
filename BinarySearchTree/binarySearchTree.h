
#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include "doubleLinkListQueue.h"


typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left; //左子树
    struct BSTreeNode *right; //右子树

    #if 1
    struct BSTreeNode *parent; //父结点
    #endif

}BSTreeNode;

typedef struct binarySearchTree
{
    //根结点
    BSTreeNode * root;
    //树的结点个数
    int size;

    //钩子函数比较器
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);

    //钩子函数 包装器 实现自定义打印接口
    int (*printFunc)(ELEMENTTYPE val);
    
    //DoubleLinkListQueueInit *pQueue;

}binarySearchTree;

//二叉搜索树的初始化
int binarySearchTreeInit(binarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val));

//二叉搜索树的插入
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val);

//二叉搜索树是否包含指定元素
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree, ELEMENTTYPE val);


//二叉搜索树的前序遍历
int binarySearchTreepreOrderTrave(binarySearchTree *pBstree);

//中序
int binarySearchTreeInOrderTrave(binarySearchTree *pBstree);


//后序
int binarySearchTreePostOrderTrave(binarySearchTree *pBstree);

//层序
int binarySearchTreeLevelOrderTrave(binarySearchTree *pBstree);

//获取二叉搜索树的高度
int binarySearchTreeGetHeight(binarySearchTree *pBstree,int *pHeight);

//二叉搜索树的删除
int binarySearchTreeDelete(binarySearchTree *pBstree, ELEMENTTYPE val);


//层序
int binarySearchTreeLevelOrderTrave(binarySearchTree *pBstree);

//二叉搜索树的销毁
int binarySearchTreeDestroy(binarySearchTree *pBstree);

#endif //__BINARY_SEARCH_TREE_H_