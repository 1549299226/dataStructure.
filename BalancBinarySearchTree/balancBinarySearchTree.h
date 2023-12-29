
#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include "common.h"


typedef struct AVLTreeNode
{
    ELEMENTTYPE data;
    //结点维护一个高度属性
    int height ;
    struct AVLTreeNode *left; //左子树
    struct AVLTreeNode *right; //右子树

    #if 1
    struct AVLTreeNode *parent; //父结点
    #endif

}AVLTreeNode;

typedef struct balanceBinarySearchTree
{
    //根结点
    AVLTreeNode * root;
    //树的结点个数
    int size;

    //钩子函数比较器
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);

    //钩子函数 包装器 实现自定义打印接口
    int (*printFunc)(ELEMENTTYPE val);
    
    //DoubleLinkListQueueInit *pQueue;

}balanceBinarySearchTree;

//二叉搜索树的初始化
int balanceBinarySearchTreeInit(balanceBinarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val));

//二叉搜索树的插入
int balanceBinarySearchTreeInsert(balanceBinarySearchTree *pBstree, ELEMENTTYPE val);

//二叉搜索树是否包含指定元素
int balanceBinarySearchTreeIsContainAppointVal(balanceBinarySearchTree *pBstree, ELEMENTTYPE val);

//获取二叉搜索树的结点个数
int balanceBinarySearchTreeGetNodeSize(balanceBinarySearchTree *pBstree, int *pSize);

//二叉搜索树的前序遍历
int balanceBinarySearchTreepreOrderTrave(balanceBinarySearchTree *pBstree);

//中序
int balanceBinarySearchTreeInOrderTrave(balanceBinarySearchTree *pBstree);

//后序
int balanceBinarySearchTreePostOrderTrave(balanceBinarySearchTree *pBstree);

//层序
int balanceBinarySearchTreeLevelOrderTrave(balanceBinarySearchTree *pBstree);

//获取二叉搜索树的高度
int balanceBinarySearchTreeGetHeight(balanceBinarySearchTree *pBstree,int *pHeight);

//二叉搜索树的删除
int balanceBinarySearchTreeDelete(balanceBinarySearchTree *pBstree, ELEMENTTYPE val);


//层序
int balanceBinarySearchTreeLevelOrderTrave(balanceBinarySearchTree *pBstree);

//二叉搜索树的销毁
int balanceBinarySearchTreeDestroy(balanceBinarySearchTree *pBstree);

#endif //__BINARY_SEARCH_TREE_H_