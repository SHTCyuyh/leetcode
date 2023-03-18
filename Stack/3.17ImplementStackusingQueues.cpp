#include<stack>
#include<string>
#include<vector>
#include<queue>
using namespace std; 

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }


    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int re = q.front();
        q.pop();
        return re;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();

    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

};

// int main(){
//     MyStack myStack;
//     myStack.push(1);
//     myStack.pop(); // return 2
//     myStack.empty(); // return False
//     return 1;

// }


