# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXSIZE 100
# define TRUE 1
# define FALSE 0
int visited[MAXSIZE]; // 访问标志的数组

//邻接矩阵
typedef struct {
	VertexType vexs[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int numVertexes, numEdges;
}MGraph;
// 创建邻接矩阵
void CreateMGraph(MGraph* G)
{

	cout << "输入顶点数和边数：";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // 输入顶点的信息
		cout << "输入第" << i + 1 << "个顶点的信息：";
		cin >> G->vexs[i];
	}
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
	// 打印顶点信息
	cout << "构建出的顶点组：" << endl;
	cout << "[";
	for (i = 0;i < G->numVertexes;i++)
		cout << G->vexs[i] << " ";
	cout << "]" << endl;
	// 打印邻接矩阵
	cout << "构建出的邻接矩阵：" << endl;
	for (i = 0;i < G->numVertexes; i++) {
		cout << "[";
		for (j = 0; j < G->numVertexes; j++)
			cout << G->arc[i][j] << " ";
		cout << "]" << endl;
	}
		
}
// 邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i) {
	visited[i] = TRUE;
	cout << G.vexs[i] << " "; // 打印顶点
	for (int j = 0; j < G.numVertexes; j++)
		if (G.arc[i][j] == 1 && !visited[j]) // 若是邻边且未被访问过
			DFS(G, j);
}
// 邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G) {
	for (int i = 0; i < G.numVertexes; i++) // 初始状态下所有顶点都未被访问过
		visited[i] = FALSE;
	for (int i = 0; i < G.numVertexes; i++) // 对未访问过的顶点调用DFS
		if (!visited[i])
			DFS(G, i);
}
/*int main() {
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);
	return 0;
*/