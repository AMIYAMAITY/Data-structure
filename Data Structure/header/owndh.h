
/*  ----------------------------MStack class with program ----------------*/

//Stack using linked list
#include<iostream>

using namespace std;

template<typename T>
class _Node
{
	public:
	T data;
	_Node<T> *next;
	_Node<T>(){}
};


template<typename T>
class MStack
{
	private:
		_Node<T>  *top;
	public:
		MStack()
		{
			top=NULL;
		}
		int push(T d);
		_Node<T> *getTop();
		int isEmptyStack();
		T pop();
		void deleteStack();

};

template<typename T>
void MStack<T>::deleteStack()
{
	_Node<T> *t=top,*ptr;
	while(t!=NULL)
	{
		ptr=t;
		t=t->next;
		free(ptr);
	}
}

template<typename T>
int MStack<T>::isEmptyStack()
{
	if(top==NULL)
	return 1;
	return 0;
}

template<typename T>
_Node<T> *MStack<T>::getTop()
{
	return top;
}


template<typename T>
T MStack<T>::pop()
{
		
	_Node<T> *temp;
	T d;
	if(getTop()==NULL)
	return 0;
	else
	{
		d=top->data;
		temp=top;
		top=top->next;
		delete temp;
		return d;
	}
	return 0;
	
}



template<typename T>
int MStack<T>::push(T d)
{
	_Node<T> *temp=new _Node<T>();
	if(temp==NULL)
	return 0;
	else
	{
		temp->data=d;
		if(top==NULL)
		{
			top=temp;
			return 1;
		}
		else
		{
			temp->next=top;
			top=temp;
			return 1;
		}
	}
	return 0;
}



/*  ----------------------------MQueue class with program ----------------*/

//Queue using linked list

template<typename T>
class __Node
{
 public:
	T data;
	__Node<T> *next;
};

template<typename T>
class MQueue
{
	private:
		__Node<T> *f,*r;
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
	__Node<T> *n=new __Node<T>();
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
	__Node<T> *ptr;
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

