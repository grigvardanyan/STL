#include "DisjointSet.h"

void DisjointSet::Make_Set(Node* elem, int x)
{
	elem->parrent_ = elem;
	elem->rank_ = 0;
	elem->key_ = x;
};

 DisjointSet::Node* DisjointSet::Find_Set(Node* current)
 {
	 if (current->parrent_ != current)
		 current->parrent_ = Find_Set(current->parrent_);
	 else
		 return current->parrent_;
 };

 void DisjointSet::Link(Node* R1, Node* R2)
 {
	 if (R1->rank_ > R2->rank_)
		 R2->parrent_ = R1;
	 else
		 R1->parrent_ = R2;
	 if (R1->rank_ == R2->rank_)
		 ++R2->rank_;
 };

 void DisjointSet::Union_Sets(Node*root1, Node* root2)
 {
	 Link(Find_Set(root1), Find_Set(root2));
 };



