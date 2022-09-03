# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXSIZE 100
# define TRUE 1
# define FALSE 0
int visited[MAXSIZE]; // ���ʱ�־������

//�ڽӾ���
typedef struct {
	VertexType vexs[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int numVertexes, numEdges;
}MGraph;
// �����ڽӾ���
void CreateMGraph(MGraph* G)
{

	cout << "���붥�����ͱ�����";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) { // ���붥�����Ϣ
		cout << "�����" << i + 1 << "���������Ϣ��";
		cin >> G->vexs[i];
	}
	for (int i = 0; i < G->numVertexes; i++) // ���ڽӾ�������ݽ��г�ʼ��
		for (int j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;
	int i, j, w;
	for (int k = 0; k < G->numEdges; k++) // ����ߵ���Ϣ�������ڽӾ���
	{
		cout << "�����(vi, vj)�ϵ��±�i���±�j���Լ������ߵ�Ȩ��";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = w;// ��Ϊ������ͼ����������ڽӾ����Ǹ��Գƾ���
	}
	// ��ӡ������Ϣ
	cout << "�������Ķ����飺" << endl;
	cout << "[";
	for (i = 0;i < G->numVertexes;i++)
		cout << G->vexs[i] << " ";
	cout << "]" << endl;
	// ��ӡ�ڽӾ���
	cout << "���������ڽӾ���" << endl;
	for (i = 0;i < G->numVertexes; i++) {
		cout << "[";
		for (j = 0; j < G->numVertexes; j++)
			cout << G->arc[i][j] << " ";
		cout << "]" << endl;
	}
		
}
// �ڽӾ����������ȵݹ��㷨
void DFS(MGraph G, int i) {
	visited[i] = TRUE;
	cout << G.vexs[i] << " "; // ��ӡ����
	for (int j = 0; j < G.numVertexes; j++)
		if (G.arc[i][j] == 1 && !visited[j]) // �����ڱ���δ�����ʹ�
			DFS(G, j);
}
// �ڽӾ������ȱ�������
void DFSTraverse(MGraph G) {
	for (int i = 0; i < G.numVertexes; i++) // ��ʼ״̬�����ж��㶼δ�����ʹ�
		visited[i] = FALSE;
	for (int i = 0; i < G.numVertexes; i++) // ��δ���ʹ��Ķ������DFS
		if (!visited[i])
			DFS(G, i);
}
/*int main() {
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);
	return 0;
*/