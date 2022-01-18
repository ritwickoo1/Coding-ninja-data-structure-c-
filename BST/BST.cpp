#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    // Define the data members
   private: 
    BinaryTreeNode<int>* root;
    bool search(BinaryTreeNode<int> *root,int data){
        if(root == NULL) return false;
        if(root->data == data)  return true;
        if(root->data > data) return search(root->left,data);
        else return search(root->right,data);
    }
    BinaryTreeNode<int> * insert(BinaryTreeNode<int> * root,int data){
        if(root==NULL){
        	BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
			return newNode;
        } 
        if(root->data < data){
	   		root->right = insert(root->right,data);
	   	}else if(root->data >= data){
	   		root->left = insert(root->left,data);
	   	}
        return root;
    }
    void print(BinaryTreeNode<int> * root){
        if(root == NULL) return;
        cout<<root->data<<":";
        if(root->left!=NULL ){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        print(root->left);
        print(root->right);
    }
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node,int data){
        if(node == NULL) return NULL;
        if(node->data < data){
            node->right = remove(node->right,data);
        	return node;
        }else if(node->data > data){
            node->left = remove(node->left,data);
            return node;
        }else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->left==NULL){
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->right==NULL){
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int> *minRight = node->right;
            	while(minRight->left!=NULL){
                    minRight = minRight->left;
                }
                int minData = minRight->data;
                node->data = minData;
                node->right = remove(minRight,minData);
            	return node;
            }
        }
    }
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function
		root = remove(root,data);
    }

    void print() { 
        // Implement the print() function
        print(root);
        
    }

    void insert(int data) { 
       // Implement the insert() function 
       root = insert(root,data);
        
    }

    bool search(int data) {
		// Implement the search() function
        return search(root,data);
    }
};
int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}