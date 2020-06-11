/*
*   广度优先算法BFS
*   author: joseph
*   date: 2020-5-25
*/

/*
input demo:
8 10
1 2
1 6
2 5
6 3
6 7
3 4
3 7
7 8
7 4
4 8
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MaxVertices 50

// 图节点结构体
typedef struct node
{
    int vertex;
    int color; // 0 - white / 1 - gray / 2 - black
    int d; // depth
    struct node* prev; // previous vertex
    struct node* next; // next vertex
}VertexNode;

// 图节点数组
typedef VertexNode AdjList[MaxVertices];

// 图结构体
typedef struct 
{
    AdjList adjList;
    int n, e;
}AdjMatrix;

// BFS队列结构体
typedef struct
{
    int data[MaxVertices]; // 只存储vertex id
    int front;
    int rear;
    int size;
}Queue;

/*
    创建图，用邻接链表的方式存储
    input:
        AdjMatrix* G
    return:
        NULL
*/
void CreateGraph(AdjMatrix* G)
{
    int nv, ne;
    VertexNode* s_v;
    VertexNode* s_u;
    printf("input number of vertex and number of edge:\n");
    scanf("%d%d", &nv, &ne);
    G->n = nv;
    G->e = ne;
    printf("input %d vertex and %d edges.\n", nv, ne);

    // 初始化图结点数组
    for (int j=0; j<nv; j++) {
        G->adjList[j].vertex = 0;
        G->adjList[j].next = NULL;
    }

    // 输入边 - (u, v)
    // 插入结点到图结点数组中，并构建链表来表示边
    printf("input edge:\n");
    while(ne--){
        int v, u;
        scanf("%d%d", &v, &u);

        int i = 0, v_idx = 0, u_idx = 0;
        int v_flag = 0, u_flag = 0;
    
        // 判断图结点数组中是否已经存在输入结点，并记录已存在结点的位置
        for (i; i<nv; i++) {
            if (G->adjList[i].vertex == 0) 
                break;
            if (G->adjList[i].vertex == v) {
                v_flag = 1;
                v_idx = i;
            }
            if (G->adjList[i].vertex == u) {
                u_flag = 1;
                u_idx = i;
            }
        }

        // 如果图结点中不存在输入结点，则添加该结点到数组中
        if(v_flag == 0){
            v_idx = i++;
            G->adjList[v_idx].vertex = v;
        }    
        if(u_flag == 0){
            u_idx = i;
            G->adjList[u_idx].vertex = u;
        } 

        // 用链表的形式存储边
        // u->v & v->u
        s_u = (VertexNode*)malloc(sizeof(VertexNode));
        s_u->vertex = u;
        s_u->next = G->adjList[v_idx].next;
        G->adjList[v_idx].next = s_u;
        s_v = (VertexNode*)malloc(sizeof(VertexNode));
        s_v->vertex = v;
        s_v->next = G->adjList[u_idx].next;
        G->adjList[u_idx].next = s_v;
    }
    
}

/*
    打印图结构（链表存储方式）
    input:
        AdjMatrix* G
    return:
        NULL
*/
void PrintGraph(AdjMatrix* G)
{
    VertexNode* s;
    for (int i = 0; i<G->n; i++) {
        printf("%d->", G->adjList[i].vertex);
        s = G->adjList[i].next;
        while(1){
            if (s->next == NULL) {
                printf("%d->^\n", s->vertex);
                break;
            }
            printf("%d->", s->vertex);
            s = s->next;
        }
    }
}

/*
    创建队列，用来存储BFS过程中的灰色结点
    队列只存储了结点的id信息
    input:
        NULL
    return:
        Queue* q
*/
Queue* CreateQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("内存不足！");
        return NULL;
    }
    q->front = -1;
    q->rear = 0;
    q->size = 0;
    return q;
}

/*
    入队操作
    input:
        Queue* q, int vertex
    return:
        NULL
*/
void EnQueue(Queue* q, int vertex)
{
    if (q->size == MaxVertices) {
        printf("Full queue!");
        return;
    }
    q->front++;
    q->front %= MaxVertices;
    q->size++;
    q->data[q->front] = vertex;
}

/*
    出队操作
    input:
        Queue* q
    return:
        int vertex
*/
int DeQueue(Queue* q)
{
    if (q->size == 0) {
        printf("Empty queue!");
        return 0;
    }
    int u = q->data[q->rear];
    q->rear++;
    q->rear %= MaxVertices;
    q->size--;
    return u;
}

/*
    得到图结点信息
    利用结点id来找对应结点的详细信息
    input:
        AdjMatrix* G, int vertex
    return:
        VertexNode* u
*/
VertexNode* GetVertex(AdjMatrix* G, int u_vertex)
{
    for (int i=0; i<G->n; i++) {
        if (G->adjList[i].vertex == u_vertex) {
            VertexNode* u = &G->adjList[i];
            return u;
        }
    }
}

/*
    更新图结点信息，表示该结点被访问到了
    input:
        AdjMatrix* G, Queue* q, int vertex, VertexNode* u
    return:
        NULL
*/
void UpdateVertex(AdjMatrix* G, Queue* q, int v_vertex, VertexNode* u)
{
    VertexNode* v = GetVertex(G, v_vertex);

    // 如果该结点是白色表明未被访问过，更新该结点信息，并入队
    if (v->color == 0) {
        v->color = 1;
        v->d = u->d + 1;
        v->prev = u;
        EnQueue(q, v->vertex);
    }
}

/*
    广度优先搜索
    input:
        AdjMatrix* G, VertexNode* r
    return:
        NULL
*/
void BFS(AdjMatrix* G, VertexNode* r)
{
    // 初始化所有节点信息（颜色、深度、父节点）
    // 未访问过的节点标白色
    // 访问过但下一节点存在没被访问的标灰色
    // 本节点及所有下一节点都被访问过的标黑色
    printf("root vertex %d\n", r->vertex);
    r->color = 1;
    r->d = 0;
    r->prev = NULL;
    for (int i=1; i<G->n; i++) {
        G->adjList[i].color = 0;
        G->adjList[i].d = INT_MAX;
        G->adjList[i].prev = NULL;
    }

    // 创建一个队列来保存灰色节点
    // 根节点先入队列
    Queue* q = CreateQueue();
    EnQueue(q, r->vertex);

    // 开始遍历访问所有节点
    // 当队列为空时，表明所有结点均被访问过了
    printf("start BFS processing...\n");
    while (q->size != 0)
    {
        // 出队并获取该节点链表
        int u_vertex = DeQueue(q);
        printf("current finding vertex is %d\n", u_vertex);
        VertexNode* u = GetVertex(G, u_vertex);
        VertexNode* v = (VertexNode*)malloc(sizeof(VertexNode));
        v = u->next;

        // 访问与当前结点相邻的结点，并更新结点
        while (1) {
            if (v == NULL)
                break;
            UpdateVertex(G, q, v->vertex, u);
            v = v->next;
        }

        // 当前结点的相邻结点全部被访问过，将该结点标为黑色
        // 这也是广度优先的含义，即首先遍历完相邻距离为K的结点，再去遍历k+1的结点
        u->color = 2;
    }
}

/*
    打印广度优先搜索树
    input:
        AdjMatrix
    return:
        NULL
*/
void PrintBFS(AdjMatrix* G) 
{
    printf("start print BFS...\n");
    for (int i=0; i<G->n; i++) {
        printf("vertex: %d, depth: %d\n", G->adjList[i].vertex, G->adjList[i].d);
    }
}

int main()
{
    // 创建图结构体
    // 添加图节点和边数据
    // 打印图结构（邻接链表的方式）
    AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
    CreateGraph(G);
    PrintGraph(G);
    
    // 定义初始（根）节点，将数组赋给指针（实际上是数组第一位元素）
    // 进行BFS（广度优先搜索）
    VertexNode* r = G->adjList;
    BFS(G, r);
    PrintBFS(G);

    return 0;
}