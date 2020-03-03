#include "stdio.h"
#include <stdlib.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
#define MAX_QUEUE_SIZE 10
typedef int elementType; // 这里暂定int为队列中的基本元素，当然可以扩展为更加复杂的struct对象

typedef struct Queue
{
    int front; //队列头指针
    int rear;  // 队列尾指针
    elementType array[MAX_QUEUE_SIZE];
    // 因为队列满和空都是 queue->front == queue->rear ，所以引入下面这个变量进行区别
    int elementCount;
    /* data */
} Queue;

bool isQueueFull(Queue *queue){
    return  queue!=NULL &&queue->elementCount == MAX_QUEUE_SIZE;
}

bool isQueueEmpty(Queue *queue){
    return  queue != NULL && queue->elementCount == 0;
}

void showQueue(Queue *queue)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist 111 ");
        return;
    }
    // if (queue->front == -1 || queue->front == queue->rear) //循环队列，列表尾(可入列的地方)赶上列表头(可以出列的地方)
    if (isQueueEmpty(queue)) //循环队列，列表尾(可入列的地方)赶上列表头(可以出列的地方)
    {
        printf(" \n the queue is empty ");
        return;
    }
    int front = queue->front;
    int rear = queue->rear;
    printf("\n");
    // 若队列满了，rear == front 为了让下面while循环开始，rear往-1方向移动一位
    if(isQueueFull(queue)){
        rear = (rear-1)% MAX_QUEUE_SIZE;
    }
    while (front != rear )
    {
        printf(" %d ", queue->array[front]);
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

// 加入队列
int enqueue(Queue *queue, elementType value)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist 222");
        return ERROR;
    }
    // 队列已满
    if (isQueueFull(queue))
    {
        printf("\n the queue is Full");
        return ERROR;
    }
    queue->array[queue->rear] = value;
    queue->elementCount++;
    // 注意顺序，showQueue 里面用到了 queue->rear的数值，所以下面的改变会影响showQueue的结果
    // 当然这存在耦合，先不管
    
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    
    showQueue(queue);
    
    return OK;
}

int dequeue(Queue *queue, elementType *valuePointer)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist 444");
        return ERROR;
    }
    //  if (queue->front == -1 || queue->front == queue->rear) //循环队列，列表尾(可入列的地方)赶上列表头(可以出列的地方)
    if (isQueueEmpty(queue)) //循环队列，列表尾(可入列的地方)赶上列表头(可以出列的地方)
    {
        printf("\n the queue is Empty ");
        return ERROR;
    }
    if (valuePointer != NULL)
    {
        *valuePointer = queue->array[queue->front];
    }
    printf("\n value : %d out of the queue",queue->array[queue->front]);
    queue->elementCount --;
    // 同enqueue,注意这个函数的顺序
    showQueue(queue);
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return OK;
}

Queue *createEmptyQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    // 需要的初始化，不然会出现不可控的问题。
    queue->front = 0; //
    queue->rear = 0;   // 即将存“入队列元素数值”的地方
    queue->elementCount = 0;
    // Queue->length = 0;
    return queue;
}



int main(int argc, char const *argv[])
{
    /* code */
    // 创建空的队列
    Queue *queue = createEmptyQueue();
    // showQueue(queue);

    // 入队列
    for (int i = 1; i <= 10; ++i)
    {
        printf("insert %d : \n",i);
        enqueue(queue, i);
        // printf("\n after insert %d rear = %d",i,queue->rear);
        // showQueue(queue);
    }
    // 出队列
    // for (int i = 0; i < 5; ++i)
    // {
    //     elementType *valueP;
    //     dequeue(Queue,valueP);
    //     showQueue(Queue);
    // }

    return 0;
}
