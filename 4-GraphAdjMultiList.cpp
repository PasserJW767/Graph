# include<iostream>
using namespace std;
# define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;
# define TRUE 1;
# define FALSE 0;
int visited4[MAXSIZE];

typedef struct EdgeNode {
	int mark; // 标记是否被遍历过（根据需求使用）
	int ivex;
	struct EdgeNode *ilink; // 依附于ivex的指针
	int jvex;
	struct EdgeNode *jlink; // 依附于jvex的指针
	EdgeType weight; // 记录权值（根据需求使用）
}EdgeNode;
typedef struct VertexNode {
	VertexType data; // 顶点的信息
	EdgeNode *firstedge; // 顶点里的边指针
}VertexNode, AdjMultiList[MAXSIZE];
typedef struct {
	AdjMultiList adjMultiList; // VertexNode数组
	int numVertex, numEdge; // 顶点和边的数量
}GraphAdjMultiList;
void CreateGraph(GraphAdjMultiList* G) {
	cout << "请输入顶点的数量和边的数量：";
	cin >> G->numVertex >> G->numEdge;
	for (int i = 0; i < G->numVertex; i++) {
		cout << "请输入顶点信息：";
		cin >> G->adjMultiList[i].data;
		G->adjMultiList[i].firstedge = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdge; k++) {
		cout << "请输入该边的两个顶点：";
		cin >> i >> j;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->ivex = i;
		e->jvex = j;
		e->ilink = G->adjMultiList[i].firstedge;
		G->adjMultiList->firstedge = e;
		e->jlink = G->adjMultiList[j].firstedge;
		G->adjMultiList->firstedge = e;
	}
}
void DFS(GraphAdjMultiList G, int i) {
	visited4[i] = TRUE;
	cout << G.adjMultiList[i].data << " ";
	EdgeNode* e = G.adjMultiList[i].firstedge;
	while (e) {
		if (!visited4[e->jvex])
			DFS(G, e->jvex);
		e = e->ilink;
	}
}
void DFSTraverse(GraphAdjMultiList G) {
	for (int i = 0; i < G.numVertex;i++)
		visited4[i] = FALSE;
	for (int i = 0; i < G.numVertex;i++)
		if (!visited4[i])
			DFS(G, i);
}
int main() {
	GraphAdjMultiList G;
	CreateGraph(&G);
	DFSTraverse(G);
}