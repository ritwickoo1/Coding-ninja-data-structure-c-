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
/* Method 1 O(n^2)
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallAns = reverseLinkedListRec(head->next);
    Node *temp = smallAns;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next= head;
    head->next = NULL;
    return smallAns;
}
*/
/* Method 2 O(n^2)
class Pair{
    public:
    	Node *head;
    	Node *tail;
};
Pair reverseLL(Node *head){
    if(head == NULL || head->next==NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverseLL(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    return reverseLL(head).head;
}
*/
// Method 3 Best
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallAns = reverseLinkedListRec(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
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

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}