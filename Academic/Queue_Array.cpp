#include <iostream>
#include <vector>
using namespace std;
#define SIZE 100

class Queue
{
    vector<int> items;
    int front, back;

public:
    Queue()
    {
        front = -1;
        back = -1;
        items.resize(SIZE);
    }
    Queue(int len)
    {
        front = -1;
        back = -1;
        items.resize(len);
    }
    bool isFull()
    {
        if (front == 0 && back == items.size() - 1)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }
    void enQueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
            front++;
        back = (back + 1) % items.size();
        items[back] = x;
    }
    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int res = items[back];
        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            front = (front + 1) % items.size();
        }
        cout << "deQueued: " << res << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i;
        for (i = front; i != back; i = (i + 1) % items.size())
            cout << items[i] << " ";
        cout << items[i];
        cout << endl;
    }
};

int main()
{
    int len;
    cout << "Queue size: ";
    cin >> len;
    Queue qu(len);
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