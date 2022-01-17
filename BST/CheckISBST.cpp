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
//Approach 1
/*
#include<climits>
int minimum(BinaryTreeNode<int> *root){
    if(root==NULL) return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root){
    if(root==NULL) return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL) return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
	return (root->data > leftMax) && (root-> data < rightMin) && isBST(root->left) && isBST(root->right);	
}
*/
// Approach 2
/*
#include<climits>
class ISBSTReturn{
    public:
    	int minimum;
    	int maximum;
    	bool isBST;
};
ISBSTReturn isBSTHelper(BinaryTreeNode<int> * root){
    if(root == NULL){
        ISBSTReturn obj;
        obj.maximum = INT_MIN;
        obj.minimum = INT_MAX;
        obj.isBST = true;
        return obj;
    }
    ISBSTReturn leftOutput = isBSTHelper(root->left);
    ISBSTReturn rightOutput = isBSTHelper(root->right);
    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(rightOutput.maximum,rightOutput.maximum));
    bool finalISBST = root->data > leftOutput.maximum && root->data < rightOutput.minimum && leftOutput.isBST
        && rightOutput.isBST;
    ISBSTReturn output;
    output.maximum = maximum;
    output.minimum = minimum;
    output.isBST = finalISBST;
    return output;
        
}
bool isBST(BinaryTreeNode<int> *root){
    return isBSTHelper(root).isBST;
}*/
//Approach 3 Top-down
#include<climits>
bool isBSTHelper(BinaryTreeNode<int> *root,int min = INT_MIN,int max = INT_MAX){
    if(root == NULL) return true;
    if(root->data < min || root->data > max) return false;
    bool isleftOk = isBSTHelper(root->left,min,root->data-1);
    bool isrightOk = isBSTHelper(root->right,root->data,max);
	return isleftOk && isrightOk;
}
bool isBST(BinaryTreeNode<int> *root){
    return isBSTHelper(root);
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
    cout << (isBST(root) ? "true" : "false");
}