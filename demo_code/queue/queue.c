
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// 顺序存储实现队列
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



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

// 判断队列是否满了
bool isQueueFull(Queue *queue){
    return  queue!=NULL &&queue->elementCount == MAX_QUEUE_SIZE;
}

// 判断队列是否空
bool isQueueEmpty(Queue *queue){
    return  queue != NULL && queue->elementCount == 0;
}

// 打印队列内容，从对头 ->队列
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
        printf(" \n (queue empty) ");
        return;
    }
    int front = queue->front;
    int rear = queue->rear;
    printf("\n");
    // 若队列满了，rear == front 为了让下面while循环开始,因为while的条件是front !=front。
    bool queueIsFullSoToBeginTheWhile = false;
    if(isQueueFull(queue)){
        queueIsFullSoToBeginTheWhile = true;
    }
    int stopFlag =  (rear+MAX_QUEUE_SIZE)% MAX_QUEUE_SIZE;
    while (front != rear ||queueIsFullSoToBeginTheWhile)
    {
        printf(" %d ", queue->array[front]);
        front = (front + 1) % MAX_QUEUE_SIZE;
        // 此条件只用一次即失效
        if(queueIsFullSoToBeginTheWhile){
            queueIsFullSoToBeginTheWhile = false;
        }
    }
    // printf("\n");
}

// 加入队列(插入)
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
        printf("\n the queue is Full,you can't do enqueue operation");
        return ERROR;
    }
    queue->array[queue->rear] = value;
    queue->elementCount++;
    // 注意顺序，showQueue 里面用到了 queue->rear的数值，所以下面的改变会影响showQueue的结果
    // 当然这存在耦合，先不管
    
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    printf("\n insert value : %d into the queue",value);
    showQueue(queue);
    
    return OK;
}

// 出列(删除)
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
        printf("\n the queue is Empty , so you can't do dequeue operation");
        return ERROR;
    }
    if (valuePointer != NULL)
    {
        *valuePointer = queue->array[queue->front];
    }
    printf("\n value : %d out of the queue",queue->array[queue->front]);
    queue->elementCount --;
    // 同enqueue,注意这个函数的顺序
    
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    showQueue(queue);
    return OK;
}

Queue *createEmptyQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    // 需要的初始化，不然会出现不可控的问题。
    queue->front = 0; //
    queue->rear = 0;   // 即将存“入队列元素数值”的地方
    queue->elementCount = 0;
    return queue;
}

// 先入列，在出列
void testEnqueueFirstAndDequeue(){
    /* code */
    // 创建空的队列
    Queue *queue = createEmptyQueue();

    // 入队列
    for (int i = 1; i <= 15; ++i)
    {
        enqueue(queue, i);
    }
    // 出队列
    for (int i = 0; i < 5; ++i)
    {
        elementType *valueP;
        dequeue(queue,valueP);
        // showQueue(Queue);
    }
    free(queue);
}

// 随机 入/出 队列，测试用例要包含 错误案例
void testEnqueueAndDequeueInCross(){
     /* code */
    // 创建空的队列
    Queue *queue = createEmptyQueue();
    // showQueue(queue);
    elementType *p ;
    int enqueueValue = 1;
    dequeue(queue,p);
     enqueue(queue, enqueueValue++);
     dequeue(queue,p);
     enqueue(queue, enqueueValue++);
     dequeue(queue,p);
     enqueue(queue, enqueueValue++);
     dequeue(queue,p);
     dequeue(queue,p);
     dequeue(queue,p);



    
    free(queue);
}


int main(int argc, char const *argv[])
{
   testEnqueueFirstAndDequeue();
//    testEnqueueAndDequeueInCross();

    return 0;
}
