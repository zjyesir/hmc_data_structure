#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #include<stack>
// #include<queue.h>
// #include<list>

#define OK 1
#define ERROR 0
typedef char elementType; // 这里暂定int为队列中的基本元素，当然可以扩展为更加复杂的struct对象
typedef struct TreeNode
{
    elementType data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
} TreeNode;

TreeNode *createTree()
{
    printf("input the value for this node:");
    elementType value;
    scanf(" %c", &value);
    getchar();
    if (value == '#')
    {
        return NULL;
    }
    else
    {
        TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
        treeNode->data = value;
        treeNode->lChild = createTree();
        treeNode->rChild = createTree();
        return treeNode;
    }
}

// 因为改变的是指针的数值，所以要传入指针的地址；
// 如果你传入的是指针，那改变的只能是指针指向对象的数值，而不是指针本身
// 以先序遍历的顺序输出结点 AB#D##C##
void createTreeAnotherWay(TreeNode **root)
{
    printf("input the value for this node:");
    elementType value;
    scanf(" %c", &value);
    getchar();
    if (value == '#')
    {
        *root = NULL;
    }
    else
    {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        (*root)->data = value;
        //  (*root)->lChild = NULL;
        //  (*root)->rChild = NULL;
        createTreeAnotherWay(&((*root)->lChild));
        createTreeAnotherWay(&((*root)->rChild));
    }
}

int depth(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int leftDepth = depth(root->lChild);
    int rightDepth =depth(root->rChild);
    int max =leftDepth>rightDepth?leftDepth:rightDepth;
    return max+1;
}

// 先序遍历递归写法
void preOrderTraverse(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    preOrderTraverse(root->lChild);
    preOrderTraverse(root->rChild);
}

// 先序遍历递归写法
void preOrderTraverse2(TreeNode *root)
{
    int myDepth = depth(root);
    int spaceNumber = myDepth*2;
    // for (size_t i = 0; i < spaceNumber; i++)
    // {
    //     /* code */
    //     printf(" ");
    // }
    if (root == NULL)
    {
         printf("#");
         return;
    }
    printf("%c ", root->data);
    printf("\n");
    preOrderTraverse2(root->lChild);
    preOrderTraverse2(root->rChild);
}



// 中序遍历
void inOrderTraverse(TreeNode *root)
{
    // 自己写
}

// 后序遍历
void postOrderTraverse(TreeNode *root)
{
    // 自己写
}

// 先序遍历的方式创建树：以父结点，左结点，右结点这样的顺序输入，若子结点空，则以#输入表示
void createTreeExample()
{
    printf("please input values(one by one) to create a tree\n");
    // 第一种方法
    // TreeNode * root =createTree();
    // 第二种方法
    TreeNode *root = NULL;
    createTreeAnotherWay(&root);
    if (root == NULL)
    {
        printf("tree is empty");
    }
    // preOrderTraverse(root);
    preOrderTraverse2(root);
    printf("depth = %d",depth(root));
}


int main(int argc, char const *argv[])
{
    /* code */
    createTreeExample();
    return 0;
}

