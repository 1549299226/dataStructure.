
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

}binarySearchTree;

//二叉搜索树的初始化
int binarySearchTreeInit(binarySearchTree **pBstree);

//二叉搜索树的插入
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val);




#endif //__BINARY_SEARCH_TREE_H_