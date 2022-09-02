# include<iostream>
using namespace std;
# define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;

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
	int numVertexNum, numEdgeNum; // 顶点和边的数量
}GraphAdjMultiList;
void CreateGraph(GraphAdjMultiList* G) {
	cout << "请输入顶点的数量和边的数量：" << endl;
	cin >> G->numVertexNum >> G->numEdgeNum;
	for (int i = 0; i < G->numVertexNum; i++) {
		cin >> G->adjMultiList[i].data;
		G->adjMultiList[i].firstedge = NULL;
	}
	int i, j;
	EdgeNode *e;
	for (int k = 0; k < G->numEdgeNum; k++) {
		cout << "请输入该边的两个顶点：" << endl;
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