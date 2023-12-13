#include<iostream>
using namespace std;
struct node{
	public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};
void insertAtHead(node* &head,int val)
{
	node* n=new node(val);
	if(head==NULL){
		n->next=n;
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	head=n;
}
void insertAtEnd(node* &head,int val)
{
	if(head==NULL)
	{
		insertAtHead(head,val);
		return;
	}
	node* n=new node(val);
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
}
void deletion(node* &head,int pos)
{
	node* temp=head;
	int count=1;
	while(count!=pos-1){
		temp=temp->next;
		count++;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}
void display(node* head)
{
	node* temp=head;
	do{
		cout<<temp->data<<"->";
		temp=temp->next;
	}while(temp!=head);
	cout<<"NULL"<<endl;
}
int main()
{
	int e,f,d;
	node* head=NULL;
	insertAtEnd(head,1);
	insertAtEnd(head,2);
	insertAtEnd(head,3);
	insertAtEnd(head,4);
	display(head);
	cout<<"Enter node insert at end =";
	cin>>e;
	insertAtEnd(head,e);
	display(head);
	cout<<"Enter node to insert at front =";
	cin>>f;
	insertAtHead(head,f);
	display(head);
	cout<<"Enter node position to delete =";
	cin>>d;
	deletion(head,d);
	display(head);
	return 0;
}
