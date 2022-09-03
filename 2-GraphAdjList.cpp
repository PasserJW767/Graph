# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXVEX 100
# define TRUE 1
# define FALSE 0
int visited2[MAXVEX];

// �ڽӱ�
typedef struct EdgeNode { // �߱���
	int adjvex; // �ڽӵ���
	EdgeType weight; // �洢Ȩֵ��������ͼ
	struct EdgeNode* next; // ָ���¸����
}EdgeNode;
typedef struct VertexNode { // �������
	VertexType data;
	EdgeNode* firstedge; // �߱�ͷָ��
}VertexNode, AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVertexes, numEdges; // ͼ�е�ǰ�������ͱ���
}GraphAdjList;
// �����ڽӱ�
void createALGraph(GraphAdjList* G) {
	cout << "���붥�����ͱ�����";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // ���붥����Ϣ
		cout << "���붥����Ϣ��";
		cin >> G->adjList[i].data; // ���붥����Ϣ
		G->adjList[i].firstedge = NULL; // ���߱��ÿ�
	}
	int i, j;
	EdgeNode* e;
	for (int k = 0; k < G->numEdges; k++) {
		cout << "�����(vi,vj)�ϵ���ţ�";
		cin >> i >> j;
		e = (EdgeNode*)malloc(sizeof(EdgeNode)); // ���ڴ�����һ���߽��ռ�
		e->adjvex = j;
		e->next = G->adjList[i].firstedge; // ���߽��ָ���λ��ָ�����i��ԭ����next
		G->adjList[i].firstedge = e; // ��firstedgeָ��e
		// ����ͼ���ظ��������裬����i��j
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}
void DFS(GraphAdjList G, int i) {
	visited2[i] = TRUE; // ��ʾ�ö����Ѿ������ʹ���
	cout << G.adjList[i].data << " "; // ��ӡ������Ϣ
	// �Ըõ��ڽӵ����ν��б���
	EdgeNode *e = G.adjList[i].firstedge;
	while (e != NULL){
		if (!visited2[e->adjvex])
			DFS(G, e->adjvex);
		e = e->next;
	}
}
void DFSTraverse(GraphAdjList G) {
	for (int i = 0; i < G.numVertexes; i++)
		visited2[i] = FALSE; // ��ͼ�ж����ʼ�����������������ΪFalse
	for (int i = 0; i < G.numVertexes; i++)
		if (!visited2[i])
			DFS(G, i); // ��ÿ������ִ��DFS
}
/*
int main() {
	GraphAdjList G;
	createALGraph(&G);
	DFSTraverse(G);
	return 0;
}*/
