#define maxsize 100
#include<stdio.h>
#include<stdlib.h>
/*********************与栈相关的全部函数*****************************/
typedef int elementtype;
typedef struct
{
    elementtype *data;
    int top;
}stack;
stack *initstack() //对栈进行初始化的函数
{
    stack *s=(stack*)malloc(sizeof(stack));
    s->data=malloc(sizeof(elementtype)*maxsize);
    s->top=-1;
    return s;
}
int isempty(stack *s) //判断栈是否为空的函数
{
    if(s->top==-1)
    {
        printf("it is empty\n");
        return 1;
    }
    else
    {
        printf("it is not empty\n");
        return 0;
    }
}
int push_stack(stack *s,elementtype *e) //压栈的函数
{
    if(s->top>=maxsize-1)
    {
        printf("it is full\n");
        return 0;
    }
    else
    {
        s->data[s->top]=*e;
        s->top++; 
        return 1;
    }
}
int pop_stack(stack *s,elementtype *e) //出栈的函数实现
{
    if(s->top<=-1)
    {
        printf("it is empty\n");
        return 0;
    }
    else
    {
        *e=s->data[s->top];
        s->top--;
        return 1;
    }
}

/******************和队列相关的函数********************/
typedef struct
{
    elementtype data[maxsize];
    int rear;
    int front;
}queue;
void initqueue(queue *q) //初始化队列的函数
{
    q->front=0;
    q->rear=0;
}
int is_empty(queue *q) //判断队列是否为空的函数实现
{
    if(q->front==q->rear)
    {
        printf("it is empty\n");
        return 1;
    }
    else
    {
        printf("it is not empty\n");
        return 0;
    }
}
elementtype dequeue(queue *q) //出队的函数实现
{
    elementtype e;
    if(q->front==q->rear)
    {
        printf("it is empty");
        return 0;
    }
    else
    {
        e=q->data[q->front];
        q->front++;
    }
     return e;
}
int queue_full(queue *q) //把队列往前走到底
{
    if(q->front>0)
    {
        int step=q->front;
        for(int i=q->front;i<q->rear;i++)
        {
            q->data[i-step]=q->data[i];
        }
        q->front=0;
        q->rear=q->rear-step;
        return 1;

    }
    else
    {
        printf("it is full");
        return 0;
    }
}
 int equeue(queue *q,elementtype e) //入队函数
 {
    if(q->rear>=maxsize)
    {
        if(!queue_full(q))          //判断队尾是否能往后走，不能则往前走；如果往前也不能走，就停止入队操作
        {
            return 0;
        }
    }
     q->data[q->rear]=e;
        q->rear++;
        return 1;
 }
 void get_head(queue *q,elementtype *e) //获取队头元素
 {
    *e=q->data[q->front];
 }
int main()
{
    queue q;
    elementtype e;
    initqueue(&q);
    equeue(&q,1);
    equeue(&q,2);
    equeue(&q,3);
    equeue(&q,4);
    equeue(&q,5);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    get_head(&q,&e);
    printf("%d\n", e);
}
