#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T> *next;
	Node(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};
template<typename T>
class Stack {
	// Define the data members
   private: 
	Node<T> *head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
    	head = nullptr;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
    	return size==0;
    }

    void push(T element) {
        // Implement the push() function
    	Node<T> *p = new Node<T>(element);
        p->next = head;
        head = p;
        size++;
    }

    T pop() {
        // Implement the pop() function
    	if(head==NULL) return -1;
        Node<T> *p = head;
        T element = p->data;
        if(head->next == NULL){
            head= NULL;
        }else{
            head = head->next;
        }
        delete p;
        size--;
        return element;
    }

    T top() {
        // Implement the top() function
        if(head!=NULL){
            return head->data;
        }else{
            return -1;
        }
    }
};

int main() {
    Stack<int> st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}