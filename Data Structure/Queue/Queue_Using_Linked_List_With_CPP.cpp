//Queue using linked list
#include<iostream>
using namespace std;

template<typename T>
class Node
{
 public:
	T data;
	Node<T> *next;
};

template<typename T>
class MQueue
{
	private:
		Node<T> *f,*r;
	public:
		MQueue<T>()
		{
			f=r=NULL;
		}
		int enqueue(T d);
		T dequeue();
		int isEmptyQueue();
};

template<typename T>
int MQueue<T>::enqueue(T d)
{
	Node<T> *n=new Node<T>();
	if(n==NULL)
		return 0;
	else
	{
		n->data=d;
		if(f==NULL || r==NULL)	
		{
			f=r=n;
			return 1;
		}
		else
		{
			r->next=n;
			r=n;
			return 1;
		}
	}
}


template<typename T>
T MQueue<T>::dequeue()
{
	T data;
	Node<T> *ptr;
	if(isEmptyQueue())
	return 0;
	else
	{
		data=f->data;	
		ptr=f;
		f=f->next;
		delete ptr;
		if(f==NULL)
		r=NULL;
		return data;
	}
	return 0;
}

template<typename T>
int MQueue<T>::isEmptyQueue()
{
	if(r==NULL && f==NULL)
	return 1;
	return 0;
}


int main()
{
MQueue<int> *qt=new MQueue<int>();

cout<<"isEmpty="<<(*qt).isEmptyQueue()<<"\n";
(*qt).enqueue(5);
(*qt).enqueue(8);
cout<<"isEmpty="<<(*qt).isEmptyQueue()<<"\n";
cout<<"dequeue :"<<(*qt).dequeue()<<"\n";

cout<<"isEmpty="<<(*qt).isEmptyQueue()<<"\n";
return 0;
}
