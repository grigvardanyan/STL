#include <iostream>
using namespace std;

template<class T>
class Queue
{
public:
	Queue() {};
	virtual ~Queue() {};
	virtual bool empty() const = 0; 
	virtual bool full()=0;
	virtual T& front() = 0;
	virtual void pop() = 0;
	virtual void push(T&) = 0;
	virtual void print() = 0;
	
	
};

template<class T>
class C_Queue :public Queue<T>
{
	T* array_;
	int size_;
	int front_;
	int end_;
public:
	C_Queue(int size = 10) :
		size_(size),
		front_(-1),
		end_(-1)
	{
		
		array_ = new T[size_];
		//Initialization of array
		for (int i = 0; i < size_; i++)
			array_[i]=0;
	}
	~C_Queue()
	{
		delete[] array_; 
	}
	bool empty()const
	{
		return front_ == end_;
	}
	bool full()
	{
		return (end_+1 < size_) ? end_== front_ &&end_!=-1: front_ == -1;
		
	}
	void pop()
	{
		if (!empty())
		{
			(front_ + 1 < size_) ? array_[++front_] = 0 : array_[front_ = 0] = 0;
		}
		else
			cout << "The Queue is empty!!!\n";
		
	}
	void push( T& elem)
	{
		if (!full())
			(end_ + 1 < size_) ? array_[++end_] = elem : array_[end_ = 0] = elem;
		else
			cout << "THe Queue is full....\n";
	}
	T& front()
	{
		if (!empty())
			return (front_ + 1 < size_) ? array_[++front_] : array_[front_ = 0];
		else
			cout << "The Queue is empty...\n";
	}
	void print()
	{
		for (int i = 0; i < size_; i++)
		{
			cout << array_[i] << " ";
		}
		cout << endl;
	}

};

template<class T>
class L_Queue :public Queue<T>
{
	struct Node
	{
		T info_;
		Node*llink_;
		Node():
			llink_(0)
		{};
		Node(T& elem, Node* link = 0) :
			info_(elem),
			llink_(link) {};
	};
		Node Head_;
		Node*end_;
	public:
		
		L_Queue():
			end_(&Head_)
		{
			Head_.llink_ = 0;
		}
		~L_Queue()
		{
			Node* current = 0;
		while (Head_.llink_)
		{
			current = Head_.llink_;
			Head_.llink_ = current->llink_;
			delete current;
		} 
		}
	bool empty()const
		{
			return &Head_ == end_;
		}
	void pop()
		{
			if (!empty())
			{
				Node* current;
				current = Head_.llink_;
				Head_.llink_ = current->llink_;
				delete current;
			}
			
		}
	void push(T&elem)
		{
			end_ = end_->llink_ = new Node(elem);
		}
	void print()
		{
			Node *current=Head_.llink_;
			while (current)
			{
				cout << current->info_<<" ";
				current = current->llink_;
			}
			cout << endl;
		}
	T& front()
		{
		if (!empty())
			return Head_.llink_->info_;
		else
			cout << "Queue is empty...\n";
		}
	bool full() { return false; }

	
};
int main()
{
	
	Queue<int> *ptr = new C_Queue<int>;
	ptr->front();

	for (int i = 1; i <= 10; i++)
		ptr->push(i);

	ptr->print();
	int x = 5;

	cout << "Let's push 2 time's\n" << endl;
	ptr->push(x);
	ptr->push(x);
	ptr->print();

	
	ptr->pop();
	ptr->pop();
	ptr->pop();

	cout << "Aftrer 3 time's pop\n" << endl;
	ptr->print();
	
	ptr->push(++x);
	ptr->push(++x);
	cout << "After 2 time's push\n" << endl;

	ptr->print(); 

	ptr->push(++x);
	cout << "Lets push one more...\n";
	ptr->print();
	cout << "Lets push one more ...\n";
	ptr->push(++x);
	ptr->print();
	
	cout << "Now strat testing Queue with list\nWe created alredy List queue \nand its empty lets get one elemt from empty queue\n";
	
	Queue<int> *l = new L_Queue<int>();
	l->front();
	cout << "Start init queue  with elements\n";
	for (int i = 10; i <= 20; i++)
	{
		l->push(i);

	}
	l->print();

	cout << "Lets pop some of theirs 4 time's\n";
	l->pop();
	l->pop();
	l->pop();
	l->pop();
	l->print();
	cout << "Lets push 3 elemets\n";
	l->push(++x);
	l->push(++x);
	l->push(++x);
	l->print();
	cin.get();
	return 0;
}