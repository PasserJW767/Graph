# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXSIZE 100

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
		cin >> G->adjList[i].data;
		G->adjList[i].firstin = NULL;
		G->adjList[i].firstout = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdges; k++) { // 根据边数初始化边
		cout << "输入该条边的两个顶点，先输出度再输入度";
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

int main() {
	return 0;
}