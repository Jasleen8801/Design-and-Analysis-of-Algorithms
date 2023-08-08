// Implement a special type of stack in which two values will be inserted with one push operation and two values will be deleted with one pop operation. With one Push operation, top will be increased once and with one Pop operation, Top will be decreased only once.

#include <bits/stdc++.h>
using namespace std;

class SpecialStack{
private:
    int capacity;
    int *arr;
    int top;
public:
    SpecialStack(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity*2];
        this->top = -1;
    }

    ~SpecialStack(){
        delete[] arr;
    }

    void push(int val1, int val2) {
        if(top+2 >= capacity*2) {
            cout << "Stack full" << endl;
            return;
        }

        top++;
        arr[top] = val1;
        top++;
        arr[top] = val2;
    }

    void pop(){
        if(top < 0) {
            cout << "Stack empty" << endl;
            return;
        }
        top -= 2;
    }

    bool isEmpty() const{
        return top < 0;
    }
};

int main(){
    int capacity;
    cout << "Enter capacity of special stack: ";
    cin >> capacity;

    SpecialStack specialStack(capacity);

    specialStack.push(1,2);
    specialStack.push(3,4);

    specialStack.pop();

    if(!specialStack.isEmpty()) specialStack.push(5,6);

    return 0;
}