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
/*
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
*/
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
	if(root==NULL) return -1;
    if(root->data == a || root->data == b){
        return root->data;
    }
    int leftLCA = getLCA(root->left,a,b);
    int rightLCA = getLCA(root->right,a,b);
    if(leftLCA!=-1 && rightLCA==-1){
        return leftLCA;
    }else if(leftLCA==-1 && rightLCA!=-1){
        return rightLCA;
    }else if(leftLCA!=-1 && rightLCA!=-1){
        return root->data;
    }else{
    	return -1;
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}