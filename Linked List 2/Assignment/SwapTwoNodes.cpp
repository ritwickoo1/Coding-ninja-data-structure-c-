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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head==NULL|| head->next==NULL ||(i==j)){
        return head;
    }else if(i > j){
        int temp = i;
        i = j;
        j = temp;
    }
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *c1 = head;
    Node *c2 = head;
    int count1 = 0, count2 = 0;
    while(count1 < i && c1!=NULL){
        p1 = c1;
        c1 = c1->next;
        count1++;
    }
    while(count2 < j && c2!=NULL){
        p2 = c2;
        c2 = c2->next;
        count2++;
    }
    if(c1==NULL || c2 == NULL) return head;
    //cout<<p2->data<<endl;
    if(i==0){
		//Node *temp = c2->next;
        p2->next = c1;
        Node *temp = c1->next;
        //c2->next = c1->next;
        c1->next = c2->next;
        c2->next = temp;
        head = c2;
    }else if(j-i==1){
    	p1->next = c2;
        c1->next = c2->next;
        c2->next = p2;
    }else if((i==0) && (j-i==1) ){
        c1->next = c2->next;
        c2->next = p2;
        head = c2;
    }else{
        p1->next = c2;
        p2->next = c1;
        Node *temp = c1->next;
        c1->next = c2->next;
        c2->next = temp;
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}