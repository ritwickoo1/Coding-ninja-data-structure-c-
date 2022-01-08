#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *middle(Node *head){
    if(head==NULL) return head;
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int len(Node *head){
    if(head==NULL) return 0;
    return 1+len(head->next);
}
Node *mergeSortedList(Node *head1,Node *head2){
    if(head1==NULL && head2 == NULL){
        return head1;
    }else if(head1==NULL && head2!=NULL){
        return head2;
    }else if(head1!=NULL && head2==NULL){
        return head1;
    }
    Node *fH = NULL;
    Node *fT = NULL;
    Node *h1 = head1;
    Node *h2 = head2;
    while(h1!=NULL && h2!=NULL){
        if(h1->data < h2->data){
            if(fH==NULL){
                fH = fT = h1;
                h1 = h1 -> next;
            }else{
                fT->next = h1;
                h1 = h1 -> next;
                fT = fT -> next;
            }
        }else{
            if(fH==NULL){
                fH = fT = h2;
                h2 = h2 -> next;
            }else{
                fT->next = h2;
                h2 = h2 -> next;
                fT = fT -> next;
            }
        }
    }
    while(h1!=NULL){
        fT->next = h1;
        h1 = h1 -> next;
        fT = fT -> next;
    }
    while(h2!=NULL){
        fT->next = h2;
        h2 = h2 -> next;
        fT = fT -> next;
    }
    return fH;
}
Node *mergeSort(Node *head)
{
	//Write your code here
    if(len(head)==0 || len(head)==1 ){
        return head;
    }
    Node *h1 = head;
    Node *mid = middle(head);
	Node *h2 = mid->next;
    mid->next = NULL;
    Node *newHead1 = mergeSort(h1);
    Node *newHead2 = mergeSort(h2);
    return mergeSortedList(newHead1,newHead2);
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}