
#include <iostream>
using namespace std;


template<class T, int size_= 10>
class Array
{

	T* array_;
	friend class Random_Iterator;

public:
	// Array Ctors
	Array() :array_(new T[size_]) {}
	~Array() { delete[]array_; }
	void print()
	{
		for (int i = 0; i < size_; i++) cout << array_[i] << endl;
	}
	//Random Iterator
	class Random_Iterator {

		T* current_;

	public:
		//Random IT Ctors

		Random_Iterator() {}
		Random_Iterator(const Random_Iterator& second_)
		{
			current_ = second_.current_;
		}
		explicit Random_Iterator(T* second_) : current_(second_) {}

		//Bool functions == != > < >= <=

		bool operator==(const Random_Iterator&  second_)const
		{
			return this == &second_; 
		}
		bool operator!=(const Random_Iterator&  second_)const
		{
			return this != &second_;
		}
		bool operator>(const Random_Iterator& second_)
		{
			if (current_ - second_.current_ > 0)
				return true;
			else
				return false;
		}
		bool operator>=(const Random_Iterator& second_)
		{
			if (current_ - second_.current_ >= 0)
				return true;
			else
				return false;
		}
		bool operator<(const Random_Iterator& second_)
		{
			if (current_ - second_.current_ < 0)
				return true;
			else
				return false;
		}
		bool operator<=(const Random_Iterator& second_)
		{
			if (current_ - second_.current_ <= 0)
				return true;
			else
				return false;
		}

		//   * []  - +

		T& operator*()const 
		{
			return *current_;
		}
		T  operator[](int index_)
		{
			return *Random_Iterator(current_ + index_); 
		}
		T  operator-(const Random_Iterator& second_)
		{
			return current_ - second_.current_;
		}
		Random_Iterator operator+(int second_)
		{
			return Random_Iterator(current_ + second_);
		}
		Random_Iterator operator-(int second_)
		{
			return Random_Iterator(current_ - second_);
		}
		//   += -=
		Random_Iterator operator+=(int second_) 
		{
			current_ += second_; return *this;
		}
		Random_Iterator operator-=(int second_) 
		{
			current_ -= second_; return *this; 
		}
		// ++ --
		Random_Iterator& operator++()
		{
			++current_; return *this;
		}
		Random_Iterator& operator--() 
		{
			--current_; return *this; 
		}

		Random_Iterator  operator++(int)
		{
			Random_Iterator it; 
			it = *this;
			++current_;
			return it;
		}
		Random_Iterator  operator--(int)
		{
			Random_Iterator it;
			it = *this;
			--current_; 
			return it; 
		}
		// =  
		Random_Iterator& operator=(const Random_Iterator& second_)
		{
			current_ = second_.current_;
			return *this; 
		}
		Random_Iterator& operator=(T* second_)
		{
			current_ = second_;  
			return *this; 
		}
};

	Random_Iterator begin_()
	{
		return Random_Iterator(array_);
	}
	Random_Iterator end_()
	{
		return Random_Iterator(array_ + size_ - 1);
	}

};


template<class Random_Iterator, class T>
Random_Iterator Bin_Search_(Random_Iterator first_, Random_Iterator last_, const T& digit_) {

	Random_Iterator left_ = first_;
	Random_Iterator right_ = last_ - 1;
	Random_Iterator middle_;
	cout << " We are in BinSearch and we use there operators < <= + ==\n Please press ENTER" << endl;
	cin.get();
	while (left_ <= right_)
	{
		middle_ = left_ + (right_ - left_) / 2;

		if (digit_ == *middle_) return middle_;
		(digit_ < *middle_) ? right_ = middle_ - 1 : left_ = middle_ + 1;
	}

	return last_;
}


int main() {

	const int size_ = 10;
	Array<int, size_>array_;
	Array<int, size_>::Random_Iterator it = array_.begin_();
	cout << "Allready created Array with 10 elements and Iterator\n" << endl;
	cout << "Start Initializing our Array\n and use operator * , ++ , =\n" << endl;
	for (int i = 0; i < size_; i++)
		*it++ = i;			
	cout << "Now lets creat 2 iteratos for Binary Search and we will search 4\n"<<endl;
	Array<int, size_>::Random_Iterator first_ = array_.begin_();
	Array<int, size_>::Random_Iterator last_ = array_.end_();

	Array<int, size_>::Random_Iterator x;
	
	x = Bin_Search_<Array<int, size_>::Random_Iterator, int>(first_, last_, 4);
	cout << " ***It was find***\n We show it by operator *-\n" << *x << endl;
	cout << "Now lets search 25\n" << endl;
	x = Bin_Search_<Array<int, size_>::Random_Iterator, int>(first_, last_, 25);
	cout << "It wasn't finde and our function returned the last element  " << *x << endl;



	cin.get();

	return 0;
}