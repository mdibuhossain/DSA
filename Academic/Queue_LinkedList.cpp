#include <iostream>
using namespace std;

class Qnode
{
public:
    int data;
    Qnode *next;
    Qnode()
    {
        next = NULL;
    }
};

class Queue
{
public:
    Qnode *head;
    Qnode *tail;
    Queue()
    {
        head = tail = NULL;
    }
    void enQueue(int x)
    {
        Qnode *tmp = new Qnode();
        tmp->data = x;
        if (tail == NULL)
        {
            head = tail = tmp;
            return;
        }
        tail->next = tmp;
        tail = tmp;
    }
    void deQueue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Qnode *tmp = head;
        cout << "deQueued: " << tmp->data << endl;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        delete tmp;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Qnode *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue qu;
    while (true)
    {
        cout << "1. enQueue" << endl;
        cout << "2. deQueue" << endl;
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
            qu.enQueue(x);
            cout << qu.tail->data << endl;
            break;
        case 2:
            qu.deQueue();
            break;
        case 3:
            qu.display();
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