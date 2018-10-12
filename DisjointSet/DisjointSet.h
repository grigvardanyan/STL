
class DisjointSet
{
public:
	struct Node
	{
		int rank_;
		int key_;
		Node*parrent_;
		Node(int rank = 0, int key = 0, Node*parrent = 0) :rank_(rank), key_(key), parrent_(parrent) {};

	};

	void Make_Set(Node*elem, int);

	Node*Find_Set(Node*current);

	void Link(Node*R1, Node*R2);

	void Union_Sets(Node*root1, Node* root2);

};
