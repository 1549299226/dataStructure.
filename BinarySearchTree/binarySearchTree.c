#include "binarySearchTree.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

//二叉搜索树的初始化
int binarySearchTreeInit(binarySearchTree **pBstree)
{
    int ret = 0;
    binarySearchTree *bstree = (binarySearchTree *)malloc(sizeof(binarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree, 0, sizeof(binarySearchTree) * 1);
    {
        bstree->root = NULL;
        bstree->size = 0;
    }

    #if 1
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }

    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
      /* 初始化根节点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->parent = NULL;
        bstree->root->right = NULL;
    }
    *pBstree = bstree;
    
    #endif

    return ret;
}

//二叉搜索树的插入
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;

    
    return ret;
}
