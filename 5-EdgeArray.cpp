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
	cout << "���붥�������ͱ�����: ";
	cin >> G->numVertex >> G->numEdge;
	for (int i = 0;i < G->numVertex;i++)
		cin >> G->vertexArr[i].vertex;
	int i, j, w;
	for (int k = 0;k < G->numEdge;k++) {
		cout << "������ʼλ�á��յ�λ�ü�Ȩ��: ";
		cin >> i >> j >> w;
		G->edgeArr[k].begin = i;
		G->edgeArr[k].end = j;
		G->edgeArr[k].weight = w;
	}
}