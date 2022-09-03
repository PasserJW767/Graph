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
	cout << "�����붥�������������";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // ���ݶ��������ʼ������
		cout << "�����붥����Ϣ��";
		cin >> G->adjList[i].data;
		G->adjList[i].firstin = NULL;
		G->adjList[i].firstout = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdges; k++) { // ���ݱ�����ʼ����
		cout << "��������ߵ��������㣬��������������: ";
		cin >> i >> j;// ��������ߵ���������
		e = (EdgeNode*)malloc(sizeof(EdgeNode)); // ����һ��EdgeNode�ռ�
		e->tailvex = i;
		e->headvex = j;
		// ����Ӻó��ȵ���Ϣ
		e->taillink = G->adjList[i].firstout;
		G->adjList[i].firstout = e;
		// ���������ȵ���Ϣ����������Ľ��嵽headvex��������ȥ
		e->headlink = G->adjList[j].firstin;
		G->adjList[j].firstin = e;
	}
}
void DFS(GraphOrthgonalList G, int i) {
	visited3[i] = TRUE; // ��־�ѷ���
	cout << G.adjList[i].data << " "; // ��ӡ����
	EdgeNode* e = G.adjList[i].firstout;
	while (e) {// �����Ƚ���DFS
		if (!visited3[e->tailvex]) // ������ȵ�δ�����ʹ��������
			DFS(G, e->tailvex);
		e = e->headlink;
	}
}
void DFSTraverse(GraphOrthgonalList G) {
	for (int i = 0; i < G.numVertexes; i++) // ����־λ���
		visited3[i] = 0;
	for (int i = 0; i < G.numVertexes; i++) // �����ʣ�����ж����ͨ������Ҫ����ͨ�����ֱ���б���, �������ֻ��һ����ͨ����
		if (!visited3[i])
			DFS(G, i);
}
int main() {
	GraphOrthgonalList G;
	createGraph(&G);
	DFSTraverse(G);
	return 0;
}