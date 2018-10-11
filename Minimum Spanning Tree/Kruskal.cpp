#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
	int first_;
	int second_;
	int weight_;
	Edge(int first = 0, int second = 0, int weight = 0) :first_(first), second_(second), weight_(weight) {};
};
struct Node
{
	int rank_;
	int key_;
	Node*parrent_;
	Node(int rank = 0, int key = 0, Node*parrent = 0) :rank_(rank), key_(key), parrent_(parrent) {};

};
struct Graph
{

	Node*SetOFNodes_;
	Edge**SetOfEdges_;
	Graph(Node*SetOfNodes = NULL, Edge**SetOfEdges = NULL) :SetOfEdges_(SetOfEdges), SetOFNodes_(SetOfNodes) {};
};

void Make_Set(Node*elem, int);

Node*Find_Set(Node*current);

void Link(Node*R1, Node*R2);

void Union_Sets(Node*root1, Node* root2);

void Sort(Edge**);

Graph*Kruskal(Graph*);

int main()
{
	int EdgesFirst[9] = { 0,2,4,0,1,0,3,1,4 };//araji gagat koxer
	int EdgesSecond[9] = { 1,3,5,4,5,2,5,3,2 };//erkrod gagat koxeri
	int EdgesWight[9] = { 5,4,4,25,20,20,10,3,5 };//qash@ koxeri

	Node *V = new Node[6];
	int *Vnumb = new int[6];
	for (int i = 0; i < 6; i++)
	{
		Vnumb[i] = i;
		Make_Set(&V[i], Vnumb[i]);
	}//sarquma Gagat u key a talis

	Edge**E = new Edge*[9];
	for (int i = 0; i < 9; i++)
	{
		E[i] = new Edge(EdgesFirst[i], EdgesSecond[i], EdgesWight[i]);
	}//sarquma koxere @st 3 arrayneri verevi
	Sort(E);//sortavoruma koxere @St weighti

	Graph G(V, E);//sarquma Graf @st gagatneri u sortavorvac kxoeri

	for (int i = 0; i < 9; i++)//stugumenq norml sortavorvaca koxere
		cout << i + 1 << "First-" << G.SetOfEdges_[i]->first_ << "Second -" << G.SetOfEdges_[i]->second_ << " weight-" << G.SetOfEdges_[i]->weight_ << endl;


	Graph*G1=Kruskal(&G);//bayc de chhasa sran)))
	for (int i = 0; i < 5; i++)
		cout << G1->SetOfEdges_[i]->weight_ << endl;







	system("pause");
	return 0;
}
Graph*Kruskal(Graph*G)
{
	
	Edge**EdgeN_1 = new Edge*[6 - 1];//verjnakan kmaxqi abzmutyunna
	for (int i = 0, j = 0; i < 9; i++)
	{
		if (Find_Set(&G->SetOFNodes_[G->SetOfEdges_[i]->first_]) != Find_Set(&G->SetOFNodes_[G->SetOfEdges_[i]->second_]))//ete @ntacik koxi araji gagate u 2 rd gagate nuyn parrente chunen 
		{
			Union_Sets(&G->SetOFNodes_[G->SetOfEdges_[i]->first_],&G->SetOFNodes_[G->SetOfEdges_[i]->second_]);// , sarqi iyancic antar vor meke myusi parente lini
			EdgeN_1[j++] = G->SetOfEdges_[i];//  @Ntacik koxe tar verjnakan koxi bazmutyan mej
			cout << "first-" << EdgeN_1[j - 1]->first_ << "Second-" << EdgeN_1[j - 1]->second_ << "weight-" << EdgeN_1[j - 1]->weight_ << endl;

		}
	}
	return G;
}

void Make_Set(Node*elem, int x)
{
	elem->parrent_ = elem;
	elem->rank_ = 0;
	elem->key_ = x;
};

Node*Find_Set(Node*current)
{
	if (current->parrent_ != current)
		current->parrent_ = Find_Set(current->parrent_);
	else
		return current->parrent_;
};

void Link(Node*R1, Node*R2)
{
	if (R1->rank_ > R2->rank_)
		R2->parrent_ = R1;
	else
		R1->parrent_ = R2;
	if (R1->rank_ == R2->rank_)
		++R2->rank_;

};

void Union_Sets(Node*root1, Node* root2)
{

	Link(Find_Set(root1), Find_Set(root2));

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
