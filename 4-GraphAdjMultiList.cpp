# include<iostream>
using namespace std;
# define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;

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
	int numVertexNum, numEdgeNum; // ����ͱߵ�����
}GraphAdjMultiList;
void CreateGraph(GraphAdjMultiList* G) {
	cout << "�����붥��������ͱߵ�������" << endl;
	cin >> G->numVertexNum >> G->numEdgeNum;
	for (int i = 0; i < G->numVertexNum; i++) {
		cin >> G->adjMultiList[i].data;
		G->adjMultiList[i].firstedge = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdgeNum; k++) {
		cout << "������ñߵ��������㣺" << endl;
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
int main() {
	return 0;
}