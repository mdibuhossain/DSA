#include <iostream>
using namespace std;

class Stack
{

public:
    int data;
    Stack *next;
    Stack()
    {
        next = NULL;
    }
    bool isEmpty(Stack *head)
    {
        if (head->next == NULL)
            return true;
        return false;
    }
    void push(Stack **head, int x)
    {
        if ((*head) == NULL)
            (*head) = new Stack();
        Stack *tmp = new Stack();
        tmp->data = x;
        tmp->next = *head;
        *head = tmp;
    }
    void pop(Stack **head)
    {
        if (isEmpty((*head)))
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int res = (*head)->data;
        Stack *tmp = new Stack;
        tmp = *head;
        (*head) = (*head)->next;
        delete tmp;
        cout << "poped: " << res << endl;
    }
    void display(Stack *head)
    {
        // Stack **tmp = head;
        while ((head)->next != NULL)
        {
            cout << (head)->data << " ";
            head = (head)->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack *head = NULL;
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
            head->push(&head, x);
            break;
        case 2:
            head->pop(&head);
            break;
        case 3:
            head->display(head);
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