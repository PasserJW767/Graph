# include<iostream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
# define MAXVEX 100
# define INFINITY 65535

//�ڽӾ���
typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

// �����ڽӾ���
void CreateMGraph(MGraph* G)
{
	
	cout << "���붥�����ͱ�����";
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++) // ���붥�����Ϣ
		cin >> G->vexs[i];
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
}

int main() {
	return 0;
} 