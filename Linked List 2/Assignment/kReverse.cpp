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
class Pair{
    public:
    	Node *head;
    	Node *tail;
};
Pair reverse(Node *head){
    if(head==NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverse(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head==NULL) return head;
    int count = 1;
    Node *h1 = head;
    Node *t1 = head;
    while(count < k && t1->next){
        t1 = t1->next;
        count++;
    }
    Node *h2 = t1->next;
    t1->next = NULL;
    Pair smallAns = reverse(h1);
    h2 = kReverse(h2,k);
    smallAns.tail->next = h2;
   	return smallAns.head; 
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}