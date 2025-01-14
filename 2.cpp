/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    if ((rear + 1) % 100005 == front) {
            // Queue is full; ideally, handle the error or resize if required.
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % 100005; // Circular increment
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    if (front == rear) {
            return -1; // Queue is empty
        }
        int val = arr[front];
        front = (front + 1) % 100005; // Circular increment
        return val;
}