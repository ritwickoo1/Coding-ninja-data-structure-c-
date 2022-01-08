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

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(pos<0){
        return head;
    }else if(pos==0 && head!=NULL){
        Node *p = head;
        head = head->next;
        delete p;
    }else{
        Node *temp = head;
        int count = 0;
        while(temp!=NULL && count < pos-1){
            temp = temp->next;
            count++;
        }
        if(temp!=NULL && temp->next!=NULL){
            Node *p = temp->next;
            temp->next = p->next;
            delete p;
        }
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
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}