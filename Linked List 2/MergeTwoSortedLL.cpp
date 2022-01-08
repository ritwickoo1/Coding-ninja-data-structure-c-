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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL && head2 == NULL){
        return head1;
    }else if(head1==NULL && head2!=NULL){
        return head2;
    }else if(head1!=NULL && head2==NULL){
        return head1;
    }
    Node *ft = NULL;
    Node *fh = NULL;
	Node *h1 = head1;
    Node *h2 = head2;
    while(h1!=NULL && h2!=NULL){
        if(h1->data > h2->data){
            if(fh==NULL){
            	ft = fh = h2;
            	h2 = h2->next;
            }else{
                ft->next = h2;
                h2 = h2->next;
                ft = ft->next;
            }
        }else{
            if(fh==NULL){
            	ft = fh = h1;
            	h1 = h1->next;
            }else{
                ft->next = h1;
                h1 = h1->next;
                ft = ft->next;
            }
        }
        
    }
    while(h1!=NULL){
        ft->next = h1;
        h1 = h1->next;
        ft = ft->next;
    }
    while(h2!=NULL){
        ft->next = h2;
        h2 = h2->next;
    	ft = ft->next;
    }
    return fh;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}