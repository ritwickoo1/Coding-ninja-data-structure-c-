#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

// Approach 1
/*
class Custom{
  public:
    TreeNode<int> * max;
    TreeNode<int> * smax;
    Custom(TreeNode<int> *max,TreeNode<int> * smax){
        this->max = max;
        this->smax = smax;
    }
};
Custom getSecondLargestNodeHelper(TreeNode<int> *root){
    //Edge Case
    if(root == NULL){
        Custom r(NULL,NULL);
        return r;
    }
    Custom parent(root,NULL);
    for(int i = 0; i < root->children.size(); i++){
        Custom child = getSecondLargestNodeHelper(root->children[i]);
        if(child.max->data > parent.max->data){
            if(child.smax == NULL){
                parent.smax = parent.max;
                parent.max = child.max;
            }else{
                if(child.smax->data > parent.max->data){
                    parent.smax = child.smax;
                    parent.max = child.max;
                    
                }else{
                    parent.smax = parent.max;
                    parent.max = child.max;
                }
            }
        }else{
            if(parent.max->data!= child.max->data && (parent.smax == NULL || child.max->data > parent.smax->data)){
                parent.smax = child.max;
            }
        }
    }
    return parent;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) return root;
    Custom ans = getSecondLargestNodeHelper(root);
    return ans.smax;
}
*/
// Approach 2 easy way
void getSecondLargestNodeHelper(TreeNode<int> *root,TreeNode<int>** largest,TreeNode<int>** secondLargest){
    if(root == NULL) return;
    if(!(*largest)) *largest = root;
    else if(root->data > (*largest)->data){
        (*secondLargest) = (*largest);
        (*largest) = root;
    }else if(!(*secondLargest) || ((root->data) > (*secondLargest)->data)){
        (*secondLargest) = root;
    }
    for(int i = 0; i < root->children.size();i++){
        getSecondLargestNodeHelper(root->children[i],largest,secondLargest);
    }
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root){
    if(root==NULL) return root;
    TreeNode<int> * largest = NULL;
    TreeNode<int> * secondLargest = NULL;
    getSecondLargestNodeHelper(root,&largest,&secondLargest);
	if(secondLargest == NULL) return NULL;
    if(largest->data == secondLargest->data) return NULL;
    return secondLargest;
}
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
