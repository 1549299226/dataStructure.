#include "binarySearchTree.h"
#include "doubleLinkListQueue.h"
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
//static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);


//新建结点
static BSTreeNode* createBSTreeNewNode(ELEMENTTYPE val,  BSTreeNode * parent);

//根据指定值获取二叉树结点
static BSTreeNode * baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTYPE val);

//static createBSTreeNewNode(ELEMENTTYPE val, );

//判断二叉搜索树的度为二
static int binarySearchTreeNodeHasTwochildrens(BSTreeNode *node);

//判断二叉搜索树的度为一
static int binarySearchTreeNodeHasOnechildren(BSTreeNode *node);

//判断二叉搜索树的度为零
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);

//二叉搜索树的初始化
int binarySearchTreeInit(binarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
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

        //钩子函数在这边赋值
        bstree->compareFunc = compareFunc;
        //钩子函数包装器 自定义打印
        bstree->printFunc = printFunc;
    }

    #if 0
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
    
    #else

    bstree->root = createBSTreeNewNode(0, NULL);
    if(bstree->root == NULL)
    {
         return MALLOC_ERROR;
    }
    #endif

    *pBstree = bstree;

    return ret;
}

#if 0
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
#endif
//前序
static int preOrderTrave(binarySearchTree *pBstree, BSTreeNode *node);

//中序
static int inOrderTrave(binarySearchTree *pBstree, BSTreeNode *node);

//后序
static int postOrderTrave(binarySearchTree *pBstree, BSTreeNode *node);

//获取当前结点的前驱结点
static BSTreeNode *bstreeNodepreDecessor(BSTreeNode *node);

//获取当前结点的后续结点
static BSTreeNode *bstreeNodeSuccessor(BSTreeNode *node);

//删除指定结点
static int binarySearchTreeDeleteNode(binarySearchTree *pBstree, BSTreeNode *node);


//新建结点
static BSTreeNode* createBSTreeNewNode(ELEMENTTYPE val,  BSTreeNode * parent)
{
    BSTreeNode * newBstNode = (BSTreeNode*)malloc(sizeof(BSTreeNode) * 1);

    if (newBstNode == NULL)
    {
        return NULL;
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

    newBstNode->parent = parent;

    return newBstNode;

    // return 0;

}

//判断二叉搜索树的度为二
static int binarySearchTreeNodeHasTwochildrens(BSTreeNode *node)
{
    return (node->left != NULL && node->right != NULL);
}

//判断二叉搜索树的度为一
static int binarySearchTreeNodeHasOnechildren(BSTreeNode *node)
{
    return (node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL);
}

//判断二叉搜索树的度为零
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    return (node->left != NULL && node->right != NULL);
}

//获取当前结点的前驱结点
//中序遍历到的结点的前一个结点
static BSTreeNode *bstreeNodePreDecessor(BSTreeNode *node)
{
    //前驱结点是在左子树的右子树的右子树。。。
    if (node->left != NULL)
    {
        BSTreeNode *travelNode = node->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }
    //程序执行到这里一定没有左子树，需要向父结点找
    while (node->parent != NULL && node == node->parent->right)
    {
        node = node->parent;
    }
    //node->parent == NULL
    //node == node->parent->left
    return node->parent;
}

//获取当前结点的后继结点
static BSTreeNode *bstreeNodeSuccessor(BSTreeNode *node)
{
    BSTreeNode *travelNode = NULL;
    if (node->right != NULL)
    {
        //后继结点是右子树的左子树的左子树的左子树。。。
        BSTreeNode *travelNode = node->right;
        while (travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode;
    }
    //程序执行到此，说明没有右子树，要向父节点走
    while (travelNode->parent != NULL && travelNode->parent->left)
    {
        node = node->parent;
    }

    return node->parent;
    
    
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
        cmp = pBstree->compareFunc(val, travelNode->data);

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

    #if 0  
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
    #else

    BSTreeNode * newBstNode = createBSTreeNewNode(val, parentNode);

    //挂在左子树
    if (cmp < 0)
    {
        parentNode->left =  newBstNode;
    }
    else
    {
        //挂在右子树
        parentNode->right = newBstNode;
    }
        
    //newBstNode->parent = parentNode;
    (pBstree->size)++;
    return ret;

}
#endif

//根据指定的值获取二叉搜索树的结点
static BSTreeNode * baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    int cmp = 0;
    BSTreeNode * travelNode = pBstree->root;
    while (travelNode != NULL)
    {   
        cmp = pBstree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return travelNode;
        }

    }
        return NULL;    
}

//二叉搜索树是否包含指定元素
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}


//前序
static int preOrderTrave(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;

    if (node == NULL)
    {
        return ret;
    }

    pBstree->printFunc(node->left);
    preOrderTrave(pBstree, node->left);
    preOrderTrave(pBstree,node->right);
}

//中序
static int inOrderTrave(binarySearchTree *pBstree,BSTreeNode *node)
{
    int ret = 0;

    if (node == NULL)
    {
        return ret;
    }

    inOrderTrave(pBstree, node->left);
    pBstree->printFunc(node->left);

    inOrderTrave(pBstree,node->right);

}

//后序
static int postOrderTrave(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;

    if (node == NULL)
    {
        return ret;
    }

    postOrderTrave(pBstree, node->left);
    postOrderTrave(pBstree,node->right);  
    pBstree->printFunc(node->left);

}

//二叉搜索树的前序遍历
int binarySearchTreepreOrderTrave(binarySearchTree *pBstree)
{
    int ret = 0;

    preOrderTrave(pBstree, pBstree->root);

    return ret;
}

//中序
int binarySearchTreeInOrderTrave(binarySearchTree *pBstree)
{
    int ret = 0;
    inOrderTrave(pBstree, pBstree->root);
    
    return ret;
}

//后序
int binarySearchTreePostOrderTrave(binarySearchTree *pBstree)
{
    int ret = 0;

    postOrderTrave(pBstree, pBstree->root);

    return ret;

}

//层序
int binarySearchTreeLevelOrderTrave(binarySearchTree *pBstree)
{
    int ret = 0;

    //初始化队列
    DoubleLinkListQueue *pQueue = NULL;
    DoubleLinkListQueueInit(&pQueue);

    //入队
    DoubleLinkListQueuePush(pQueue, pBstree->root);

    //判断队列是否为空
    BSTreeNode *nodeVal = NULL;
    while (!DoubleLinkListQueueIsEmpty(pQueue))
    {
        DoubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        #if 0
        printf("data:%d\n",nodeVal->data);
        #else
        pBstree->printFunc(nodeVal->data);
        #endif
        DoubleLinkListQueuePop(pQueue);

        //左子树入队
        if (nodeVal->left != NULL)
        {
            DoubleLinkListQueuePush(pQueue, nodeVal->left);

        }
        //右子树入队
        if (nodeVal->right != NULL)
        {
            DoubleLinkListQueuePush(pQueue, nodeVal->right);
        }
    }
    
    //释放队列
    DoubleLinkListQueueDestroy(pQueue);

    return ret;
}

//二叉搜索树的高度
int binarySearchTreeGetHeight(binarySearchTree *pBstree,int *pHeight)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
    
    if (pBstree->size == 0)
    {
        return 0;
    }
    
    int ret = 0;

    DoubleLinkListQueue * pQueue = NULL;
    DoubleLinkListQueueInit(&pQueue);

    DoubleLinkListQueuePush(pQueue, pBstree->root);
    //树的高度（根节点入队高度为0）
    int height = 0;
    //树每一层的结点数量
    int leveSize = 1;
    
    BSTreeNode *traveNode = NULL;
    while (!DoubleLinkListQueueIsEmpty(pQueue))
    {
        DoubleLinkListQueueTop(pQueue, (void**)&pQueue->head);
        DoubleLinkListQueuePop(pQueue);
        leveSize--;

        //左子树不为空
        if (traveNode->left != NULL)
        {
            DoubleLinkListQueuePush(pQueue, traveNode->left);
        }
        //右子树不为空
        if (traveNode->right != NULL)
        {
            DoubleLinkListQueuePush(pQueue, traveNode->right);
        }
        //树的当前层结点遍历结束
        if (leveSize == 0)
        {
            height++;
            DoubleLinkListQueueGetSize(pQueue, &leveSize);
        }
    }

    *pHeight = height;

    DoubleLinkListDestroy(pQueue);
    

    return ret;
}

//删除指定结点
static int binarySearchTreeDeleteNode(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }

    /* 树的结点减一 */
    (pBstree->size)--;

    if (binarySearchTreeNodeHasTwochildrens(node))
    {
        /* 找到前驱结点 */
        BSTreeNode * preNode = bstreeNodePreDecessor(node);
        node->data = preNode->data;
        node = preNode;
    }

    /* 程序执行到这里. 要删除的结点要么是度为1 要么是度为0. */

    /* 假设node结点是度为1的。它的child要么是左要么是右. */
    /* 假设node结点是度为0的, */
    BSTreeNode * child = node->left != NULL ? node->left : node->right;

    BSTreeNode *delNode = NULL;
    if (child)
    {
        /* 度为1 */
        child->parent = node->parent;
        if (node->parent == NULL)
        {
            /* 度为1 且 它是根结点 */
            pBstree->root = child;

            delNode = node;
            #if 0
            if (node)
            {   
                free(node);
                node = NULL;
            }
            #endif
        }
        else
        {
            /* 度为1 且 它不是根结点 */
            if (node == node->parent->left)
            {
                node->parent->left = child;
            }
            else if (node == node->parent->right)
            {
                node->parent->right = child;
            }

            delNode = node;
            #if 0
            /* 释放结点 */
            if (node)
            {
                free(node);
                node = NULL;
            }
            #endif
        }
    }
    else
    {
        /* 度为0 */
        if (node->parent == NULL)
        {
            /* 度为0 且是根结点 */
            delNode = node;
            #if 0
            if (node)
            {
                free(node);
                node = NULL;
            }
            #endif
        }
        else
        {
            if (node == node->parent->left)
            {
                node->parent->left = NULL;
            }
            else if (node == node->parent->right)
            {
                node->parent->right = NULL;
            }


            delNode = node;
            #if 0
            if (node)
            {
                free(node);
                node = NULL;
            }
            #endif
        }
       
    }

    if (delNode)
    {
        free(delNode);
        delNode = NULL;
    }
    
    return ret;

#if 0
    if (binarySearchTreeNodeHasTwochildrens(node))
    {
        BSTreeNode *preNode = preNode = bstreeNodepreDecessor(node);
        Node->data = preNode->data;
        node = preNode;
    }   
    
    if (binarySearchTreeNodeHasOnechildren(node))
    {
        if (node->left)
        {
            node->left->parent = node->parent;
            node->parent->left = node->left;
        }

        if (node->right)
        {
            node->right->parent = node->parent;
            node->parent->right = node->right;
        }
        if (preNode == NULL)
        {
            free(preNode);
            preNode = NULL;
        }
        
        
    }
 
    if (binarySearchTreeNodeIsLeaf(node))
    {
        free(node);
        node = NULL;
    }    
#endif
    
}

//二叉搜索树的删除
int binarySearchTreeDelete(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
    
    int ret = 0;

    //删除度为二的结点
    //找到前驱/后继
    //复制前驱结点的value到要删除的结点
    //删除前驱结点
    //删除度为零的结点直接删，并将父结点的指针置空

    //BSTreeNode *delNode = baseAppointValGetBSTreeNode(pBstree, val);
    //return binarySearchTreeDeleteNode(pBstree,delNode);
    binarySearchTreeDeleteNode(pBstree, baseAppointValGetBSTreeNode(pBstree, val));

    return ret;
}

//二叉搜索树的销毁
int binarySearchTreeDestroy(binarySearchTree *pBstree)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }


    int ret = 0;

    DoubleLinkListQueue * pQueue = NULL;
    DoubleLinkListQueueInit(&pQueue);

    DoubleLinkListQueuePush(pQueue, pBstree->root);
    BSTreeNode *traveNode = NULL;
    while (DoubleLinkListQueueIsEmpty(pQueue))
    {
        DoubleLinkListQueueTop(pQueue, (void**)&traveNode);
        DoubleLinkListQueuePop(pQueue);
    

        if (traveNode->left != NULL)
        {
            DoubleLinkListQueuePush(pQueue, traveNode->left);
        }
    
        if (traveNode->right != NULL)
        {
            DoubleLinkListQueuePush(pQueue, traveNode->right);
        }
    
        if (traveNode)
        {
            free(traveNode);
            traveNode = NULL;
        }
    }

    DoubleLinkListQueueDestroy(pQueue);
    
    if (pBstree)
    {
        free(pBstree);
        pBstree = NULL;
    }
    
    return ret;

}