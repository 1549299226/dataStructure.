#include <stdio.h>
#include "dynamicArray.h"
#include <string.h>

/*
    静态数组 
        1、不够灵活
        2、可能会有浪费的现象
*/
#define BUFFER_SIZE 20
#define DEFAULT_NUM 3

typedef static stuInfo
{
    int age;
    char sex;
}stuInfo;

int main()
{
    dynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array, BUFFER_SIZE);
#if 0
    {
        /* 插入数据 */
        dynamicArrayInsertData(&array, 3);
        for(int idx = 1; idx <= DEFAULT_SIZE; idx++)
         {
             dynamicArrayInsertData(&array, 21);
         }
    }
 
    {
        /* 获取动态数组的大小 */
     int size = 0;
     dynamicArrayGetSize(&array, &size);
         printf("size = %d\n", size);
     }

    {
        int size = 0;
        int val = 0;
        for(int idx = 0; idx < size; idx++)
        {
         dynamicArrayGetAppointPosVal(&array, idx, &val);
         printf("val = %d\t", val);
         }
     }

    {
        /* 删除指定位置的元素 */
         int pos = 1;
        dynamicArrayDeleteAppointPosData(&array, pos);
        /* 获取动态数组的大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        printf("size = %d\n", size);

         int val = 0;
        for(int idx = 0; idx < size; idx++)
        {
             dynamicArrayGetAppointPosVal(&array, idx, &val);
            printf("val = %d\t", val);
        }
     }

    stuInfo stu1, stu2, stu3; 
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu1.age = 20;
    stu1.sex = 'f';

    stu1.age = 30;
    stu1.sex = 'm';

    stuInfo buffer[DEFAULT_NUM] = {stu1,stu2,stu3};

    for (int idx = 0; idx < DEFAULT_NUM ; idx++)
    {
        dynamicArrayInsertData(&array,(void *)&buffer[idx]);
    }
 
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n",size);

    stuInfo *info;
    //memset(&info, 0, sizeof(info));
    for (int idx = 0; idx < DEFAULT_NUM ; idx++)
    {
        dynamicArrayGetAppointPosval(&array, idx,(void *)&info);
        printf("info.age:%d\tinfo.sex:%c\n",info->age,info->sex);
    }
#endif    
    
    int buffer[DEFAULT_NUM] = {1,2,3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);

    }
    
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n",size);

    int *val = NULL;
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosval(&array, idx, (void *)&val);
        printf("val:%d\n",*val);
    }

    
    return 0;

}