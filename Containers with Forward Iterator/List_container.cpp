#include <iostream>
using std::cout;
using std::endl;
using std::cin;

template<class T>
class Container
{
public:
	struct List
	{
		T info_;
		List*next_;
		List() :next_(NULL) {};
		List(const T& info, List*next = NULL) :info_(info), next_(next) {};
	};
	class Forward_Iterator
	{
		List*ptr_;
	public:
		//ctors
		Forward_Iterator() {};
		Forward_Iterator(Forward_Iterator&second) { ptr_ = second.ptr_; };
		explicit Forward_Iterator(List*obj) :ptr_(obj) {};
		//bool
		bool operator==(Forward_Iterator& second) { return ptr_ = second.ptr_; };
		bool operator!=(Forward_Iterator& second) { return ptr_ != second.ptr_; };
		//++
		Forward_Iterator& operator++() {
			if (ptr_->next_) {
				ptr_ = ptr_->next_;
				return *this;
			}
			else {
				List* obj = new Node();
				ptr_->next_ = obj;
				ptr_ = ptr_->next_;
				return *this;
			}
		}


		Forward_Iterator  operator++(int) {
			if (ptr_->next_) {
				Forward_Iterator current;
				current = *this;
				ptr_ = ptr_->next_;
				return current;
			}
			else {
				Forward_Iterator current;
				current = *this;
		 	List* obj = new List();
				ptr_->next_ = obj;
				ptr_ = ptr_->next_;
				return current;
			}
		}
		//* =
		T& operator*()
		{
			return ptr_->info_;
		}
		Forward_Iterator operator=(Forward_Iterator& second_) { ptr_ = second_.ptr_; return *this; };
		Forward_Iterator operator=(T&info)
		{
			ptr_->info_ = info;
			return *this;
		}
		
			
	};
	//typdef
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef Forward_Iterator iterator;
	//ctors
	Container():arr_list_(new List()) {};
	Container(List& obj_) { arr_list_ =&obj_; };
	//=
	Container operator=(Container& second_) { arr_list_ = second_.arr_list_; return *this; };
	//bool
	bool operator==(Container& second_) { return second_.arr_list_ == arr_list_; };
	bool operator!=(Container& second_) { return second_.arr_list_ != arr_list_; };
	bool operator <(Container& second_)
	{

		int size_ = (size() >= second_.size()) ? second_.size() : size();

		Forward_Iterator first = begin();
		Forward_Iterator second = second_.begin();

		for (int i = 0; i < size_; i++) {
			if (*first == *second)
			{
				first++; second++;
				continue;
			}

			if (*first < *second)
				return true;
			else
				return false;
		}
	}
	bool operator>(Container& second_)
	{

		int size_ = (size() >= second_.size()) ? second_.size() : size();

		Forward_Iterator first = begin();
		Forward_Iterator second = second_.begin();

		for (int i = 0; i < size_; i++) {
			if (*first == *second)
			{
				first++; second++;
				continue;
			}

			if (*first > *second) 
				return true;
			else
				return false;
		}
	}
	bool operator>=(Container& second_)
	{

		int size_ = (size() >= second_.size()) ? second_.size() : size();

		Forward_Iterator first = begin();
		Forward_Iterator second = second_.begin();

		for (int i = 0; i < size_; i++) {
			if (*first == *second)
			{
				first++; second++;
				continue;
			}

			if (*first > *second)
				return true;
			else
				return false;
		}
	}
	bool operator<=(Container& second_)
	{

		int size_ = (size() >= second_.size()) ? second_.size() : size();

		Forward_Iterator first = begin();
		Forward_Iterator second = second_.begin();

		for (int i = 0; i < size_; i++) {
			if (*first == *second)
			{
				first++; second++;
				continue;
			}

			if (*first < *second)
				return true;
			else
				return false;
		}
	}
	bool empty()
	{
		return(arr_list_->next_) ? false : true;
		
	}
	
	//others
	Forward_Iterator begin() { return Forward_Iterator(arr_list_); }
	Forward_Iterator end()
	{
		List*current = arr_list_;
		for(; current->next_; current = current->next_)
			current = current->next_;
		return Forward_Iterator(current);
	};
	int size() {
		List* current = arr_list_;
		int size_= 0;
		while (current->next_) { size_++; current = current->next_; }

		return size_;
	}
	void swap(Container& second_)
	{
		Container temp(arr_list_);
		arr_list_ = second_.arr_list_;
		second_.arr_list_ = temp.arr_list_;
	}
	void print()
	{
		iterator it = this->begin();
		size_t size_ = size();
		for (int i = 0; i < size_; i++)
			cout << *it++<<" ";
		cout << endl;
	}

	private:
		List*arr_list_;

};

template<class Cont,class Iterator>
Cont merge(Cont& first_c, Cont& second_c)
{
	//First Iterators ande end Iteratos for our Containers
	Iterator first = first_c.begin();
	Iterator first_end = first_c.end();
	Iterator second = second_c.begin();
	Iterator second_end = second_c.end();
	//Our Container which must include all elements of two containers
	Cont NewCont;
	//Iterator For our NewContainer
	Iterator Newcont_it=NewCont.begin();

	while (first != first_end && second != second_end) {

		if (*first <= *second)
		{
			*Newcont_it = *first;
			first++;
		}
		else
		{
			*Newcont_it = *second;
			second++;
		}
		Newcont_it++;
	}
	while (first != first_end)
		*Newcont_it++ = *first++;
	while (second!= second_end)
		*Newcont_it++ = *second++;
	return NewCont;

}
int main()
{
	Container<int> cont1, cont2;
	cout << "We were create 2 containers with int type-parametrs\nLets check about empty" << endl;
	cout << "1 Container-" << cont1.empty() << "\n2 Container-" << cont2.empty();
	
	cout << "\n\nLets Init our containers\n";
	Container<int>::Forward_Iterator first = cont1.begin();
	Container<int>::Forward_Iterator second = cont2.begin();
	for (int i = 0, j = 1; j <= 20; i += 2, j += 2)
	{
		*first++ = i;
		*second++= j;
	}
	cont1.print();
	cont2.print();

	if (cont1 > cont2)cout << "Container 1 > Container 2" << endl;
	if (cont1 < cont2) cout << "Containter 1 < Container 2\n\n" << endl;
	cout << "How we see we created 2 Containers with int and printed\n Now lets run Merge Algoritm for our 2 containers\n";
	result=merge<Container<int>, Container<int>::Forward_Iterator>(cont1, cont2);
	cout << "Our result\nSize-"<<endl;
	result.print();
	cout << result.size();
	
	Container<int>result;
	
	
	cin.get();
}