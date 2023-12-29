#include "balancBinarySearchTree.h"
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

#define true 1
#define false 0

//static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

static int AVLTreeNodeIsBalancde(AVLTreeNode *node);

//AVL树结点调平衡
static int AVLTreeNodeAdjustBalance(balanceBinarySearchTree *pBstree, AVLTreeNode * node);


static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

//添加节点之后的操作
static int insertNodeAfter(balanceBinarySearchTree *pBstree, AVLTreeNode * node);
//新建结点
static AVLTreeNode* createAVLTreeNewNode(ELEMENTTYPE val,  AVLTreeNode * parent);

//根据指定值获取二叉树结点
static AVLTreeNode * baseAppointValGetAVLTreeNode(balanceBinarySearchTree *pBstree, ELEMENTTYPE val);

//static createAVLTreeNewNode(ELEMENTTYPE val, );

//判断二叉搜索树的度为二
static int balanceBinarySearchTreeNodeHasTwochildrens(AVLTreeNode *node);

//判断二叉搜索树的度为一
static int balanceBinarySearchTreeNodeHasOnechildren(AVLTreeNode *node);

//判断二叉搜索树的度为零
static int balanceBinarySearchTreeNodeIsLeaf(AVLTreeNode *node);

//二叉搜索树的初始化
int balanceBinarySearchTreeInit(balanceBinarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
{
    int ret = 0;
    balanceBinarySearchTree *bstree = (balanceBinarySearchTree *)malloc(sizeof(balanceBinarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree, 0, sizeof(balanceBinarySearchTree) * 1);
    {
        bstree->root = NULL;
        bstree->size = 0;

        //钩子函数在这边赋值
        bstree->compareFunc = compareFunc;
        //钩子函数包装器 自定义打印
        bstree->printFunc = printFunc;
    }

    #if 0
    bstree->root = (AVLTreeNode *)malloc(sizeof(AVLTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }

    memset(bstree->root, 0, sizeof(AVLTreeNode) * 1);
      /* 初始化根节点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->parent = NULL;
        bstree->root->right = NULL;
    }

    *pBstree = bstree;
    
    #else

    bstree->root = createAVLTreeNewNode(0, NULL);
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
//计算结点的平衡因子
static int AVLTreeNodeBalanceFactor(AVLTreeNode *node)

//前序
static int preOrderTrave(balanceBinarySearchTree *pBstree, AVLTreeNode *node);

//中序
static int inOrderTrave(balanceBinarySearchTree *pBstree, AVLTreeNode *node);

//后序
static int postOrderTrave(balanceBinarySearchTree *pBstree, AVLTreeNode *node);

//获取当前结点的前驱结点
static AVLTreeNode *bstreeNodepreDecessor(AVLTreeNode *node);

//获取当前结点的后续结点
static AVLTreeNode *bstreeNodeSuccessor(AVLTreeNode *node);

//删除指定结点
static int balanceBinarySearchTreeDeleteNode(balanceBinarySearchTree *pBstree, AVLTreeNode *node);


//新建结点
static AVLTreeNode* createAVLTreeNewNode(ELEMENTTYPE val,  AVLTreeNode * parent)
{
    AVLTreeNode * newAVLNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode) * 1);

    if (newAVLNode == NULL)
    {
        return NULL;
    }

     memset(newAVLNode, 0, sizeof(AVLTreeNode) * 1);
    {
        newAVLNode->data = 0;
        newAVLNode->left = NULL;
        newAVLNode->parent = NULL;
        newAVLNode->right = NULL;
    }
    
    //新结点赋值
    newAVLNode->data = val;

    newAVLNode->parent = parent;

    return newAVLNode;

    // return 0;

}

//判断二叉搜索树的度为二
static int balanceBinarySearchTreeNodeHasTwochildrens(AVLTreeNode *node)
{
    return (node->left != NULL && node->right != NULL);
}

//判断二叉搜索树的度为一
static int balanceBinarySearchTreeNodeHasOnechildren(AVLTreeNode *node)
{
    return (node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL);
}

//判断二叉搜索树的度为零
static int balanceBinarySearchTreeNodeIsLeaf(AVLTreeNode *node)
{
    return (node->left != NULL && node->right != NULL);
}

//获取当前结点的前驱结点
//中序遍历到的结点的前一个结点
static AVLTreeNode *bstreeNodepreDecessor(AVLTreeNode *node)
{
    //前驱结点是在左子树的右子树的右子树。。。
    if (node->left != NULL)
    {
        AVLTreeNode *travelNode = node->left;
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
static AVLTreeNode *bstreeNodeSuccessor(AVLTreeNode *node)
{
    AVLTreeNode *travelNode = NULL;
    if (node->right != NULL)
    {
        //后继结点是右子树的左子树的左子树的左子树。。。
        AVLTreeNode *travelNode = node->right;
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

//判断大小
static int tmpMax(int val1, int val2)
{
    return val1 - val2 >= 0 ? val1 : val2;
}

//更新结点高度
static int AVLTreeNodeUpdateHeight(AVLTreeNode *node)
{
    int ret = 0;
    
    int leftHeight = node->left == NULL ? 0 : node->left->height;
    int rightHeight = node->right == NULL ? 0 : node->right->height;

    return 1 + tmpMax(leftHeight, rightHeight);

    // while (AVLTreeNodeIsBalancde(node) && node != NULL)
    // {
    //     node->parent->height++;
    //     node = node->parent;

    // }
    
    return ret;
}

//AVL树结点调平衡
static int AVLTreeNodeAdjustBalance(balanceBinarySearchTree *pBstree, AVLTreeNode * node)
{

}
//添加节点之后的操作
//新添加的结点一定是叶子结点
static int insertNodeAfter(balanceBinarySearchTree *pBstree, AVLTreeNode * node)
{
    int ret = 0;
    //todo....
    while ((node = node->parent) != NULL)
    {
        //程序执行到这里有不止一个结点
        if (AVLTreeNodeIsBalancde(node))
        {
            //如果界定啊是平衡的，那就更新高度
            AVLTreeNodeUpdateHeight(node);
        }
        else
        {
            //node 是最低的不平衡结点
            //开始旋转
            AVLTreeNodeAdjustBalance(pBstree, node);

            //调整完最低的不平衡结点，上边的不平衡结点就平衡了
            break;
        }
    }
    
    //更新高度


    //调整平衡
    return ret;
}

//二叉搜索树的插入
int balanceBinarySearchTreeInsert(balanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;
    if (pBstree->size == 0)
    {
        //更新树的结点
        (pBstree->size)++;
        pBstree->root->data = val;
        insertNodeAfter(pBstree->root);
        return ret;
    }

    //travelNode 指向根结点
    AVLTreeNode * travelNode = pBstree->root;
    AVLTreeNode * parentNode = pBstree->root;
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
    AVLTreeNode * newAVLNode = (AVLTreeNode)malloc(sizeof(AVLTreeNode) * 1);
    if (newAVLNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newAVLNode, 0, sizeof(AVLTreeNode) * 1);
    {
        newAVLNode->data = 0;
        newAVLNode->left = NULL;
        newAVLNode->parent = NULL;
        newAVLNode->right = NULL;
    }
    
    //新结点赋值
    newAVLNode->data = val;
    #else

    AVLTreeNode * newAVLNode = createAVLTreeNewNode(val, parentNode);

    //挂在左子树
    if (cmp < 0)
    {
        parentNode->left =  newAVLNode;
    }
    else
    {
        //挂在右子树
        parentNode->right = newAVLNode;
    }
    //添加之后的调整
    insertNodeAfter(newAVLNode);
    //newAVLNode->parent = parentNode;
    (pBstree->size)++;
    return ret;

}
#endif

//根据指定的值获取二叉搜索树的结点
static AVLTreeNode * baseAppointValGetAVLTreeNode(balanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int cmp = 0;
    AVLTreeNode * travelNode = pBstree->root;
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
int balanceBinarySearchTreeIsContainAppointVal(balanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetAVLTreeNode(pBstree, val) == NULL ? 0 : 1;
}

//计算结点的平衡因子
static int AVLTreeNodeBalanceFactor(AVLTreeNode *node)
{
    int leftHeight = node->left == NULL ? 0 : node->left->height;

    int rightHeight = node->right == NULL ? 0 : node->right->height;

    return leftHeight - rightHeight; 
} 

//判断结果是否平衡
static int AVLTreeNodeIsBalancde(AVLTreeNode *node)
{
    #if 0
    return abs(AVLTreeNodeBalanceFactor(node)) <= 1;
    #else 
    int nodefactor = ads(AVLTreeNodeBalanceFactor(node));
    if (nodefactor <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }

    #endif 
}
//前序
static int preOrderTrave(balanceBinarySearchTree *pBstree, AVLTreeNode *node)
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
static int inOrderTrave(balanceBinarySearchTree *pBstree,AVLTreeNode *node)
{
    int ret = 0;

    if (node == NULL)
    {
        return ret;
    }

    inOrderTrave(pBstree, node->left);
    pBstree->printFunc(node->data);

    inOrderTrave(pBstree,node->right);

}

//后序
static int postOrderTrave(balanceBinarySearchTree *pBstree, AVLTreeNode *node)
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
int balanceBinarySearchTreepreOrderTrave(balanceBinarySearchTree *pBstree)
{
    int ret = 0;

    preOrderTrave(pBstree, pBstree->root);

    return ret;
}

//中序
int balanceBinarySearchTreeInOrderTrave(balanceBinarySearchTree *pBstree)
{
    int ret = 0;
    inOrderTrave(pBstree, pBstree->root);
    
    return ret;
}

//后序
int balanceBinarySearchTreePostOrderTrave(balanceBinarySearchTree *pBstree)
{
    int ret = 0;

    postOrderTrave(pBstree, pBstree->root);

    return ret;

}

//层序
int balanceBinarySearchTreeLevelOrderTrave(balanceBinarySearchTree *pBstree)
{
    int ret = 0;

    //初始化队列
    DoubleLinkListQueue *pQueue = NULL;
    DoubleLinkListQueueInit(&pQueue);

    //入队
    DoubleLinkListQueuePush(pQueue, pBstree->root);

    //判断队列是否为空
    AVLTreeNode *nodeVal = NULL;
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
int balanceBinarySearchTreeGetHeight(balanceBinarySearchTree *pBstree,int *pHeight)
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
    
    AVLTreeNode *traveNode = NULL;
    while (!DoubleLinkListQueueIsEmpty(pQueue))
    {
        DoubleLinkListQueueTop(pQueue, (void**)&traveNode);
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

    DoubleLinkListQueueDestroy(pQueue);
    

    return ret;
}

//删除指定结点
static int balanceBinarySearchTreeDeleteNode(balanceBinarySearchTree *pBstree, AVLTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }

    /* 树的结点减一 */
    (pBstree->size)--;

    if (balanceBinarySearchTreeNodeHasTwochildrens(node))
    {
        /* 找到前驱结点 */
        AVLTreeNode * preNode =bstreeNodepreDecessor(node);
        node->data = preNode->data;
        node = preNode;
    }

    /* 程序执行到这里. 要删除的结点要么是度为1 要么是度为0. */

    /* 假设node结点是度为1的。它的child要么是左要么是右. */
    /* 假设node结点是度为0的, */
    AVLTreeNode * child = node->left != NULL ? node->left : node->right;

    AVLTreeNode *delNode = NULL;
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
    if (balanceBinarySearchTreeNodeHasTwochildrens(node))
    {
        AVLTreeNode *preNode = preNode = bstreeNodepreDecessor(node);
        Node->data = preNode->data;
        node = preNode;
    }   
    
    if (balanceBinarySearchTreeNodeHasOnechildren(node))
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
 
    if (balanceBinarySearchTreeNodeIsLeaf(node))
    {
        free(node);
        node = NULL;
    }    
#endif
    
}

//二叉搜索树的删除
int balanceBinarySearchTreeDelete(balanceBinarySearchTree *pBstree, ELEMENTTYPE val)
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

    //AVLTreeNode *delNode = baseAppointValGetAVLTreeNode(pBstree, val);
    //return balanceBinarySearchTreeDeleteNode(pBstree,delNode);
    balanceBinarySearchTreeDeleteNode(pBstree, baseAppointValGetAVLTreeNode(pBstree, val));

    return ret;
}

//二叉搜索树的销毁
int balanceBinarySearchTreeDestroy(balanceBinarySearchTree *pBstree)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }


    int ret = 0;

    DoubleLinkListQueue * pQueue = NULL;
    DoubleLinkListQueueInit(&pQueue);

    DoubleLinkListQueuePush(pQueue, pBstree->root);
    AVLTreeNode *traveNode = NULL;
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

//获取二叉搜索树的结点个数
int balanceBinarySearchTreeGetNodeSize(balanceBinarySearchTree *pBstree, int *pSize)
{
    if (pBstree == NULL)
    {
        return 0;
    }
    
    if (pSize)
    {
        *pSize = pBstree->size;
    }

    return pBstree->size;
    
}