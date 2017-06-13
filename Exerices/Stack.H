#ifndef Stack_H
#define Stack_H
//-------------------顺序栈------------------------------
const int Maxsize = 40;
typedef Datatype char;
//定义顺序栈结构类型
typedef struct
{
    Datatype elements[Maxsize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack *s)
{
    s->top = -1;  //初始化栈顶指针
}

//创建栈空.h
void setnull(SqStack *s)
{
    s = new SqStack;
    InitStack(s);
}

//是否为空栈
bool StackEmpty(SqStack *s)
{
    if (s->top == -1)  //栈空
        return true;
    else  //不空
        return false;
}

//顺序栈入栈.h
bool Push(SqStack *s, Datatype x)
{
    if (s->top == MaxSize - 1)  //栈满，报错
        return false;
    s->data[++s->top] = x;  //指针先加 1，再入栈
    return true;
}

//顺序栈出栈
bool Pop(SqStack *s, ElemType &x)
{
    if (s->top == -1)  // 栈空，报错
        return false;
    x = s->data[s->top--];  //先出栈，指针再减1
    return true;
}

bool GetTop(SqStack *s, ElemType &x)
{
    if (s->top == -1)  //找空，报错
        return false;
    x = s->data[s->top];  //x记录栈顶元素
    return true;
}
//-------------------顺序栈------------------------------
//------------------链栈---------------------------------
typedef struct StackNode
{
    ElemType data;  //数据域
    struct Linknode *next;  //指针域
} StackNode, *LinkStackPtr;  //栈类型定义

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;//计数
} LinkStack;

void InitStack(LinkStack *s)
{
    s->top=NULL;
    s->count==0;
}

bool StackEmpty(LinkStack *s)
{
    if(s->count==0)
        return true;
    else
        return false;
}

bool Push(LinkStack *S,Datatype e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;
    S->top=s;
    S->count++;
    return true;
}

bool Pop(LinkStack *S ,Datatype *e)
{
    LinkStackPtr p;
    if(StackEmpty(S))
        return false;
    *e=S->top->data;
    p=S->top;
    S->top=S->top->next;
    free(top);  //先使top指针移位再释放
    S->count--;
    return true;
}




//------------------链栈---------------------------------
#endif