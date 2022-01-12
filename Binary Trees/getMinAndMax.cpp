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
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        pair<int,int> p;
        p.first = p.second = root->data;
        return p;
    }
    pair<int,int> ans;
    ans.first = ans.second =  root->data;
	if(root->left){
        pair<int,int> leftAns = getMinAndMax(root->left);
        ans.first = min(ans.first,leftAns.first);
        ans.second = max(ans.second,leftAns.second);
    }
    	
    if(root->right){
		pair<int,int> rightAns = getMinAndMax(root->right);
        ans.first = min(ans.first,rightAns.first);
    	ans.second = max(ans.second,rightAns.second);
    }
    return ans;
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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}