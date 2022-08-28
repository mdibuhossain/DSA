#include <iostream>
using namespace std;

int top = -1;
int len;

bool isEmpty()
{
    if (top < 0)
        return true;
    return false;
}

bool isFull()
{
    if (top >= (len - 1))
        return true;
    return false;
}

void push(int ar[], int x)
{
    if (isFull())
    {
        cout << "Stack is Full" << endl;
        return;
    }
    top++;
    ar[top] = x;
}

void pop(int ar[])
{
    if (isEmpty())
    {
        cout << "Stack is already empty" << endl;
        return;
    }
    cout << "poped: " << ar[top] << endl;
    top--;
}

void display(int ar[])
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
        cout << ar[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Stack size: ";
    cin >> len;
    int stack[len] = {0};
    while (true)
    {
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        int inp;
        cin >> inp;
        switch (inp)
        {
        case 1:
            int x;
            cout << "input: ";
            cin >> x;
            push(stack, x);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            return 0;
        default:
            cout << "try again" << endl;
            break;
        }
    }
    return 0;
}