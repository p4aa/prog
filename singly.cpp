#include<iostream>
using namespace std;
struct Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data=val;
			next=NULL;
		}
};
void insertAtTail(Node* &head,int val)
{
	Node* n=new Node(val);
	if(head==NULL){
		head=n;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
int count(Node* head)
{
	int count=0;
	Node* temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	cout<<"Size of List is ="<<count<<endl;
	return 0;
}
void deletion(Node* &head,int val)
{
	Node* temp=head;
	while(temp->next->data!=val){
		temp=temp->next;
	}
	Node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}
Node* reverse(Node* &head)
{
	Node* prev=NULL;
	Node* curr=head;
	Node* nextptr;
	while(curr!=NULL){
		nextptr=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextptr;
	}
	return prev;
}
void search(Node* head,int key)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			cout<<"Entered key found"<<endl;
		}
		temp=temp->next;
	}
}
void display(Node* head)
{
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
int main()
{
	Node* head=NULL;
	int x,n,key;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	display(head);
	cout<<"Enter new value for insertion =";
	cin>>x;
	insertAtTail(head,x);
	cout<<"Vale Insertion at tail:"<<endl;
	display(head);
	count(head);
	cout<<"Enter Key to search ="<<endl;
	cin>>key;
	search(head,key);
	cout<<"Enter value for Delete ="<<endl;
	cin>>n;
	deletion(head,n);
	cout<<"Vale Deletion:"<<endl;
	display(head);
	cout<<"Reverse Linked List:"<<endl;
	Node* newhead=reverse(head);
	display(newhead);
	
	return 0;	
}
