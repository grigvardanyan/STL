#include "DisjointSet.h"
#include <iostream>
using std::cout;

struct Edge
{
	int first_;
	int second_;
	int weight_;
	Edge(int first = 0, int second = 0, int weight = 0) :first_(first), second_(second), weight_(weight) {};
};

struct Graph
{
	DisjointSet::Node* SetOFNodes_;
	Edge**SetOfEdges_;
	Graph(DisjointSet::Node* SetOfNodes = NULL, Edge** SetOfEdges = NULL) :SetOfEdges_(SetOfEdges), SetOFNodes_(SetOfNodes) {};
};

Graph* Kruskal(Graph* G);
void Sort(Edge**CurrentSet);

int main()
{
	int EdgesFirst[9] = { 0,2,4,0,1,0,3,1,4 };
	int EdgesSecond[9] = { 1,3,5,4,5,2,5,3,2 };
	int EdgesWight[9] = { 5,4,4,25,20,20,10,3,5 };

	DisjointSet* set = new DisjointSet();
	DisjointSet::Node *V = new DisjointSet::Node[6];

	int *Vnumb = new int[6];
	//Create Edge and set key
	for (int i = 0; i < 6; i++)
	{
		Vnumb[i] = i;
		set->Make_Set(&V[i], Vnumb[i]);
	}

	Edge**E = new Edge*[9];
	//Create Vertexes based on above array
	for (int i = 0; i < 9; i++)
	{
		E[i] = new Edge(EdgesFirst[i], EdgesSecond[i], EdgesWight[i]);
	}
	//Sort vertexes based on Weights
	Sort(E);
	//Create Graph
	Graph G(V, E);
	//Just checki for sorted result
	for (int i = 0; i < 9; i++)
		cout << i + 1 << "First-" << G.SetOfEdges_[i]->first_ << "Second -" << G.SetOfEdges_[i]->second_ << " weight-" << G.SetOfEdges_[i]->weight_ << std::endl;

	Graph*G1 = Kruskal(&G);

	for (int i = 0; i < 5; i++)
		cout << G1->SetOfEdges_[i]->weight_ <<std:: endl;

	std::cin.get();
	return 0;
}


Graph*Kruskal(Graph* G)
{
	DisjointSet* set = new DisjointSet();
	//EdgeN_1 is final tree
	Edge**EdgeN_1 = new Edge*[6 - 1];

	for (int i = 0, j = 0; i < 9; i++)
	{
		if (set->Find_Set(&G->SetOFNodes_[G->SetOfEdges_[i]->first_]) != set->Find_Set(&G->SetOFNodes_[G->SetOfEdges_[i]->second_])) 
		{
			set->Union_Sets(&G->SetOFNodes_[G->SetOfEdges_[i]->first_], &G->SetOFNodes_[G->SetOfEdges_[i]->second_]);//Make forest and set other as parrent
			EdgeN_1[j++] = G->SetOfEdges_[i];
			cout << "First-" << EdgeN_1[j - 1]->first_ << "Second-" << EdgeN_1[j - 1]->second_ << "Weight-" << EdgeN_1[j - 1]->weight_ << std::endl;
		}
	}
	return G;
}

void Sort(Edge**CurrentSet)
{
	Edge*SwapEdge = NULL;
	int min;
	//Sorting
	for (int i = 0; i < 8; i++)
	{
		min = i;
		for (int j = i + 1; j < 9; j++)
			if (CurrentSet[j]->weight_ < CurrentSet[min]->weight_)
				min = j;
		SwapEdge = CurrentSet[i];
		CurrentSet[i] = CurrentSet[min];
		CurrentSet[min] = SwapEdge;
	}
}





