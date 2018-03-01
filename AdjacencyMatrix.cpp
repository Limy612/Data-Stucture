#include <iostream>

using std::cout; 
using std::endl; 
using std::cin;

//邻接矩阵存储的结构
typedef char VertexType;//定义了一个新的类型别名，有类型检查
typedef int EdgeType;

#define MAXVEX 100
//#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

//无向网图的邻接矩阵表示
void CreatMGraph(MGraph *G)
{
	cout << "Please input numVertexes and numEdges" << endl;
	cin >> &G->numVertexes >> &G->numEdges >> endl;
	
}

int main()
{
	MGraph *G;
	CreatMGraph(G);
	return 0;
}