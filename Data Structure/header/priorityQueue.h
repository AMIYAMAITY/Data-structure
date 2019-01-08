#include<iostream>
using namespace std;

template<typename T>
class PQ
{
	private:
		int rank;
		T data;
		PQ<T> *next;
	public:
		PQ()
		{
		next=NULL;
		}
		void setRank(int rank);
		void setData(T data);
		int getRank();
		T getData();
		void setNext(PQ<T> *next);
		PQ<T> *getNext();

};

template<typename T>
void PQ<T>::setRank(int rank)
{
(*this).rank=rank;
}

template<typename T>
void PQ<T>::setData(T data)
{
(*this).data=data;
}

template<typename T>
int PQ<T>::getRank()
{
return (*this).rank;
}

template<typename T>
T PQ<T>::getData()
{
return (*this).data;
}

template<typename T>
void PQ<T>::setNext(PQ<T> *nex)
{
(*this).next=nex;
}

template<typename T>
PQ<T> *PQ<T>::getNext()
{
return next;
}


template<typename T>
class PriorityQueue
{
	private:
		PQ<T> *front;
	public:
		PriorityQueue<T>()
		{
			front=NULL;
		}
		bool add(T data,int rank);
		PQ<T> *getFront();
		PQ<T> *getBack();
		bool popFront();
		bool popBack();
		bool isEmpty();
};



template<typename T>
bool PriorityQueue<T>::add(T data,int rank)
{
PQ<T> *pq=new PQ<T>();
PQ<T> *header,*ptr;
if(pq==NULL)
{
	cout<<endl<<"Memory Not Available"<<endl;
	return false;
}
else
{
	(*pq).setData(data);
	(*pq).setRank(rank);
	(*pq).setNext(NULL);
	
	if(front==NULL)
	{
		header=front=pq;
		return true;
	}
	else
	{
		if((*front).getRank() > rank)
		{
			(*pq).setNext(front);
			header=front=pq;
			return true;
		}
		else
		{
			while((*header).getNext()!=NULL)
			{
				if(rank < (*(*header).getNext()).getRank())
				{
					ptr=(*header).getNext();
					(*header).setNext(pq);
					(*pq).setNext(ptr);
					return true;
				}
				header=(*header).getNext();
			}
			(*header).setNext(pq);
			return true;
		}

		
	}	
	return false;
}
}


template<typename T>
PQ<T> *PriorityQueue<T>::getFront()
{

	if((*this).front==NULL)
	return NULL;
	return (*this).front;
}


template<typename T>
PQ<T> *PriorityQueue<T>::getBack()
{
PQ<T> *header,*ptr;
header=(*this).front;
	T data;

	if((*this).front==NULL)
		return NULL;
	else
	{
		while((*header).getNext()!=NULL)
			header=(*header).getNext();
			return header;
	}
}

template<typename T>
bool PriorityQueue<T>::popFront()
{
if(!(*this).front)
	return false;
else
{
PQ<T> *ptr;
	ptr=(*this).front;
	(*this).front=(*(*this).front).getNext();
	ptr=NULL;
	//free(ptr);
	return true;
}
return false;
}


template<typename T>
bool PriorityQueue<T>::popBack()
{
if(!(*this).front)
	return false;
if((*(*this).front).getNext()==NULL)
{
	(*this).front=NULL;
	//free((*this).front);
	return true;
}
else
{
PQ<T> *header=(*this).front;
PQ<T> *ptr;
	while((*(*header).getNext()).getNext()!=NULL)
		header=(*header).getNext();
		ptr=(*header).getNext();
		(*header).setNext(NULL);
		ptr=NULL;
		//free(ptr);
		return true;
}
}


template<typename T>
bool PriorityQueue<T>::isEmpty()
{
if((*this).front==NULL)
return true;
return false;
}
