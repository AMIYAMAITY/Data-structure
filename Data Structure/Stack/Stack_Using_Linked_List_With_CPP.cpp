//Stack using linked list
#include<iostream>

using namespace std;

template<typename T>
class Node
{
	public:
	T data;
	Node<T> *next;
	Node<T>(){}
};


template<typename T>
class Stack
{
	private:
		Node<T>  *top;
	public:
		Stack()
		{
			top=NULL;
		}
		int push(T d);
		Node<T> *getTop();
		int isEmptyStack();
		T pop();
		void deleteStack();

};

template<typename T>
void Stack<T>::deleteStack()
{
	Node<T> *t=top,*ptr;
	while(t!=NULL)
	{
		ptr=t;
		t=t->next;
		free(ptr);
	}
}

template<typename T>
int Stack<T>::isEmptyStack()
{
	if(top==NULL)
	return 1;
	return 0;
}

template<typename T>
Node<T> *Stack<T>::getTop()
{
	return top;
}


template<typename T>
T Stack<T>::pop()
{
		
	Node<T> *temp;
	T d;
	if(getTop()==NULL)
	return 0;
	else
	{
		d=top->data;
		temp=top;
		top=top->next;
		free(temp);
		return d;
	}
	return 0;
	
}



template<typename T>
int Stack<T>::push(T d)
{
	Node<T> *temp=new Node<T>();
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




int main()
{
Stack<int> st;
for(int i=65;i<70;i++)
st.push(i);
//st.deleteStack();

for(int i=1;i<=5;i++)
cout<<"pop"<<i<<"="<<st.pop()<<"\n";



cout<<"isEmpty="<<st.isEmptyStack();
return 0;
}
