template<class T>

class BinarySearchTree
{
public:
	struct Node
	{
		T value;
		Node* left;
		Node* right;
	};

	BinarySearchTree();
	~BinarySearchTree();

	void Add(T value);
	void Remove(T value);
	Node* Search(T value);
	Node* Predecessor(T value);
	Node* Successor(T value);
	Node* Predecessor(Node* node);
	Node* Successor(Node* node);
private:

	Node* root = NULL;

};

