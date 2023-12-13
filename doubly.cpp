#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prev;
};
Node* head1=NULL;
Node* head2=NULL;
void insert(Node* &head, int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(!head){
		head=temp;
	}
	else{
		Node* ptr=head;
		while(ptr->next){
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	}
}
void insertAtTail(Node* &head,int data)
{
	Node* n=new Node();
	n->data=data;
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
}
void deletion(Node* &head,int data)
{
	Node* temp=head;
	int count=1;
	while(temp!=NULL && count!=data){
		temp=temp->next;
		count++;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL)
	{
		temp->next->prev=temp->prev;
	}
	delete temp;
}
void sort(Node* &head)
{
	Node* ptr=head;
	while(ptr->next){
		Node* temp=ptr->next;
		while(temp){
			if(ptr->data > temp->data){
				swap(ptr->data,temp->data);
			}
			temp=temp->next;
		}
		ptr=ptr->next;
	}
}
void merge()
{
	Node* ptr1=head1;
	Node* ptr2=head2;
	while(ptr1->next){
		ptr1=ptr1->next;
	}
	ptr1->next=ptr2;
	ptr2->prev=ptr1;
}
void display(Node* head)
{
	Node* ptr=head;
	while(ptr){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
}
int main()
{
	int n,d;
	cout<<"First Doubly linked List ::"<<endl;
	insert(head1,2);
	insert(head1,1);
	insert(head1,4);
	insert(head1,3);
	display(head1);
	cout<<"First Sorted List::"<<endl;
	sort(head1);
	display(head1);
	cout<<"Secong Doubly linked list::"<<endl;
	insert(head2,8);
	insert(head2,6);
	insert(head2,5);
	insert(head2,7);
	display(head2);
	cout<<"second Sorted List::"<<endl;
	sort(head2);
	display(head2);
	cout<<"*****Merge Lists are*****"<<endl;
	merge();
	display(head1);
	cout<<"Enter the new value to insert at tail =";
	cin>>n;
	insertAtTail(head1,n);
	display(head1);
	cout<<"Enter element to delete =";
	cin>>d;
	deletion(head1,d);
	display(head1);
	return 0;
}
