#include<iostream>
using namespace std;
class Node{
	public:
		Node* left;
		Node* right;
		int key;
		Node(int k)
		{
			key=k;
			left=NULL;
			right= NULL;
		}
};

///////////////////

class QueueNode{
	public:
		Node* data;
		QueueNode* next;
		QueueNode(Node* n){
			data =n;
			next =NULL;
		}
};
class Queue{
	QueueNode* front;
	QueueNode* rear;
	public:
		Queue(){
			front=NULL;
			rear=NULL;
		}
		bool isEmpty()
		{
			return front == NULL;
			
		}
		void enQueue(Node* n)
		{
		   QueueNode* newNode=new QueueNode(n);
		   	if(isEmpty())
		   	{
		   		front = rear = newNode;	
			}
			else{
				rear->next=newNode;
				rear=newNode;
			}
		}
		void deQueue()
		{
			if(isEmpty())
		   	{
		   		return;	
			}
			QueueNode* temp=front;
			front= front->next;
			delete temp;
			
		}
		Node* getfront()
		{
			if(isEmpty())
		   	{
		   		return NULL;	
			}
			return front->data;
		}
};
///////////////////////
class BinaryTree{
	public:
		Node* root;
		
		
		BinaryTree()
		{
			root=NULL;
		}
		
		
		void inOrder(Node* root)
		{
			if (root!=NULL)
			{
			inOrder(root->left);
			cout<<root->key<<"  ";
			inOrder(root->right);	
			}
		}
		
		void preOrder(Node* root)
		{
			if (root!=NULL)
			{
			cout<<root->key<<"   ";
			preOrder(root->left);
			preOrder(root->right);	
			}
		}
		
		void postOrder(Node* root)
		{
			if (root!=NULL)
			{
			postOrder(root->left);
			postOrder(root->right);
			cout<<root->key<<"  ";	
			}
		}
		
		
		void levelOrderPrint(Node* root)
		{
			if(root==NULL)
			return;
			Queue q;
			q.enQueue(root);
			while (q.isEmpty()==false)
			{
				Node* curr=q.getfront();
				q.deQueue();
				cout<<curr->key<<"  ";
				if(curr->left!=NULL)
				q.enQueue(curr->left);
				if(curr->right!=NULL)
				q.enQueue(curr->right);
			}
		}
	
		
};
int main()
{
BinaryTree bt;
bt.root=new Node(10);
bt.root->left=new Node(20);	
bt.root->right=new Node(30);
bt.root->right->left=new Node(40);
bt.root->right->right=new Node(50);

cout<<"in order "<<endl;
bt.inOrder(bt.root);
cout<<endl<<endl;

cout<<"pre order "<<endl;
bt.preOrder(bt.root);
cout<<endl<<endl;

cout<<"post order "<<endl;
bt.postOrder(bt.root);
cout<<endl<<endl;
cout<<"level order "<<endl;
bt.levelOrderPrint(bt.root);
}

