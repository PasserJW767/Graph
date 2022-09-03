# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXSIZE 50

typedef struct EdgeNode {
	int begin;
	int end;
	EdgeType weight;
}EdgeNode,EdgeArr[MAXSIZE];
typedef struct VertexNode {
	VertexType vertex;
}VertexNode, VertexArr[MAXSIZE];
typedef struct {
	VertexArr vertexArr;
	EdgeArr edgeArr;
	int numVertex, numEdge;
}EdgeArray;
void createGraph(EdgeArray* G) {
	cout << "输入顶点数量和边数量: ";
	cin >> G->numVertex >> G->numEdge;
	for (int i = 0;i < G->numVertex;i++)
		cin >> G->vertexArr[i].vertex;
	int i, j, w;
	for (int k = 0;k < G->numEdge;k++) {
		cout << "输入起始位置、终点位置及权重: ";
		cin >> i >> j >> w;
		G->edgeArr[k].begin = i;
		G->edgeArr[k].end = j;
		G->edgeArr[k].weight = w;
	}
}