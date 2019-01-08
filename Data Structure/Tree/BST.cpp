//Binary Search Tree 
#include<iostream>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;

template<typename T>
class Node
{
	private:
	   T data;
	   Node<T> *left,*right;
	public:	
	    Node<T>(T d)
	    {
		data=d;
		left=right=NULL;
	    }
	   void setLeft(Node<T> *l)
	    {
		left=l;
	    }
	   void setRight(Node<T> *r)
	    {
		right=r;
	    }
	   Node<T> *getLeft()
	   {
		return left;
	   }
	  Node<T> *getRight()
	   {
		return right;
	   }
	  T getData()
	   {
 		return data;
           }
	
};

template<typename T>
class BST
{

	public:
		Node<T> *insert(Node<T> *root,T d);
		void inorder(Node<T> *root);//Recursive
		void inorderNonRecursive(Node<T> *root);//Non-Recursive
		void preorder(Node<T> *root);//Recursive
		void preorderNonRecursive(Node<T> *root);//Non-Recursive
		void postorder(Node<T> *root);//Recursive
		void postorderNonRecursive(Node<T> *root);//Non-Recursive
		void levelOrderTraversing(Node<T> *root);//Non-Recursive
		int  sizeOfBST(Node<T> *root);
		int  heightOfBST(Node<T> *root);
};

template<typename T>
Node<T> *BST<T>::insert(Node<T> *root,T d)
{
	if(!root)
	return new Node<T>(d);
	else
	{
		if(d < (*root).getData())
		(*root).setLeft(insert((*root).getLeft(),d));
		else if(d > (*root).getData())
		(*root).setRight(insert((*root).getRight(),d));
		else
		return root;
	}
}

template<typename T>
void BST<T>::inorder(Node<T> *root)
{
	if(!root)
	return;
	inorder((*root).getLeft());
	cout<<(*root).getData()<<"  ";
	inorder((*root).getRight());
}

template<typename T>
void BST<T>::inorderNonRecursive(Node<T> *root)//Non-Recursive
{
	if(!root)
	return;
	stack<Node<T> *> st;
	while(true)
	{
		if(root)
		st.push(root);
		while(root)
		{
			root=(*root).getLeft();
			if(root)
			st.push(root);
		}
		if(st.empty())
		break;
		cout<<(*st.top()).getData()<<"  ";
		root=(*st.top()).getRight();
		st.pop();
	}
	
}


template<typename T>
void BST<T>::preorder(Node<T> *root)
{
	if(!root)
	return;
	cout<<(*root).getData()<<"  ";
	preorder((*root).getLeft());
	preorder((*root).getRight());
}

template<typename T>
void BST<T>::preorderNonRecursive(Node<T> *root)//Non-Recursive
{
	if(!root)
	return;
	stack<Node<T> *> st;
	while(true)
	{
		if(root)
		st.push(root);
		while(root)
		{
			cout<<(*root).getData()<<"  ";
			root=(*root).getLeft();
			if(root)
			st.push(root);
		}
		if(st.empty())
		break;
		root=(*st.top()).getRight();
		st.pop();
	}
	
}

template<typename T>
void BST<T>::postorder(Node<T> *root)
{

	if(!root)
	return;
	postorder((*root).getLeft());
	postorder((*root).getRight());
	cout<<(*root).getData()<<"  ";
}

template<typename T>
void BST<T>::postorderNonRecursive(Node<T> *root)//Non-Recursive
{
	if(!root)
	return;
	stack<Node<T> *> st;
	Node<T> *previous=NULL;
	do
	{
		while(root)
		{
			st.push(root);
			root=(*root).getLeft();
		}
		while(root==NULL && !st.empty())
		{
			root=st.top();
			if((*root).getRight()==NULL || (*root).getRight()==previous)
			{
				cout<<(*root).getData()<<"  ";
				st.pop();
				previous=root;
				root=NULL;
			}
			else
			root=(*root).getRight();
		}
	}while(!st.empty());
	
}

template<typename T>
void BST<T>::levelOrderTraversing(Node<T> *root)
{
	if(!root)	
	return;
	queue<Node<T> *> q;
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		cout<<(*root).getData()<<"  ";
		q.pop();
		if((*root).getLeft())
		q.push((*root).getLeft());
		if((*root).getRight())
		q.push((*root).getRight());
		
	}
}
template<typename T>
int BST<T>::sizeOfBST(Node<T> *root)
{
	if(!root)
	return 0;
	return sizeOfBST((*root).getLeft())+sizeOfBST((*root).getRight())+1;
}

template<typename T>
int BST<T>::heightOfBST(Node<T> *root)
{
int lh,rh;
	if(!root)
	return 0;
	lh=heightOfBST((*root).getLeft());
	rh=heightOfBST((*root).getRight());
	if(lh>rh)
	return lh+1;
	else
	return rh+1;
}

int main()
{
BST<int> *bst=new BST<int>();
Node<int> *root=NULL;
root=(*bst).insert(root,8);
root=(*bst).insert(root,5);
root=(*bst).insert(root,12);
root=(*bst).insert(root,3);
root=(*bst).insert(root,6);
root=(*bst).insert(root,18);
root=(*bst).insert(root,20);

cout<<"\n Inorder Traversal:\n";
(*bst).inorder(root);
cout<<"\n";
(*bst).inorderNonRecursive(root);

cout<<"\n Preorder Traversal:\n";
(*bst).preorder(root);
cout<<"\n";
(*bst).preorderNonRecursive(root);

cout<<"\n Postorder Traversal:\n";
(*bst).postorder(root);
cout<<"\n";
(*bst).postorderNonRecursive(root);

cout<<"\n levelOrderTraversing:\n";
(*bst).levelOrderTraversing(root);
cout<<"\n";

cout<<"Size of BST :"<<(*bst).sizeOfBST(root)<<"\n";
cout<<"height of BST :"<<(*bst).heightOfBST(root)<<"\n";

return 0;
}
