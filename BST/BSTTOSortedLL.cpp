#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
class Pair{
	public:
		Node<int> *head;
		Node<int> *tail;
};
Pair LinkedList(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair p;
        p.head = NULL;
        p.tail = NULL;
        return p;
    }
    Node<int> *node = new Node<int>(root->data);
    Pair lNodeAns = LinkedList(root->left);
    Pair rNodeAns = LinkedList(root->right);
    Pair ans;
	if(!lNodeAns.head && !rNodeAns.head){
    	ans.head = node;
    	ans.tail = node;
	}else if(lNodeAns.head && !rNodeAns.head){
		ans.head = lNodeAns.head;
		lNodeAns.tail->next = node;
		ans.tail = node;
	}else if(!lNodeAns.head && rNodeAns.head){
		ans.head = node;
		node->next = rNodeAns.head;
		ans.tail = rNodeAns.tail;
	}else{
		ans.head = lNodeAns.head;
		lNodeAns.tail->next = node;
		node->next = rNodeAns.head; 
		ans.tail = rNodeAns.tail;
	}
	return ans;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return LinkedList(root).head;
}
BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}