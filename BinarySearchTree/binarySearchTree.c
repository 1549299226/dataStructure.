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
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

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

static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    #if 0
    if( val1 < val2)
    {
        return -1;
    }
    else if (val1 > val2)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
    #else

    return val1 - val2;
    
    #endif
}
//二叉搜索树的插入
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;
    if (pBstree->size == 0)
    {
        //更新树的结点
        (pBstree->size)++;
        pBstree->root->data = val;
        return ret;
    }

    //travelNode 指向根结点
    BSTreeNode * travelNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;
    //确定符号：到底放左边还是右边
    int cmp = 0; 

    while (travelNode != NULL)
    {
        parentNode = travelNode;
        cmp = compareFunc(val, travelNode->data);

        //插入元素<遍历到的结点
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)  //插入元素>遍历到的结点
        {
            travelNode = travelNode->right;
        }
        else        //插入元素=遍历到的结点
        {
            return ret;
        }
    }   
    BSTreeNode * newBstNode = (BSTreeNode)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->parent = NULL;
        newBstNode->right = NULL;
    }
    
    //新结点赋值
    newBstNode->data = val;

    //挂在左子树
    if (cmp < 0)
    {
        parentNode->left =  (val的结点);
    }
    else
    {
        //挂在右子树
        parentNode->right = (val的结点);
    }
        
    newBstNode->parent = parentNode;
    (pBstree->size)++;
    return ret;
}
