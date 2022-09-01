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
	cout << "�����붥�������������";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // ���ݶ��������ʼ������
		cin >> G->adjList[i].data;
		G->adjList[i].firstin = NULL;
		G->adjList[i].firstout = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdges; k++) { // ���ݱ�����ʼ����
		cout << "��������ߵ��������㣬��������������";
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

int main() {
	return 0;
}