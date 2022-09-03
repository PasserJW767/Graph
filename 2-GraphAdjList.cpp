# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXVEX 100

// 邻接表
typedef struct EdgeNode { // 边表结点
	int adjvex; // 邻接点域
	EdgeType weight; // 存储权值，用于网图
	struct EdgeNode* next; // 指向下个结点
}EdgeNode;
typedef struct VertexNode { // 顶点表结点
	VertexType data;
	EdgeNode* firstedge; // 边表头指针
}VertexNode, AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVertexes, numEdges; // 图中当前顶点数和边数
}GraphAdjList;

// 创建邻接表
void createALGraph(GraphAdjList* G) {
	cout << "输入顶点数和边数：";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // 输入顶点信息
		cin >> G->adjList[i].data; // 输入顶点信息
		G->adjList[i].firstedge = NULL; // 将边表置空
	}
	int i, j;
	EdgeNode* e;
	for (int k = 0; k < G->numEdges; k++) {
		cout << "输入边(vi,vj)上的序号：";
		cin >> i >> j;
		e = (EdgeNode*)malloc(sizeof(EdgeNode)); // 向内存申请一个边结点空间
		e->adjvex = j;
		e->next = G->adjList[i].firstedge; // 将边结点指向的位置指向这个i点原本的next
		G->adjList[i].firstedge = e; // 将firstedge指向e
		// 无向图，重复上述步骤，调换i和j
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}