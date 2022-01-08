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
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
Node *reverseSLL(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallAns = reverseSLL(head->next);
    Node *temp = smallAns;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}
Node *middle(Node *head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node *head)
{
    //Write your code here
   	if(head==NULL || head->next==NULL){
        return true;
    }
    Node* mid = middle(head);
    Node *h1 = head;
    Node *temp = h1;
    Node *h2 = NULL;
    if(len(head)%2==0){
        while(temp!=mid){
            temp = temp->next;
        }
        h2 = temp->next;
    }else{
         while(temp->next!=mid){
            temp = temp->next;
        }
        h2 = temp->next->next;
    }
    temp->next = NULL;
    if(len(h1)!=len(h2)) return false;
    h1 = reverseSLL(h1);
    while(h1!=NULL && h2!=NULL){
        if(h1->data != h2->data){
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}