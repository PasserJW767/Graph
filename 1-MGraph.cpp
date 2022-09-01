# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXVEX 100
# define INFINITY 65535

//邻接矩阵
typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

// 创建邻接矩阵
void CreateMGraph(MGraph* G)
{
	
	cout << "输入顶点数和边数：";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) // 输入顶点的信息
		cin >> G->vexs[i];
	for (int i = 0; i < G->numVertexes; i++) // 对邻接矩阵的内容进行初始化
		for (int j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;
	int i, j, w;
	for (int k = 0; k < G->numEdges; k++) // 读入边的信息，建立邻接矩阵
	{
		cout << "输入边(vi, vj)上的下标i和下标j，以及该条边的权：";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = w;// 因为是无向图，所以这个邻接矩阵是个对称矩阵
	}
}

int main() {
	return 0;
} 