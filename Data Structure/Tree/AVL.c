#include<stdio.h>
#include<stdlib.h>

struct Node 
{
int data;
struct Node *laddr;
struct Node *raddr;
int height;
};


int height(struct Node *node)
{
if(node==NULL)
return 0;
else
return node->height;
}


int max(int x,int y)
{
return (x>y)?x:y;
}


int getBalance(struct Node *N)
{
if(N==NULL)
return 0;
else
return (height(N->laddr)-height(N->raddr));
}


struct Node *newNode(int key)
{
struct Node *node=(struct Node *)malloc(sizeof(struct Node));
node->data=key;
node->laddr=NULL;
node->raddr=NULL;
node->height=1;
return node;
}


struct Node *leftRotation(struct Node *x)
{
struct Node *y = x->raddr;
struct Node *T2 = y->laddr;
 
    y->laddr = x;
    x->raddr = T2;
 
    x->height = max(height(x->laddr), height(x->raddr))+1;
    y->height = max(height(y->laddr), height(y->raddr))+1;

    return y;
}



struct Node *rightRotation(struct Node *y)
{
struct Node *x=y->laddr;
struct Node *t2=x->raddr;

x->raddr=y;
y->laddr=t2;

x->height=max(height(x->laddr),height(x->raddr))+1;
y->height=max(height(y->laddr),height(y->raddr))+1;

return x;
}



struct Node *insert(struct Node *node,int key)
{
if(node==NULL)
	return newNode(key);
 if(key<node->data)
	node->laddr=insert(node->laddr,key);
 else if(key>node->data)
	node->raddr=insert(node->raddr,key);
 else
	return node;

	node->height=1+max(height(node->laddr),height(node->raddr));

	int balance=getBalance(node);

	if(balance > 1 && key < node->laddr->data)	
		return rightRotation(node);

	if(balance > 1 && key > node->laddr->data)	
		{
		node->laddr=leftRotation(node->laddr);
		return rightRotation(node);
		}

	if(balance < -1 && key > node->raddr->data)	
		return leftRotation(node);

	if(balance < -1 && key < node->raddr->data)	
		{
		node->raddr=rightRotation(node->raddr);
		return leftRotation(node);
		}
	

return node;
}

struct Node *minValueNode(struct Node *node)
{
struct Node *current=node;
	while(current->laddr!=NULL)
		current=current->laddr;
return current;
}



struct Node *deleteNode(struct Node *root,int key)
{

if(root==NULL)
	return root;
else if(key < root->data )
	root->laddr=deleteNode(root->laddr,key);
else if(key > root->data )
	root->raddr=deleteNode(root->raddr,key);
else
{
	if( (root->laddr==NULL) || (root->raddr==NULL) )
	{
		struct Node *temp=root->laddr ? root->laddr : root->raddr;
		if( temp == NULL )
		{
			temp=root;
			root=NULL;
		}
		else
			*root=*temp;
		free(temp);
	}
	else
	{
		struct Node *temp=minValueNode(root->raddr);
			root->data = temp->data;
		root->raddr=deleteNode(root->raddr,temp->data);
	}

}

if(root==NULL)
return root;

root->height=1 + max(height(root->laddr),height(root->raddr));

int balance=getBalance(root);

if(balance > 1 && getBalance(root->laddr) >= 0)
	return rightRotation(root);

if(balance > 1 && getBalance(root->laddr) < 0)
{
	root->laddr=leftRotation(root->laddr);
	return rightRotation(root);
}

if(balance < -1 && getBalance(root->raddr) <= 0)
	return leftRotation(root);

if(balance < -1 && getBalance(root->raddr) > 0)
{
	root->raddr=rightRotation(root->raddr);
	return leftRotation(root);
}



return root;
}





void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->laddr);
        preOrder(root->raddr);
    }
}

int main()
{
 struct Node *root = NULL;
  root = insert(root, 30);
  root = insert(root, 25);
  root = insert(root, 31);
  root = insert(root, 35);
  root = insert(root, 33);
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);


root =deleteNode(root, 30);

printf("Preorder traversal of the after Delete AVL"
         " tree is \n");
  preOrder(root);
 
  return 0;
}
