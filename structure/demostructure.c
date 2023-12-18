#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 16

#define DEFAULT_SIZE 2

// 什么叫结构体
//将不同类型的属性封装成一个类型
//定义结构体
//取别名 typedef
typedef struct stuInfo
{
    int age;
    int height;
    int weight;
    char sex;
    char name[BUFFER_SIZE];
    char *address;
#if 0
    cahr clothes;
    char shoes;
    char phones;
#endif
}stuInfo;

//字节对齐
//结构体会默认进行数据对齐：读取速度快（但浪费空间）
//结构体的【位域】到网络编程的时候再深究
//什么叫变长结构体

//函数：结构体做函数

#if 0
//值传递：不影响实参

int printStruct(stuInfo stu)
{   
    //栈空间很小，不允许超过8M
    stu.age = 100;
    printf("stu.age = %d,stu.height = %d,stu.sex = %c,stu.weight:%d,stu.name:%s\n",stu.age,stu.height,stu.sex,stu.weight,stu.name);

    return 0;
}
#else



int printStructBuffer(stuInfo *stu,int stuSize)
{
    for (int idx = 0; idx < stuSize, idx++)
    {

        printf("stu.age = %d,stu.height = %d,stu.sex = %c,stu.weight:%d,stu.name:%s\n",stu.age,stu.height,stu.sex,stu.weight,stu.name);

    }
    return 0;
}
//传入参数：不要改变值
int printStruct(const stuInfo *stu)
{   
    int ret = 0;
    int len = sizeof(stu);
    printf("len:%d\n",len);
    //栈空间很小，不允许超过8M
    //结构体必须用指针，省内存空间
    // stu.age = 100;
    // printf("stu.age = %d,stu.height = %d,stu.sex = %c,stu.weight:%d,stu.name:%s\n",stu.age,stu.height,stu.sex,stu.weight,stu.name);
    stu-> 100;

    return 0;
}

#endif

int main()
{
#if 1

    //使用结构体
    stuInfo stu;
    
    //typedef struct stuInfo
    //结构体的大小
#if 0
    int len = sizeof(stu);
    printf("len:%d\n",len);
#if 0   
    stu.age = 10;
    stu.height = 50;
    stu.sex = 'm';
    strncpy(stu.name,sizeof(stu.name)-1);
    printf("stu.age = %d,stu.height = %d,stu.sex = %c,stu.weight:%d,stu.name:%s\n",stu.age,stu.height,stu.sex,stu.weight,stu.name);
#endif

    //结构体数组
    //定义
    stuInfo buffer[BUFFER_SIZE];
    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'f';
    buffer[0].height = 130;
    strncpy(buffer[0].name,"zhangsan",sizeof(buffer[0].name)-1);

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[0].name,"wangwu",sizeof(buffer[1].name)-1);

    printf("buffer[0].age = %d,buffer[0].height = %d,buffer[0].sex = %c,buffer[0].weight:%d,buffer[0].name:%s\n",buffer[0].age,buffer[0].height,buffer[0].sex,buffer[0].weight,buffer[0].name);
    printf("buffer[1].age = %d,buffer[1].height = %d,buffer[1].sex = %c,buffer[1].weight:%d,buffer[1].name:%s\n",buffer[1].age,buffer[1].height,buffer[1].sex,buffer[1].weight,buffer[1].name);
#endif 


#endif 


#if 0

    stu.age = 10;
    stu.height = 50;
    stu.sex = 'm';
    stu.height = 130;
    strncpy(stu.name, sizeof(stu.name)-1);
    printf("stu.age = %d,stu.height = %d,stu.sex = %c,stu.weight:%d,stu.name:%s\n",stu.age,stu.height,stu.sex,stu.weight,stu.name);
//回顾指针
    int a = 5;
    int *p = &a;

    stuInfo *info = &stu;
    //结构体指针读数据或者写数据，都是用->
    info->age = 30;
    printf("info->age:%d\n",info->age);

    printf("stu->age:%d\n",stu->age);

    printStruct(stu);

    printf("stu.age:%d",)

#endif
#if 0
    stuInfo buffer[BUFFER_SIZE];
    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'f';
    buffer[0].height = 130;
    strncpy(buffer[0].name,"zhangsan",sizeof(buffer[0].name)-1);

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[0].name,"wangwu",sizeof(buffer[1].name)-1);

    printStructBuffer(buffer,sizeof(buffer)/sizeof(buffer[0]));
#endif
#if 1
     /* 结构体指针 */
    stu.age = 10;
    stu.weight = 30;
    stu.sex = 'm';
    stu.height = 130;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

    /* 结构体里面有指针，必须分配空间 */
    stu.address = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if(stu.address == NULL)
    {
         return -1;
    }
    strcpy(stu.address, "china");


#endif
    return 0;
}