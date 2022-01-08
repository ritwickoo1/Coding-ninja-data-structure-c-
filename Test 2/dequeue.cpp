#include<iostream>
using namespace std;
class Deque
{
    int  *arr;
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size)
    {
        arr = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }
  
    // Operations on Deque:
    void  insertFront(int key);
    void  insertRear(int key);
    void  deleteFront();
    void  deleteRear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};
  
  
// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}
  
// Inserts an element at front
void Deque::insertFront(int key)
{
    // check whether Deque if  full or not
    if (rear >= size-1)
    {
        cout << "-1" << endl;
        return;
    }
  
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }else
  		rear = rear + 1;
    arr[rear] = key;
	
}
  
// function to inset element at rear end
// of Deque.
void Deque ::insertRear(int key)
{
    // check whether Deque if  full or not
    if (rear >= size-1)
    {
        cout << "-1" << endl;
        return;
    }
  
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }else
  		rear = rear + 1;
    arr[rear] = key;
}
  
// Deletes element at front end of Deque
void Deque ::deleteFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << "-1" << endl;
        return ;
    }
  
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }
    else
        front = front+1;
}
  
// Delete element at rear end of Deque
void Deque::deleteRear()
{
    if (isEmpty())
    {
        cout << "-1" << endl ;
        return ;
    }
  
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        rear = rear-1;
}
  
// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
   //     cout << "-1" << endl;
        return -1 ;
    }
    return arr[front];
}
  
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        //cout << "-1" << endl;
        return -1 ;
    }
    return arr[rear];
}

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.	insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
