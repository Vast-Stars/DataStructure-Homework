//循环队列的结构类型定义.h

#ifndef LoopQueue_H
#define LoopQueue_H

const int m=5;
typedef int datatype;
typedef struct
{   datatype sequ[m];
    int  rear, quelen;
}LoopQueue;

//出队.h
datatype *dequeue(qu *sq)
{
}

//入队.h
void enqueue(LoopQueue *sq, datatype x)
{
}

//置空队.h
void setnull(LoopQueue *sq)
{  sq->rear=m-1;
    sq->quelen=0;
}

#endif