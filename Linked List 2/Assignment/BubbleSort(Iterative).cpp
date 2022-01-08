//bubble sort iterative
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

int len(Node *head){
	if(head!=NULL) return 0;
	return 1 + len(head->next);
}
Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head==NULL || head->next==NULL) return head;
    for(int i = 0; i < len(head)-1; i++){
    	Node *prev = NULL;
    	Node *curr = head;
    	Node *future = curr->next;
    	while(curr->next!=NULL){
       		if(curr->data > curr->next->data){
                if(prev==NULL){
                    curr->next = future->next;
                    future->next = curr;
                    prev = future;
                    head = prev;
                }else{
                    future = curr->next;
                    curr->next = future->next;
                    prev->next = future;
                    future->next = curr;
                    prev = future;
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}