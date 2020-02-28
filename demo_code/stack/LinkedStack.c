#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10
#define OK 1
#define ERROR 0
typedef int elementType; // 这里暂定int为栈中的基本元素，当然可以扩展为更加复杂的struct对象

//$$$$$$$$$$$$$$$$$$链式存储的栈例子$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct
{
    elementType data;       // 节点数值
    struct StackNode *next; // 表示下一个节点的位置
} StackNode;

typedef struct
{
    struct StackNode *top; //表示栈顶元素指针
    int count;             // 表示元素个数
} LinkedStack;

int push(LinkedStack *stack, elementType value)
{
    if (stack == NULL)
    {
        return ERROR;
    }
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = value;
    //前一个top变为现在的next
    if (stack->top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = stack->top;
    }
    //头节点指针更新，
    stack->top = newNode;
    stack->count++;
    return OK;
}

// 注意删除节点的时候，top指针的更新
int pop(LinkedStack *stack, elementType *poppedValue)
{
    if (stack == NULL)
    {
        return ERROR;
    }
    if (stack->count == 0) //说明栈已经空了
    {
        return ERROR;
    }
    StackNode *currentTopnode = stack->top;
    if (currentTopnode == NULL)
    {
        return ERROR;
    }
    *poppedValue = currentTopnode->data;
    stack->top = currentTopnode->next;
    //节点被弹出(删除)后，要释放内存空间，防止内存溢出
    free(currentTopnode);
    (stack->count)--;
    return OK;
}

void showStack(LinkedStack *stack)
{
    if (stack == NULL || stack->count == 0)
    {
        printf("Stack is empty");
    }
    StackNode *cursor = stack->top;
    while (cursor != NULL)
    {
        printf(" %d ", cursor->data);
        cursor = cursor->next;
        /* code */
    }

    printf("\n");
}

LinkedStack *createStack()
{
    LinkedStack *pStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    pStack->count = 0;
    pStack->top = NULL;
    showStack(pStack);
    return pStack;
}

void pushOperationInStack(LinkedStack *pStack)
{
    push(pStack, 1);
    printf("push element %d\n", 1);
    showStack(pStack);
    push(pStack, 2);
    printf("push element %d \n", 2);
    showStack(pStack);
    push(pStack, 3);
    printf("push element %d \n", 3);
    showStack(pStack);
}

void popOperationInStack(LinkedStack *pStack)
{
    elementType value;
    elementType *pValue = &value;
    printf("pop element\n");
    pop(pStack, pValue);
    showStack(pStack);
    printf("pop element\n");
    pop(pStack, pValue);
    showStack(pStack);
}

// 返回 栈的元素个数
int getStackLength(LinkedStack *pStack)
{
    /*todo*/
    return 0;
}

//判断 栈是否为空
bool isStackEmpty(LinkedStack *pStack)
{
    return true;
}

bool findElementInStack(LinkedStack *pStack, elementType value)
{
    return false;
}

int main(int argc, char const *argv[])
{
    // 创建栈
    LinkedStack *pStack = createStack();

    // 入栈操作
    pushOperationInStack(pStack);

    // 出栈操作
    popOperationInStack(pStack);

    return 0;
}
