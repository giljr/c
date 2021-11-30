/* Project 19  -- BREATH FIRST SEARCH ALGORITHM (BFS)

    19_GRAPHBREATHFIRST_V0.C
    ------------------------
    
    This is a college work for BREATH FIRST SEARCH ALGORITHM (BFS).
    
         
	BFS algorithm
	A standard BFS implementation puts each vertex of the graph into one of two categories:

	Visited
	Not Visited
	The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

	The algorithm works as follows:

	Start by putting any one of the graph's vertices at the back of a queue.
	Take the front item of the queue and add it to the visited list.
	Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
	Keep repeating steps 2 and 3 until the queue is empty.
	The graph might have two different disconnected parts so to make sure that we cover every vertex, we can also run the BFS algorithm on every node
	************************************************************
	Output:
	
	Choose a vertex to start the search:
	0

	Vertex Adjacency List 0:
	2 -> 1 -> 

	Vertex Adjacency List 1:
	3 -> 0 -> 

	Vertex Adjacency List 2:
	3 -> 0 -> 

	Vertex Adjacency List 3:
	Pressione qualquer tecla para continuar. . .
	(base) PS C:\Users\giljr\Desktop\vscode2> cd "c:\Users\giljr\Desktop\vscode2\" ; if ($?) { gcc 19_graphbreadthfirst_v0.c -o 19_graphbreadthfirst_v0 } ; if ($?) { .\19_graphbreadthfirst_v0 }
	Choose a vertex to start the search:
	0

	Vertex Adjacency List 0:
	2 -> 1 -> 

	Vertex Adjacency List 1:
	3 -> 0 -> 

	Vertex Adjacency List 2:
	3 -> 0 -> 

	Vertex Adjacency List 3:
	5 -> 4 -> 2 -> 1 ->

	Vertex Adjacency List 4:
	3 ->

	Vertex Adjacency List 5:
	3 ->

	Visited Graph Vertexes, starting at V0:
	V0      V2      V3      V5      V4      V1
	Pressione qualquer tecla para continuar. . . 
   ************************************************************
    
 	Based on: https://www.programiz.com/dsa/graph-bfs
	   
	UNINTER - Course: Computer Engineering
	Polytechnic School
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Dez, 2021
 */
#include <stdio.h>
#include <stdlib.h>

#define VERTEX_NUMBER 6

typedef struct AdjacentNodesList
{
	int vertex;
	struct AdjacentNodesList *prox;
} AdjNodesList_t;

typedef struct Graph
{
	int Totalvertexes;
	struct AdjacentNodesList **ListaAdj;
} Graph_t;

struct STACK
{
	int vertex;
	struct STACK *prox;
} *top = NULL;

Graph_t *MakeGraph(int vertexes);
void AddVertex(Graph_t *Graph, int source, int destination);
void ShowGraph(Graph_t *Graph);
void BreadthFirstSearch(Graph_t *AdjNodes, int v, int visited[]);
void push(int y);
void pop();

int main()
{
	int visited[VERTEX_NUMBER] = {0};
	int source;

	Graph_t *GraphTest = MakeGraph(VERTEX_NUMBER);
	AddVertex(GraphTest, 0, 1);
	AddVertex(GraphTest, 0, 2);
	AddVertex(GraphTest, 1, 3);
	AddVertex(GraphTest, 2, 3);
	AddVertex(GraphTest, 3, 4);
	AddVertex(GraphTest, 3, 5);

	printf("Choose a vertex to start the search:\n");
	scanf_s("%d", &source);

	ShowGraph(GraphTest);

	printf("\nVisited Graph Vertexes, starting at V%d:\n", source);
	BreadthFirstSearch(GraphTest, source, visited);

	printf("\n");
	system("pause");
	return 0;
}

Graph_t *MakeGraph(int Totalvertexes)
{
	Graph_t *Graph = (Graph_t *)malloc(sizeof(Graph_t));
	Graph->Totalvertexes = Totalvertexes;
	Graph->ListaAdj = (AdjNodesList_t **)malloc(Totalvertexes * sizeof(AdjNodesList_t *));

	for (int i = 0; i < Totalvertexes; i++)
		Graph->ListaAdj[i] = NULL;

	return Graph;
}

void AddVertex(Graph_t *Graph, int source, int destination)
{
	AdjNodesList_t *NewItem = (AdjNodesList_t *)malloc(sizeof(AdjNodesList_t));
	NewItem->vertex = destination;
	NewItem->prox = NULL;

	NewItem->prox = Graph->ListaAdj[source];
	Graph->ListaAdj[source] = NewItem;

	NewItem = (AdjNodesList_t *)malloc(sizeof(AdjNodesList_t));
	NewItem->vertex = source;
	NewItem->prox = NULL;

	NewItem->prox = Graph->ListaAdj[destination];
	Graph->ListaAdj[destination] = NewItem;
}

void ShowGraph(Graph_t *Graph)
{
	int v;
	for (v = 0; v < Graph->Totalvertexes; v++)
	{
		AdjNodesList_t *ScanItem = Graph->ListaAdj[v];
		printf("\n Vertex Adjacency List %d:\n ", v);
		while (ScanItem != NULL)
		{
			printf("%d -> ", ScanItem->vertex);
			ScanItem = ScanItem->prox;
		}
		printf("\n");
	}
}

void BreadthFirstSearch(Graph_t *AdjNodes, int v, int visited[])
{
	int w;
	AdjNodesList_t *ScanItem;
	ScanItem = (AdjNodesList_t *)malloc(sizeof(AdjNodesList_t));

	visited[v] = 1;
	printf("V%d\t", v);
	push(v);
	ScanItem = AdjNodes->ListaAdj[v];
	//if (ScanItem == NULL) {
	//	return;
	//}
	while (ScanItem != NULL)
	{
		w = ScanItem->vertex;
		if (visited[w] != 1)
		{
			BreadthFirstSearch(AdjNodes, w, visited);
		}
		ScanItem = ScanItem->prox;
	}
	pop();
}

void push(int y)
{

	struct STACK *NewItem;
	NewItem = (struct STACK *)malloc(sizeof(struct STACK));
	NewItem->vertex = y;

	if (top == NULL)
	{
		top = NewItem;
		top->prox = NULL;
	}
	else
	{
		NewItem->prox = top;
		top = NewItem;
	}
}

void pop()
{

	struct STACK *NewItem;
	NewItem = (struct STACK *)malloc(sizeof(struct STACK));

	if (top == NULL)
	{
		//top = NewItem;
		//top->prox = NULL;
	}
	else
	{
		NewItem = top;
		top = top->prox;
		free(NewItem);
	}
}