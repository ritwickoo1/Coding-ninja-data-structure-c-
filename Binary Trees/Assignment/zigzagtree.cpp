#include <iostream>
#include <queue>

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
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL) return;
    stack<BinaryTreeNode<int> *> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        cout<<s1.top()->data<<" ";
        if(s1.top()->left)
        	s2.push(s1.top()->left);
        if(s1.top()->right)
        	s2.push(s1.top()->right);
        s1.pop();
        if(s1.empty()){ 
            cout<<endl;
            while(!s2.empty()){
                cout<<s2.top()->data<<" ";
                if(s2.top()->right)
                    s1.push(s2.top()->right);
                if(s2.top()->left)
                    s1.push(s2.top()->left);
                s2.pop();
            }
            cout<<endl;
        }
        
    }
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
    zigZagOrder(root);
}