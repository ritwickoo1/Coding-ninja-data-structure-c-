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
15
*/
/* Approach 1 O(n^2) 
#include<climits>
bool check(BinaryTreeNode<int> *root, int sum){

	if(root==NULL) return false;
	if(root->data == sum) {
		root->data = INT_MIN;
		return true;	
	}
	return check(root->left,sum) || check(root->right,sum);
}
void pairSum(BinaryTreeNode<int> *curr, int sum,BinaryTreeNode<int> *root){
	if(curr == NULL) return;
	if(curr->data != INT_MIN){
		if(check(root,(sum-curr->data))){
			if(curr->data <sum-curr->data && curr->data > 0&&sum-curr->data > 0)
			cout<<curr->data<<" "<<sum-curr->data<<endl;
			else if(curr->data >sum-curr->data && curr->data > 0&&sum-curr->data > 0)
			cout<<sum-curr->data<<" "<<curr->data<<endl;
			curr->data = INT_MIN;
		}
	}
	pairSum(curr->left, sum, root);
	pairSum(curr->right, sum, root);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
	pairSum(root,sum,root);
}
*/
#include<algorithm>
void convertTreeToArray(BinaryTreeNode<int> * root,vector<int> &arr){
	if(root==NULL) return;
	arr.push_back(root->data);
	convertTreeToArray(root->left,arr);
	convertTreeToArray(root->right,arr);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
	vector<int> arr;
	convertTreeToArray(root,arr);
	sort(arr.begin(),arr.end());
	int i = 0;
	int j = arr.size()-1;
	while(i < j){
		if(arr[i]+arr[j]==sum){
			cout<<arr[i]<<" "<<arr[j]<<endl;
			i++;
			j--;
		}else if(arr[i]+arr[j] > sum){
			j--;
		}else{
			i++;
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}