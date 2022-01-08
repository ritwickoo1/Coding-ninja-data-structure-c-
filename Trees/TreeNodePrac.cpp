#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
	
		TreeNode(T data){
			this->data = data;
		}
		~TreeNode(){
			for(int i = 0; i < children.size();i++){
				delete children[i];
			}
		}
				
};
TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root data: ";
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		TreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout<<"Enter number of childs of "<<front->data<<endl;
		cin >> numChild;
		for(int i = 0; i < numChild; i ++){
			int childData;
			cout<<"Enter "<<i<<"th child Data: ";
			cin >> childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
TreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
void printLevelWise(TreeNode<int>* root){
	queue<TreeNode<int>*> childs;
	childs.push(root);
	while(!childs.empty()){
		TreeNode<int> *childNode = childs.front();
		childs.pop();
		cout<<childNode->data<<":";
		int n = childNode->children.size();
		for(int i = 0; i < n; i++){
			cout<<childNode->children[i]->data;
			if(i < n-1)
			cout<<",";
			childs.push(childNode->children[i]);
		}
		cout<<endl;
	}
}
void printTree(TreeNode<int> *root){
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}
int main(){
	TreeNode<int> *root = takeInputLevelWise();
	printLevelWise(root);
}