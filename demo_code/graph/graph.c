#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//********************************邻接矩阵**********************************
/* 顶点类型应由用户定义 */
typedef char VertexType;             
/* 边上的权值类型应由用户定义 */
typedef int EdgeType;                
/* 最大顶点数，应由用户定义 */
#define MAXVEX 100                   
/* 用65535来代表∞ */
#define INFINITY 65535               
typedef struct
{/* 顶点表 */
    VertexType vexs[MAXVEX];         
    /* 邻接矩阵，可看作边表 */
    EdgeType arc[MAXVEX][MAXVEX];    
    /* 图中当前的顶点数和边数 */
    int numVertexes, numEdges;       
} MGraph;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    /* 输入顶点数和边数 */
    scanf("%d,%d", &G->numVertexes, &G->numEdges);    
    /* 读入顶点信息，建立顶点表 */
    for (i = 0; i < G->numVertexes; i++){
        scanf(&G->vexs[i]);
    }           
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j <G->numVertexes; j++)
        {
            /* 邻接矩阵初始化 */
            G->arc[i][j] = INFINITY;
        }
    }
    /* 读入numEdges条边，建立邻接矩阵 */
    for (k = 0; k < G->numEdges; k++)                 
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w); //输入边vi,vj上的权重w
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; //无向图，矩阵对称
    }

}

//********************************邻接矩阵**********************************



//********************************邻接表************************************

/* 顶点类型应由用户定义 */
typedef char VertexType;          
/* 边上的权值类型应由用户定义 */
typedef int EdgeType;             
/* 边表结点 */
typedef struct EdgeNode           
{
    /* 邻接点域，存储该顶点对应的下标 */
    int adjvex;                   
    /* 用于存储权值，对于非网图可以不需要 */
    EdgeType weight;              
    /* 链域，指向下一个邻接点　 */
    struct EdgeNode *next;        
} EdgeNode;
/* 顶点表结点 */
typedef struct VertexNode         
{
    /* 顶点域，存储顶点信息 */
    VertexType data;              
    /* 边表头指针 */
    EdgeNode *firstedge;          
} VertexNode, AdjList[MAXVEX];
typedef struct
{
    AdjList adjList;
    /* 图中当前顶点数和边数 */
    int numVertexes, numEdges;    
} GraphAdjList;


/* 建立图的邻接表结构 */
void  CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    /* 输入顶点数和边数 */
    scanf("%d,%d", &G->numVertexes, 
          &G->numEdges);    
    /* 读入顶点信息，建立顶点表 */
    for (i = 0; i < G->numVertexes; i++)              
    {
        /* 输入顶点信息 */
        scanf(&G->adjList[i].data);                   
        /* 将边表置为空表 */
        G->adjList[i].firstedge = NULL;               
    }

     /* 建立边表 */
    for (k = 0; k < G->numEdges; k++)                 
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        /* 输入边(vi,vj)上的顶点序号 */
        scanf("%d,%d", &i, &j);                       
        /* 向内存申请空间， */
        /* 生成边表结点 */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));     
        /* 邻接序号为j */
        e->adjvex = j;                                
        /* 将e指针指向当前顶点指向的结点 */
        e->next = G->adjList[i].firstedge;            
        /* 将当前顶点的指针指向e */
        G->adjList[i].firstedge = e;                  
        /* 向内存申请空间， */
        /* 生成边表结点 */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));     
        /* 邻接序号为i */
        e->adjvex = i;       
        e->next = G->adjList[j].firstedge;     //将e指针指向当前顶点指向的结点
        G->adjList[j].firstedge = e; //将当前顶点的指针指向e  
    }
}            

//********************************邻接表************************************




int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
