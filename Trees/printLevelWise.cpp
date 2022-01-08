#include <iostream>
#include <vector>
#include <queue>
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
void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return;
    
    queue<TreeNode<int>*> childs;
    childs.push(root);
    
    while(!childs.empty()){
        TreeNode<int> *child = childs.front();
        childs.pop();
        int n = child->children.size();
        cout<<child->data<<":";
        for(int i = 0; i < n; i++){
            cout<<child->children[i]->data;
            if(i<n-1){
                cout<<",";
            }
            childs.push(child->children[i]);
        }
        cout<<endl;
        
    }
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
    printLevelWise(root);
}