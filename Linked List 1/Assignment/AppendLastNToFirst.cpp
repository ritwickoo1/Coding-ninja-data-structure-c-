#include <iostream>
// 1 2 3 4 5 -1
//3
//3 4 5 1 2
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
int len(Node *head){
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    int size = len(head);
    int s = size-n;
    Node* temp = head;
    int i = 0;
    if(s==0||s==size|| n< 0|| n > size){
        return head;
    }
    while(i < s-1){
        temp = temp->next;
        i++;
    }
    Node *newhead = temp->next;
    temp->next = NULL;
    Node *p = newhead;
    while(p->next!=NULL){
        p = p -> next;
    }
    p->next = head;
    head = newhead;
    return head;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}