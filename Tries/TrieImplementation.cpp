#include<iostream>
#include<string>
using namespace std;
class TrieNode{
	public:
		char data;
		TrieNode ** children;
		bool isTerminal;
	TrieNode(char data){
		isTerminal = false;
		this->data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++){
			children[i] = NULL;
		}
	}
	~TrieNode(){
		for(int i = 0; i < 26; i++){
			delete children[i];
		}
		delete [] children;
	}
};
class Trie{
	TrieNode *root;
	public:
		Trie(){
			root = new TrieNode('\0');
		}
	private:
		void insert(TrieNode *root, string word){
			if(word.size()==0){
				root->isTerminal = true;
				return ;
			}
			int index = word[0]-'a';
			TrieNode *child;
			if(root->children[index]!=NULL){
				child = root->children[index];
			}else{
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			insert(child,word.substr(1));
		}
	public:
		void insert(string word){
			insert(root,word);
		}
	private:
		bool search(TrieNode *root,string word){
			if(word.size()==0){
				return root->isTerminal;
			}
			int index = word[0]-'a';
			TrieNode *child;
			if(root->children[index]!=NULL){
				child = root->children[index];
			}else{
				return false;
			}
			return search(child,word.substr(1));
		}
	public:
		bool search(string word){
			return search(root,word);
		}
	private:
		void remove(TrieNode *root, string word){
			if(word.size()==0){
				root->isTerminal = false;
				return;
			}
			int index = word[0]-'a';
			TrieNode *child;
			if(root->children[index]!=NULL){
				child = root->children[index];
			}else{
				return;
			}
			remove(child,word.substr(1));
			if(child->isTerminal==false){
				for(int i = 0; i < 26; i++){
					if(child->children[i]!=NULL){
						return ;
					}
				}
				delete child;
				root->children[index] = NULL;
			}
		}
		public:
			void remove(string word){
				remove(root,word);
			}
};
int main(){
	Trie obj;
	obj.insert("and");
	cout<<obj.search("and")<<endl;
	obj.remove("and");
	cout<<obj.search("and")<<endl;
	return 0;
}