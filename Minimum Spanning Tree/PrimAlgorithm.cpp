#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node
{
	bool Qstatus_;
	int key_;
	Node*parrent_;
	Node(bool status = true, int key = INT_MAX, Node*parrent = NULL) :
		Qstatus_(status),
		key_(key),
		parrent_(parrent)
	{};

};

int** GraphInit();
int Min(Node**);
bool Empthy(Node**V);
int main(int argc, char* argv[])
{
	
	int Queu = 6;
	int**Edge = GraphInit();
	int CurrentNode = 0;

	Node**V = new Node*[6];
	for (int i = 0; i < 6; i++)
		V[i] = new Node();

	for(int i=0;i<6;i++)
	cout << "KEy- " << V[i]->key_ << " PArrent-" << V[i]->parrent_ << " Status- " << V[i]->Qstatus_ << endl;

	cout << " Finished creation of Nodes\n";
	V[0]->key_= 0;

	do
	{
		
		CurrentNode = Min(V);
		
		V[CurrentNode]->Qstatus_=false;
		
		for(int i = 0 ; i < 6 ; i++ )
			if (Edge[CurrentNode][i] != 0)
			{
				
				if (V[i]->Qstatus_==true && Edge[CurrentNode][i] < V[i]->key_)
				{
					V[i]->key_ = Edge[CurrentNode][i];
					V[i]->parrent_ = V[CurrentNode];
					
				}
			}		



	} while (!Empthy(V));

	cout << endl;
	for (int i = 1; i < 6; i++)
		cout << "Key- " << V[i]->key_ << " Parrent-" << V[i]->parrent_->key_<< " Status- " << V[i]->Qstatus_ << endl;
	system("pause");
	return 0;
}
int** GraphInit()
{

	int**Edges = new int*[6];

	for (int i = 0; i < 6; i++)
	{
		Edges[i] = new int[6];

		for (int j = 0; j < 6; j++)
			Edges[i][j] = 0;
	}

	Edges[0][1] = 9;
	Edges[0][3] = 8;
	Edges[0][4] = 1;
	Edges[1][0] = 9;
	Edges[1][2] = 4;
	Edges[1][5] = 3;
	Edges[2][1] = 4;
	Edges[2][3] = 1;
	Edges[3][0] = 8;
	Edges[3][2] = 1;
	Edges[3][4] = 5;
	Edges[4][0] = 1;
	Edges[4][3] = 5;
	Edges[4][5] = 2;
	Edges[5][1] = 3;
	Edges[5][4] = 2;
	cout << "End Init \n";
	return Edges;

}

int Min(Node**Queu)
{
	int min = INT_MAX;
	for (int i = 0; i < 6; i++)
	{
		if (Queu[i]->Qstatus_ == true)
		{
			min = i;
			break;
		}
	}

	//Find min key in queue
	for (int j = 0; j < 6; j++)
	{
		if (Queu[j]->Qstatus_==true&&(Queu[j]->key_ < Queu[min]->key_))
			min = j;
	}

	return min;
		
};

bool Empthy(Node**Queue)
{
	for (int i = 0; i < 6; i++)
	{
		if (Queue[i]->Qstatus_ == true)
		{
			return false;
		}
	}
	return true;
}

