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
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head==NULL||N==0 || N<0) return head;
    else if(M==0||M<0) return NULL;
    Node *t1 = head;
    Node *t2 = NULL;
    Node *temp = head;
	int c1 = 1;
    int c2 = 1;
    while(t1!=NULL && t1->next!=NULL){
        while(c1 < M && t1!=NULL){
            t1 = t1->next;
            c1++;
        }
        t2 = t1->next;
        while(c2 <= N && t2!=NULL){
            Node *p = t2;
            t2 = t2->next;
            delete p;
            c2++;
        }
        c1 = c2 = 1;
        t1->next = t2;
        t1  = t1->next;
    }
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}