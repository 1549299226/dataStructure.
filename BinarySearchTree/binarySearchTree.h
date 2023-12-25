
#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE int

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

}binarySearchTree;

//二叉搜索树的初始化
int binarySearchTreeInit(binarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

//二叉搜索树的插入
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val);

//二叉搜索树是否包含指定元素
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree, ELEMENTTYPE val);


//二叉搜索树的前序遍历
int binarySearchTreepreOrderTrave();

//中序
int binarySearchTreeInOrderTrave();

//后序
int binarySearchTreePostOrderTrave();

//层序
int binarySearchTreeLevelOrderTrave();


#endif //__BINARY_SEARCH_TREE_H_