#include <iostream>
using namespace std;
void interFace()
{
	system("cls");
	cout<<endl<<endl<<"=====================================    ASSINGNEMT 4 PAGE 1   ================================"<<endl<<endl;
    	cout<<"    1.SINGLY LINKED LIST    "<<endl;
		cout<<"    2.DOUBLY LINKED LIST    "<<endl;
		cout<<"    3.SINGLY CIRCULAR LINKED LIST    "<<endl;
		cout<<"    4.SINGLY CIRCULAR LINKED LIST    "<<endl;
    	cout<<"    5.EXIT    "<<endl;
}
class Node
{
    public:
      int value;
      Node *next;
      Node *prev;
      Node(int v)
        {
         value = v;
         next = NULL;
         prev = NULL;      	
		}
};
class Linkedlist
{
public:
	Node *head;
	Linkedlist()
	{
		head=NULL;
    }
    void Menu()
    {
    	system("pause");
    	system ("cls");
    	cout<<endl<<endl<<"=====================================    SINGLY LINKEDLIST    ================================"<<endl<<endl;
    	cout<<"    1.ADD    "<<endl;
		cout<<"    2.addFirst    "<<endl;
    	cout<<"    3.addLAST    "<<endl;
    	cout<<"    4.deleteFirst    "<<endl;
    	cout<<"    5.deleteLast    "<<endl;
    	cout<<"    6.countNodes    "<<endl;
    	cout<<"    7.max    "<<endl;
    	cout<<"    8.average    "<<endl;
    	cout<<"    9.reverse    "<<endl;
    	cout<<"    10.detectLoop    "<<endl;
    	cout<<"    11.isPolindrome    "<<endl;
    	cout<<"    12.insertAt    "<<endl;
    	cout<<"    13.search    "<<endl;
    	cout<<"    14.display    "<<endl;
    	cout<<"    15.exit    "<<endl;
    	cout<<"    16.go back to page 1    "<<endl;
	}
    void addFirst(int v)
    {
    	system("cls");
    	Node *newNode= new Node(v);
    	newNode->next = head;
    	head = newNode;
	}
	void addLast(int v)
	{
		system("cls");
		Node *newNode = new Node(v);
		if (head==NULL)
		{
			head=newNode;
		}
		else 
		{
			Node *current= head;
			while(current->next !=NULL)
			{
				current=current->next;
			}
			current->next = newNode;
			//newNode->next=NULL;
		}
	}
    void add(int v)
    {
    	system("cls");
    	Node* newnode=new Node(v);
    	if (head==NULL)
    	{
    		head=newnode;
		}
		else 
		{
		Node* current=head;
		while(current->next !=NULL)	
		   {
			   current=current->next;
		   }
		   current->next=newnode;
		}
	}
	void deleteFirst()
	{
		system("cls");
		/*if(head=NULL)
		{
			return;
		}
		else*/
		{
			Node *temp=head;
			head=head->next;
			delete temp;
		}
	}
	void deleteLast()
	{
		Node *current =head;
		while(current->next->next !=NULL)
		{
			current = current->next;
		}
		current->next=NULL;
		delete current->next;
	}

	int countNodes()
	{
		system("cls");
		int count=0;
		Node *current=head;
		while(current!=NULL)
		{
			count++;
			current=current->next;
		}
		return count;
	}
	int Max()
	{
		system("cls");
		int max= head->value;
		Node *current=head->next;
		while(current!=NULL)
		{
			if(current->value>max)
			{
				max=current->value;
			}
			current=current->next;
		}
		return max;
	}
	int Average()
	{
		system("cls");
		if (head==NULL)
		{
			return 0.0;
		}
		else
		{
			Node *current =head;
			int sum=0;
			int count=0;
			double average=0.0;
			while (current !=NULL)
			{
				sum+=current->value;
				count++;
				current=current->next;
			}
			average=sum/count;
			return average;
		}
	}
	void reverse()
	{
		system("cls");
		Node *r;
		Node *p;
		Node *q;
		r=NULL;
		p=NULL;
		q=head;
		while (q)
		{
			r=p;
			p=q;
			q=q->next;
			p->next=r;
		}
		head=p;
	}
	bool detectLoop()
	{
		system("cls");
		if (head==NULL || head->next==NULL)
		{
			return false;
		}
		else 
		{
			Node *p;
			Node *q;
			while (q!=NULL && q->next!=NULL)
			{
				if (p==q)
				{
					return true;
				}
				p=p->next;
				q=q->next->next;
			}	
		} return false;
	}
	void isPolindrome()
	{
		system("cls");
		if (head==NULL || head->next==NULL)
		{
			cout<<"is polindrome"<<endl;
			return;
		}
		
		Node *slow=head;
		Node *fast=head;
		while(fast!=NULL && fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		
		Node *previous = NULL;
		Node *current = slow;
		Node *nextNode;
		while(current!=NULL)
		{
			nextNode=current->next;
			current->next=previous;
			previous=current;
		}
		Node *firstHalf =head;
		while(previous!=NULL &&firstHalf!=NULL)
		{
			if(firstHalf->value!=previous->value)
			{
				cout<<" not polindrome"<<endl;
				return;
			}
		    firstHalf=firstHalf->next;
			previous=previous->next;
		}
		cout<<"is polindrome"<<endl;
		return;
    }
    void insertAt(int key, int pos)
    {
    	 Node* temp=head;
    	 Node* new_node=new Node(key);
    	 new_node->value=key;
    	for(int i=0;i<pos-1;i++)
    	{
    		temp=temp->next;
		}
		new_node->next=temp->next;
		temp->next=new_node;
    }
    bool search(int key)
	{ 
	system ("cls");
		Node* temp=head;
	while(temp!=NULL)
		{
			if(temp->value==key)
			{
				cout<<"Yes! Element "<<key<<" is present."<<endl;
				return true;
				
			}
			else
			{
				temp=temp->next;
			}
		}
		cout<<"Sorry! Element "<<key<<" is not present. ";
		return false;
	}
	void display()
	{
		system("cls");
		if(head==NULL)
		{
			return;
		}
		else
		{
			Node* current= head;
			while(current!=NULL)
			{ 
			cout<<current->value<<"  ";
			current=current->next;
			}
			cout<<endl;
		}
	}

    
};
class DoublyLinkedList
{
    public:
       Node *head;
    DoublyLinkedList()
        {
           head = NULL;
        }
        
     void Menu()
    {
    	system("pause");
    	system("cls");
    	cout<<endl<<endl<<"=====================================    DOUBLY LINKEDLIST    ================================"<<endl<<endl;
    	cout<<"    1.ADD    "<<endl;
		cout<<"    2.addFirst    "<<endl;
    	cout<<"    3.addLAST    "<<endl;
    	cout<<"    4.deleteFirst    "<<endl;
    	cout<<"    5.deleteLast    "<<endl;
    	cout<<"    6.search    "<<endl;
    	cout<<"    7.countNodes    "<<endl;
    	cout<<"    8.max    "<<endl;
    	cout<<"    9.average    "<<endl;
    	cout<<"    10.reverse    "<<endl;
    	cout<<"    11.detectLoop    "<<endl;
    	cout<<"    12.insertAt    "<<endl;
    	cout<<"    13.display    "<<endl;
    	cout<<"    14.exit    "<<endl;
    	cout<<"    15.go back to page 1    "<<endl;
	}   
     void add(int v)
    {
    	system("cls");
    	Node* newnode=new Node(v);
    	if (head==NULL)
    	{
    		head=newnode;
		}
		else 
		{
		Node* temp=head;
		while(temp->next !=NULL)	
		   {
			   temp=temp->next;
		   }
		   temp->next=newnode;
		}
	}   
    void display()
    {
    	system("cls");
        Node *temp = head;
           while (temp != NULL)
        {
           cout << temp->value << "  ";
           temp = temp->next;
        }
    }
    void addFirst(int key) {
    	system("cls");
        Node* new_node = new Node(key); 
            if(head == NULL) {
                head = new_node;
            return;
        } 
        new_node->next = head; 
            if (head != NULL)
        {
            head->prev = new_node;
        } 
            head->prev = new_node;
            head = new_node;
    }
    
    void addLast(int key)
{
	system("cls");
    Node* temp = head;
    Node* new_node = new Node(key);

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
}

	void deleteFirst()
    {
    	system("cls");
           if (head == NULL)
        {
           return;
        }
          Node *temp = head;
          head = head->next;
          if (head != NULL)
        {
           head->prev = NULL;
        }
           delete temp;
    }
    
    void deleteLast()
	{
		system("cls");
		Node* temp=head;

	while(temp->next->next!=NULL)
	{

		temp=temp->next;
	}
	 	delete temp->next;
	    temp->next=NULL;
	   
	}
	
	void insertAt(int key, int pos)
    {
    	system("cls");
    	 Node* temp=head;
    	 Node* new_node=new Node(key);
    	 new_node->value=key;
    	for(int i=0;i<pos-1;i++)
    	{
    		temp=temp->next;
		}
		new_node->next=temp->next;
		new_node->prev=temp;
		temp->next=new_node;
		new_node->next->prev=new_node;
    }
   // void deleteNode(int key)
    bool search(int key)
	{ 
	system("cls");
		Node* temp=head;
	while(temp!=NULL)
		{
			if(temp->value==key)
			{
				cout<<"Yes! Element "<<key<<" is present."<<endl;
				return true;
				
			}
			else
			{
				temp=temp->next;
			}
		}
		cout<<"Sorry! Element "<<key<<" is not present. ";
		return false;
	}
	int countNodes()
	{
		system("cls");
		Node* temp=head;
		 int c=0;
	while(temp!=NULL)
	    {
		   c++;
		   temp=temp->next;
		}
		cout<<"Total Nodes : "<<c<<endl;
		return c;
	
	}
	int MaxValue()
	{
		system("cls");
		int max= head->value;
		Node *temp=head->next;
		while(temp!=NULL)
		{
			if(temp->value>max)
			{
				max=temp->value;
			}
			temp=temp->next;
		}
		cout<<" MaxValue is : "<<max<<endl;
		return max;
	}
	
    int Average()
	{
		system("cls");
		if (head==NULL)
		{
			return 0.0;
		}
		else
		{
			Node *temp =head;
			int sum=0;
			int count=0;
			double average=0.0;
			while (temp !=NULL)
			{
				sum+=temp->value;
				count++;
				temp=temp->next;
			}
			average=sum/count;
			cout<<" Average of no. "<<average<<endl;
			return average;
		}
	}
    void reverse()
	{
		system("cls");
		Node *r;
		Node *p;
		Node *q;
		r=NULL;
		p=NULL;
		q=head;
		while (q)
		{
			r=p;
			p=q;
			q=q->next;
			p->next=r;
		}
		head=p;
	}
    bool detectLoop()
    {
    	system("cls");
    	if(head==NULL)
    	{
    		return false;
		}
		else
		{
			Node *p = head;
			Node *q = head;
			while(q!=NULL&& q->next!=NULL)
			{
				p=p->next;
				q=q->next->next;
				if(p==q)
				{
					cout<<"Yes "<<endl;
					return true;
				}
			}
			cout<<"No ";
			return false;
		}
	}

    
};
class circularLinkedlist
{
public:
	Node *head;
	circularLinkedlist()
	{
		head=NULL;
    }
    void Menu()
    {
    	system("pause");
    	system("cls");
    	cout<<endl<<endl<<"=====================================    SINGLY CIRCULAR LINKEDLIST    ================================"<<endl<<endl;
    	cout<<"    1.ADD    "<<endl;
		cout<<"    2.addFirst    "<<endl;
    	cout<<"    3.addLAST    "<<endl;
    	cout<<"    4.deleteFirst    "<<endl;
    	cout<<"    5.deleteLast    "<<endl;
    	cout<<"    7.countNodes    "<<endl;
    	cout<<"    8.max    "<<endl;
    	cout<<"    9.average    "<<endl;
    	cout<<"    10.reverse    "<<endl;
    	cout<<"    11.detectLoop    "<<endl;
    	cout<<"    12.insertAt    "<<endl;
    	cout<<"    13.search    "<<endl;
    	cout<<"    14.display    "<<endl;
    	cout<<"    15. go to page 1    "<<endl;
	}
    void addFirst(int v)
    {
		system("cls");
		Node *newNode = new Node(v);
		if (head==NULL)
		{
			head=newNode;
			newNode->next=head;
		}
		else 
		{
			Node *current= head;
			while(current->next !=head)
			{
				current=current->next;
			}
			current->next = newNode;
			newNode->next=head;
			head=newNode;
		}
	}
	void addLast(int v)
	{
		system("cls");
		Node *newNode = new Node(v);
		if (head==NULL)
		{
			head=newNode;
			newNode->next=head;
		}
		else 
		{
			Node *current= head;
			while(current->next !=head)
			{
				current=current->next;
			}
			current->next = newNode;
			newNode->next=head;
		}
		newNode->next=head;
	}
    void add(int v)
    {
    	system("cls");
    	Node* newnode=new Node(v);
    	if (head==NULL)
    	{
    		head=newnode;
    		newnode->next=head;
		}
		else 
		{
		Node* current=head;
		while(current->next !=head)	
		   {
			   current=current->next;
		   }
		   current->next=newnode;
		   newnode->next=head;
		}
	}
	void deleteFirst()
	{
		system("cls");
		if(head==NULL)
		{
			return;
		}
			Node *temp=head;
			Node *t=head;
			while(t->next!=head)
			{
				t=t->next;
			}
			if(head->next==head)
			{
				delete head;
				head=NULL;
			}
			else
			{
			 t->next=head->next;;
			 head=head->next;
			 delete temp;
			}
	}
	void deleteLast()
	{
		Node *current =head;
		while(current->next->next !=head)
		{
			current = current->next;
		}
		Node* temp=current->next;;
		current->next=head;
		delete temp;
	}

	int countNodes()
	{
		system("cls");
		int count=0;
		Node *current=head;
		//while(current!=head)
		do{
			count++;
			current=current->next;
		}while(current!=head);
		return count;
	}
	int Max()
	{
		system("cls");
		int max= head->value;
		Node *current=head->next;
		while(current!=head)
		{
			if(current->value>max)
			{
				max=current->value;
			}
			current=current->next;
		}
		return max;
	}
	int Average()
	{
		system("cls");
		if (head==NULL)
		{
			return 0.0;
		}
		else
		{
			Node *current =head;
			int sum=0;
			int count=0;
			double average=0.0;
			do{
				sum+=current->value;
				count++;
				current=current->next;
			}while (current !=head);
			average=sum/count;
			return average;
		}
	}
	void reverse()
	{
		system("cls");
		Node *r;
		Node *p;
		Node *q;
		r=NULL;
		p=NULL;
		q=head;
		while (q)
		{
			r=p;
			p=q;
			q=q->next;
			p->next=r;
		}
		head=p;
	}
	bool detectLoop()
	{
		system("cls");
		if (head==NULL || head->next==NULL)
		{
			return false;
		}
		else 
		{
			Node *p=head;
			Node *q=head;
			while (q!=NULL && q->next!=NULL)
			{
				if (p==q)
				{
					return true;
				}
				p=p->next;
				q=q->next->next;
			}	
		} return false;
	}

    void insertAt(int key, int pos)
    {
    	 Node* temp=head;
    	 Node* new_node=new Node(key);
    	 new_node->value=key;
    	for(int i=0;i<pos-1;i++)
    	{
    		temp=temp->next;
		}
		new_node->next=temp->next;
		temp->next=new_node;
    }
    bool search(int key)
	{ 
	    system("cls");
		Node* temp=head;
		do{
			if(temp->value==key)
			{
				cout<<"Yes! Element "<<key<<" is present."<<endl;
				return true;
				
			}
			else
			{
				temp=temp->next;
			}
		}while(temp!=head);
		cout<<"Sorry! Element "<<key<<" is not present. ";
		return false;
	}
	void display()
	{
	
		system("cls");
		if(head==NULL)
		{
			return;
		}
		else
		{
			Node* current= head;
			//while(current!=head)
			do{ 
			cout<<current->value<<"  ";
			current=current->next;
			}while(current!=head);
			cout<<endl;
		}
	}
};
class Doubly_circulerLinkedList
{
    public:
       Node *head;
    Doubly_circulerLinkedList()
        {
           head = NULL;
        }
        
     void Menu()
    {
    	system("pause");
    	system ("cls");
    	cout<<endl<<endl<<"=====================================    DOUBLY LINKEDLIST    ================================"<<endl<<endl;
		cout<<"    1.addFirst    "<<endl;
    	cout<<"    2.addLAST    "<<endl;
    	cout<<"    3.deleteFirst    "<<endl;
    	cout<<"    4.deleteLast    "<<endl;
    	cout<<"    5.search    "<<endl;
    	cout<<"    6.countNodes    "<<endl;
    	cout<<"    7.max    "<<endl;
    	cout<<"    8.average    "<<endl;
    	cout<<"    9.reverse    "<<endl;
    	cout<<"    10.detectLoop    "<<endl;
    	cout<<"    11.insertAt    "<<endl;
    	cout<<"    12.go to page 1    "<<endl;
	}   
    void addFirst(int key) {
    	system("cls");
        Node* newnode = new Node(key); 
            if(head == NULL) {
                head = newnode;
                head->next=head;
                head->prev=head;
            
        } 
        else{
		 
        
        newnode->next=head;
        newnode->prev=head->prev;
        head->prev->next=newnode;
        head->prev=newnode;
        head=newnode;
    }
}
	 void addLast(int key)
{
	system("cls");
    Node* temp = head;
    Node* newnode = new Node(key);

     if(head == NULL) {
            head = newnode;
        	head->next=head;
            head->prev=head;
            
        } 
        else {
		
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    head->prev=newnode;
}
}
    void deleteFirst()
    {
    	system("cls");
           if (head == NULL)
        {
            return ;
        }
        Node* temp=head;
        if (temp->next!= head)
        {
        	head = head->next;
           head->prev = temp->prev;
           temp->prev->next=head;
        }
           delete temp;
       }
    void deleteLast()
	{
	//	Node* newnode= new Node()
		if(head==NULL)
		{
			return;
		 }
		 Node* temp =head->prev;
			if(temp!=head)
			{
			    temp->prev->next=head;
				head->prev=temp->prev;	
			}
		delete temp;
	}
    
	  bool search(int key)
	{ 
	    system("cls");
		Node* temp=head;
	while(temp!=head)
		{
			if(temp->value==key)
			{
				cout<<" Yes! Element "<<key<<" is present."<<endl;
				return true;
				
			}
			else
			{
				temp=temp->next;
			}
		}
		cout<<" Sorry! Element "<<key<<" is not present. "<<endl;
		return false;
	}
	int countNodes()
	{
		Node* temp=head;
		 int c=0;
	//while(temp->next!=head)
	do
	    {
		  c++;
		   temp=temp->next;
		}
		//c++;
	while(temp!=head);
		cout<<" Total Nodes : "<<c<<endl;
		return c;
	}
	int MaxValue()
	{
		system("cls");
		int max= head->value;
		Node *temp=head->next;
		while(temp!=head)
		{
			if(temp->value>max)
			{
				max=temp->value;
			}
			temp=temp->next;
		}
		cout<<" MaxValue is : "<<max<<endl;
		return max;
	}
	 double Average()
	{
		system("cls");
		if (head==NULL)
		{
			return 0.0;
		}
		else
		{
			Node *temp =head;
			int sum=0;
			int count=0;
			double average=0.0;
	
		do
			{
				sum+=temp->value;
				count++;
				temp=temp->next;
			}
			while (temp !=head);
			average=sum/count;
			
			cout<<" Average of no. "<<average<<endl;
			return average;
		}
	}
		void reverse()
	{
		system("cls");
		Node *r;
		Node *p;
		Node *q;
		r=head;
		p=head;
		q=head->next;
	do
		{
			r=p;
			p=q;
			q=q->next;
			p->next=r;
		}
		while (!q);
		head=p;
}
	 bool detectLoop()
    {
    	system("cls");
    	if(head==NULL)
    	{
    		return false;
		}
		else
		{
			Node *p = head;
			Node *q = head;
			while(q!=head&& q->next!=head)
			{
				p=p->next;
				q=q->next->next;
				if(p==q)
				{
					cout<<"Yes "<<endl;
					return true;
				}
			}
			cout<<"No ";
			return false;
		}
	}
void insertAt(int key, int pos)
    {
    	 Node* temp=head;
    	 Node* new_node=new Node(key);
    	 new_node->value=key;
    	for(int i=0;i<pos-1;i++)
    	{
    		temp=temp->next;
		}
		new_node->next=temp->next;
		new_node->prev=temp;
		temp->next=new_node;
		new_node->next->prev=new_node;
    }
    
    	void display()
	{
	
		system("cls");
		if(head==NULL)
		{
			return;
		}
		else
		{
			Node* temp= head;
			//while(current!=head)
			do{ 
			cout<<temp->value<<"  ";
			temp=temp->next;
			}while(temp!=head);
			cout<<endl;
		}
	}
};
int main()
{
	a:
	interFace();
	int select;
	cout<<"ENTER YOUR CHOICE "<<endl;
	cin>>select;
	switch (select)
	{
		case 1:
			{
			Linkedlist list;
	int choice;
	int value;
	int nodeCOUNT=0;
	int max=0;
	double average=0.0;
	bool detectLoop;
	bool isPolindrome;
c:
	list.Menu();
	cout<<endl<<"    ENTER YOUR CHOICE    "<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1:	
	   list.add(2);
	   list.add(4);
	   list.add(90);
	   list.add(8);
	   list.add(11);
	   list.add(5);
	   list.add(40);
	   list.add(30);
	   list.add(20);
	   list.add(11);
	   list.display();
	   cout<<"The elements are added"<<endl<<endl;
	   break;
	case 2:
		int v;
		cout<<"enter number to add"<<endl;
		cin>>v;
	   list.addFirst(v);
	   //cout<<"  added at first"<<endl;
	   list.display();
	   cout<<v<<" is added at first"<<endl<<endl;
	   break;
	case 3:
	   int val;
	   cout<<"enter number to add"<<endl;
		cin>>val;
	   list.addLast(val);
	   list.display();
	   cout<<val<<" is added at last"<<endl<<endl;
	   break;
	case 4:
	  list.deleteFirst();
	  cout<<"after deleted "<<endl;
	  list.display();
   	  break;  
	case 5:
	   list.deleteLast();
	   list.display(); 
       break;
	case 6:
		nodeCOUNT=list.countNodes();
		cout<<" number of nodes="<<nodeCOUNT<<endl;
		cin.get();
		break;
	case 7:
		max=list.Max();
		list.display();
		cout<<"max value="<<max<<endl;
		break;
	case 8:
	      	average=list.Average();
	      	cout<<" average="<<average<<endl;
	      	break;
	case 9:
		cout<<"reverse is:"<<endl;
	    list.reverse();
	    list.display();
		break; 
	case 10:
	    detectLoop=list.detectLoop(); 
		if(detectLoop)  
		{
			cout<<"yes it has loop"<<endl;
		}
		else
		{
			cout<<"it does not have loop"<<endl;
		}
		break;  
	case 11:
	    list.isPolindrome(); 
		/*if(isPolindrome)  
		{
			cout<<"the list is polindrome"<<endl;
		}
		else
		{
			cout<<"the list is not polindrome"<<endl;
		}
		list.display();*/
		break; 
	case 12:
		int location;
		int value;
		cout<<" enter number to insert"<<endl;
		cin>>value;
		cout<<" at which location do you want to insert"<<endl;
		cin>>location;
	    list.insertAt(value,location);
	    list.display();
	    cout<<value<<" is inserted at location "<<location<<endl<<endl;
		break; 
	case 13:
		int num;
		cout<<"enter number to search"<<endl;
		cin>>num;
	    list.search(num);
		break;		
	case 14:
	    list.display();
		cin.get();
		break;	
	case 15:
	   exit(0);
	case 16:
	   goto a;
	default:
	    cout<<" wrong choice "<<endl;
	    break;
   }
   getchar();
   goto c;
			break;
		}
		//////////
		case 2:
			{
		    DoublyLinkedList List2;
int choic;
v:
List2.Menu();
cout<<"\nEnter your choice ";
cin>>choic;
switch (choic)
{

	case 1:
		List2.add(10);
		List2.add(20);
		List2.add(30);
		List2.add(40);
		List2.add(50);
		List2.add(2);
	    List2.add(4);
	    List2.add(90);
	    List2.add(8);
	    List2.add(11);
		List2.display();
		cout<<"\n elements are are added in linkedlist"<<endl;
	break;
	case 2:
		int v;
		cout<<"enter number to add at 1st"<<endl;
		cin>>v;
		List2.addFirst(v);
		List2.display();
		cout<<"\n"<<v<<" is added at 1st"<<endl<<endl;
	break;
	case 3:
		int val;
		cout<<"\n enter number to add"<<endl;
		cin>>val;
		List2.addLast(val);
		List2.display();
		cout<<endl<<val<<" is added at last"<<endl<<endl;
	break;
	case 4:
		List2.deleteFirst();
		List2.display();
	break;
	case 5:
		List2.deleteLast();
		List2.display();
	break;
	case 6:
		int value;
		cout<<"enter number to search"<<endl;
		cin>>value;
		List2.search(value);
		List2.display();	
	break;
	case 7:
		List2.countNodes();
		List2.display();
	break;
	case 8:
		List2.MaxValue();
		List2.display();
	break;
	case 9:
		List2.Average();
		List2.display();
	break;
	case 10:
		List2.reverse();
		List2.display();
	break;
	case 11:	
		List2.detectLoop();
		List2.display();
	break;
	case 12:
		int position;
		int number;
		cout<<"enter number to insert"<<endl;
		cin>>number;
		cout<<" at what location do you want to add"<<endl;
		cin>>position;
		List2.insertAt(number,position);
		List2.display();
		cout<<"\n"<<number<<" is inserted at "<<position<<endl<<endl;
	break;
    case 13:	
		List2.display();
	break;
	case 14:
	   exit(0);
	case 15:
	   goto a;
	default:
		cout<<" You enter wrong choice "<<endl;
	break;
	}
	getchar();
	goto v;
			break;
		}
		case 3:
			{
				circularLinkedlist list;
	int choice;
	int value;
	int nodeCOUNT=0;
	int max=0;
	double average=0.0;
	bool detectLoop;
	bool isPolindrome;
m:
	list.Menu();
	cout<<endl<<"    ENTER YOUR CHOICE    "<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1:	
	   list.add(2);
	   list.add(4);
	   list.add(6);
	   list.add(8);
	   list.add(11);
	   list.display();
	   cout<<" Elements are added in LinedList"<<endl<<endl;
	   break;
	case 2:
		int val;
		cout<<"enter number to add at 1st"<<endl;
		cin>>val;
	   list.addFirst(val);
	   cout<<"  added at first"<<endl;
	   list.display();
	   cout<<endl<<val<<" is added at first"<<endl;
	   break;
	case 3:
	   int v;
		cout<<"enter number to add at 1st"<<endl;
		cin>>v;
	   list.addLast(v);
	   list.display();
	   cout<<endl<<v<<" added at last "<<endl;
	   break;
	case 4:
	  list.deleteFirst();
	  list.display();
	  cout<<" THE 1ST ELEMENT IS DELETED FROM LINKEDLIST "<<endl<<endl;
   	  break;  
	case 5:
	   list.deleteLast();
	   list.display(); 
	   cout<<" THE LAST ELEMENT IS DELETED FROM LINKEDLIST "<<endl<<endl;
       break;
	case 7:
		nodeCOUNT=list.countNodes();
		cout<<" number of nodes="<<nodeCOUNT<<endl;
		cin.get();
		break;
	case 8:
		max=list.Max();
		list.display();
		cout<<" THE MAXIMUM VALUE IS ="<<max<<endl;
		break;
	case 9:
	      	average=list.Average();
	      	cout<<" AVERAGE IS ="<<average<<endl<<endl;
	      	break;
	case 10:
	    list.reverse();
	    list.display();
	    cout<<" THE LINKED LIST IS REVERSED "<<endl<<endl;
		break; 
	case 11:
	    detectLoop=list.detectLoop(); 
		if(detectLoop)  
		{
			cout<<"YES LINKED LIST HAS LOOP "<<endl<<endl;
		}
		else
		{
			cout<<"LINKED LIST DOES NOT HAVE LOOP "<<endl;
		}
		break;  
	case 12:
		int position;
		int n;
		cout<<" enter number to insert "<<endl;
		cin>>n;
		cout<<"at what position do you want to insert "<<endl;
		cin>>position;
	    list.insertAt(n,position);
	    list.display();
	    cout<<n<<" IS INSERTED AT "<<position<<endl<<endl;
		break; 
	case 13:
		int value;
		cout<<"enter number to search"<<endl;
		cin>>value;
	    list.search(value);
		break;		
	case 14:
	    list.display();
		cin.get();
		break;
	case 15:
	{
		goto a;
		}	
	default:
	    cout<<" wrong choice "<<endl;
	    break;
   }
   getchar();
   goto m;
				break;
			}
		case 4:
			{
				Doubly_circulerLinkedList List3;
int choice;
do{
List3.Menu();
cout<<"\nEnter your choice ";
cin>>choice;
switch (choice)
{

	case 1:
			int v;
		cout<<"enter number to add at 1st"<<endl;
		cin>>v;
		List3.addFirst(v);
		List3.display();
		cout<<"\n"<<v<<" is added at 1st"<<endl<<endl;
		
	break;
	case 2:
	int val;
		cout<<"\n enter number to add"<<endl;
		cin>>val;
		List3.addLast(val);
		List3.display();
		cout<<endl<<val<<" is added at last"<<endl<<endl;
	break;
	case 3:
		List3.deleteFirst();
	break;
	case 4:
		List3.deleteLast();
	break;
	case 5:
		int value;
		cout<<"enter number to search"<<endl;
		cin>>value;
		List3.search(value);
		List3.display();	
	break;
	case 6:
		List3.countNodes();
	break;
	case 7:
		List3.MaxValue();
	break;
	case 8:
		List3.Average();
	break;
	case 9:
		List3.reverse();
	break;
	case 10:	
		List3.detectLoop();
	break;
	case 11:
		int position;
		int number;
		cout<<"enter number to insert"<<endl;
		cin>>number;
		cout<<" at what location do you want to add"<<endl;
		cin>>position;
		List3.insertAt(number,position);
		List3.display();
		cout<<"\n"<<number<<" is inserted at "<<position<<endl<<endl;

	break;
	case 12:
		{
			goto a;
		}
	default:
		cout<<" You enter wrong choice "<<endl;
	break;
	}
       }
while(choice!=0);

			}
			
		case 5:
			exit(0);
		default:
	    cout<<" wrong choice "<<endl;
	    break;	
	}
	goto a;
	
return 0;
}
