#include "stdio.h"
#include <stdlib.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
typedef int elementType; // 这里暂定int为队列中的基本元素，当然可以扩展为更加复杂的struct对象
typedef struct LinkedQueueNode
{
    elementType data;
    struct LinkedQueueNode *next;
    /* data */
} LinkedQueueNode;

typedef struct LinkedQueue
{
    struct LinkedQueueNode *front; //队列头指针
    struct LinkedQueueNode *rear;  // 队列尾指针
    int length;
    /* data */
} LinkedQueue;

void showLinkedQueue(LinkedQueue *queue)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist");
        return;
    }
    if (queue->length == 0)
    {
        printf("\n the queue is empty");
        return;
    }
    LinkedQueueNode *cursor = queue->front;
    printf("\n");
    while (cursor != NULL)
    {
        printf(" %d ", cursor->data);
        cursor = cursor->next;
    }
}

// 加入队列
int enqueue(LinkedQueue *linkedQueue, elementType value)
{
    if (linkedQueue == NULL)
    {
        printf("the queue does not exist");
        return ERROR;
    }
    LinkedQueueNode *node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
    node->data = value;
    node->next = NULL;
    LinkedQueueNode *front = linkedQueue->front;
    LinkedQueueNode *rear = linkedQueue->rear;
    // 直接写成 linkedQueue->rear->next 会出错，因为 typedef struct{}name. 但用 typedef struct name{}name 就没有问题了去研究一下
    //  空列表的时候，头和尾都指向同个节点
    if (linkedQueue->length == 0)
    {
        linkedQueue->front = node;
        linkedQueue->rear = node;
    }
    else
    {
        linkedQueue->rear->next = node; // 将新节点作为队尾的下一个节点
        linkedQueue->rear = node;       // 更新队尾指针
    }
    linkedQueue->length++;
    return OK;
}

int dequeue(LinkedQueue *linkedQueue)
{
    if (linkedQueue == NULL)
    {
        printf("the queue does not exist");
        return ERROR;
    }
    if (linkedQueue->front == NULL && linkedQueue->rear == NULL) //列表为空，注意front是指向具体节点，而不是一个另外专门的头节点
    {
        printf(" the queue is empty ");
        return OK;
    }
    LinkedQueueNode *poppedNode = linkedQueue->front;
    printf(" \n node which value is : % d is popped out", poppedNode->data);
    LinkedQueueNode *newFront = poppedNode->next;
    free(poppedNode);
    linkedQueue->front = newFront;
    linkedQueue->length--;
    return OK;
}

LinkedQueue *createEmptyLinkedQueue()
{
    LinkedQueue *linkedQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    // 需要的初始化，不然会出现不可控的问题。
    linkedQueue->front = NULL;
    linkedQueue->rear = NULL;
    linkedQueue->length = 0;
    return linkedQueue;
}

int main(int argc, char const *argv[])
{
    /* code */
    // 创建空的队列
    LinkedQueue *linkedQueue = createEmptyLinkedQueue();
    showLinkedQueue(linkedQueue);

    // 入队列
    for (int i = 1; i <= 10; ++i)
    {
        enqueue(linkedQueue,i );
        showLinkedQueue(linkedQueue);
    }
    // 出队列
    for (int i = 0; i < 5; ++i)
    {
        dequeue(linkedQueue);
        showLinkedQueue(linkedQueue);
    }

    return 0;
}
