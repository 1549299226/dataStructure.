#include "dynamicArrayStack.h"
#include "dynamicArray.h"

#define DEFAULT_SIZE 10

/* 栈的初始化  */
int dynamicArrayStackInit(dynamicArrayStack *pStack)
{
    return dynamicArrayInit(pStack, DEFAULT_SIZE);

}
//压栈
int dynamicArrayStackPush(dynamicArrayStack *pStack, ELEMENTTYPE val)
{
    //调用动态数组的尾插
    return dynamicArrayInsertData(pStack, val);
}
//查看栈顶元素
int dynamicArrayStackTop(dynamicArrayStack *pStack, ELEMENTTYPE val)
{
    return dynamicArrayGetAppointPosval(pStack, pStack->len-1,val);
}
//出栈
int dynamicArrayStackPop(dynamicArrayStack *pStack)
{
    return dynamicArrayDeleteData(pStack);
}
//栈是否为空
int dynamicArrayStackIsEmpty(dynamicArrayStack *pStack)
{
    int size = 0;
    dynamicArrayGetSize(pStack, &size);
    return size == 0 ? 1 : 0;
}
//获得栈的大小
int dynamicArrayStackGetSize(dynamicArrayStack *pStack,int *pSize)
{   
    #if 1
    return dynamicArrayGetSize(pStack, pSize);
    #else
    dynamicArrayGetSize(pStack, pSize);
    if (pSize)
    {
        return *pSize;
    }
    #endif
}   
//栈的销毁
int dynamicArrayStackDestroy(dynamicArrayStack *pStack)
{
    return dynamicArrayDestroy(pStack);
}

