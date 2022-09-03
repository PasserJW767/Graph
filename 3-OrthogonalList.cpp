# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXSIZE 100
# define TRUE 1
# define FALSE 0 
int visited3[MAXSIZE];

typedef struct EdgeNode {
	int tailvex;
	int headvex;
	struct EdgeNode *headlink;
	struct EdgeNode *taillink;
	EdgeType weight;
}EdgeNode;
typedef struct VertexNode {
	VertexType data;
	EdgeNode *firstin;
	EdgeNode *firstout;
}VertexNode, AdjList[MAXSIZE];
typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;
}GraphOrthgonalList;

void createGraph(GraphOrthgonalList* G) {
	cout << "请输入顶点个数、边数：";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // 根据顶点个数初始化顶点
		cout << "请输入顶点信息：";
		cin >> G->adjList[i].data;
		G->adjList[i].firstin = NULL;
		G->adjList[i].firstout = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdges; k++) { // 根据边数初始化边
		cout << "输入该条边的两个顶点，先输出度再输入度: ";
		cin >> i >> j;// 输入该条边的两个顶点
		e = (EdgeNode*)malloc(sizeof(EdgeNode)); // 申请一个EdgeNode空间
		e->tailvex = i;
		e->headvex = j;
		// 先添加好出度的信息
		e->taillink = G->adjList[i].firstout;
		G->adjList[i].firstout = e;
		// 接着添加入度的信息，即把上面的结点插到headvex的链表里去
		e->headlink = G->adjList[j].firstin;
		G->adjList[j].firstin = e;
	}
}
void DFS(GraphOrthgonalList G, int i) {
	visited3[i] = TRUE; // 标志已访问
	cout << G.adjList[i].data << " "; // 打印数据
	EdgeNode* e = G.adjList[i].firstout;
	while (e) {// 按出度进行DFS
		if (!visited3[e->tailvex]) // 如果出度点未被访问过，则访问
			DFS(G, e->tailvex);
		e = e->headlink;
	}
}
void DFSTraverse(GraphOrthgonalList G) {
	for (int i = 0; i < G.numVertexes; i++) // 将标志位清空
		visited3[i] = 0;
	for (int i = 0; i < G.numVertexes; i++) // 逐点访问，如果有多个连通分量就要对连通分量分别进行遍历, 这里假设只有一个连通分量
		if (!visited3[i])
			DFS(G, i);
}
int main() {
	GraphOrthgonalList G;
	createGraph(&G);
	DFSTraverse(G);
	return 0;
}