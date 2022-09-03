# include<iostream>
using namespace std;
# define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;
# define TRUE 1;
# define FALSE 0;
int visited4[MAXSIZE];

typedef struct EdgeNode {
	int mark; // ����Ƿ񱻱���������������ʹ�ã�
	int ivex;
	struct EdgeNode *ilink; // ������ivex��ָ��
	int jvex;
	struct EdgeNode *jlink; // ������jvex��ָ��
	EdgeType weight; // ��¼Ȩֵ����������ʹ�ã�
}EdgeNode;
typedef struct VertexNode {
	VertexType data; // �������Ϣ
	EdgeNode *firstedge; // ������ı�ָ��
}VertexNode, AdjMultiList[MAXSIZE];
typedef struct {
	AdjMultiList adjMultiList; // VertexNode����
	int numVertex, numEdge; // ����ͱߵ�����
}GraphAdjMultiList;
void CreateGraph(GraphAdjMultiList* G) {
	cout << "�����붥��������ͱߵ�������";
	cin >> G->numVertex >> G->numEdge;
	for (int i = 0; i < G->numVertex; i++) {
		cout << "�����붥����Ϣ��";
		cin >> G->adjMultiList[i].data;
		G->adjMultiList[i].firstedge = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdge; k++) {
		cout << "������ñߵ��������㣺";
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