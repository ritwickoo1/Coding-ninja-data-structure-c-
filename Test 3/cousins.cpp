#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
int level(BinaryTreeNode<int> *root,int node,int lev){
    if(root==NULL) return 0;
    if(root->data == node) return lev;
    int left = level(root->left,node,lev+1);
    if(left!=0) return 1;
    else return level(root->right,node,lev+1);
}
bool isSibling(BinaryTreeNode<int> *root,int p,int  q){
    if(root==NULL) return false;
    if(root->right && root->left){
        if(root->right->data == p && root->left->data == q||root->right->data == q && root->left->data == p){
            return true;
        }
    }
    return isSibling(root->left,p,q) || isSibling(root->right,p,q);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
	if(root==NULL) return false;
    return ((level(root,p,0))==(level(root,q,0))&& !isSibling(root,p,q));
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
