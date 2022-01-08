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

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if(head==NULL || head->next==NULL) return head;
    Node *temp = head;
    Node *even = NULL;
    Node *odd = NULL;
    Node *oddHead = NULL;
    Node *evenHead = NULL;
    while(temp!=NULL){
        if(temp->data%2){
            if(odd==NULL){
                odd = oddHead = temp;
            }else{
                odd->next = temp;
                odd = temp;
            }
        }else{
            if(even==NULL){
                even = evenHead = temp;
            }else{
                even->next = temp;
                even = temp;
            }
        }
        temp = temp->next;
    }
    if(odd!=NULL && even!=NULL){
        odd->next = evenHead;
        even->next = NULL;
        return oddHead;
    }else if(even==NULL){
        odd->next = NULL;
        return oddHead;
    }else{
        even->next = NULL;
        return evenHead;
    }
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}