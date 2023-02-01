#include <iostream>
using namespace std;

class Heap
{
public:
    void build(int ar[], int n, int start)
    {
        int target = start;
        int left = 2 * start + 1;
        int right = left + 1;
        if (left < n && ar[left] > ar[target]) // max heap condition
            target = left;
        if (right < n && ar[right] > ar[target]) // max heap condition
            target = right;
        if (target != start)
        {
            swap(ar[start], ar[target]);
            build(ar, n, target);
        }
    }
    void sort(int ar[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            build(ar, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(ar[0], ar[i]);
            build(ar, i, 0);
        }
    }
};

int main()
{
    Heap heap;
    int ar[3] = {999, 852, 999999};
    heap.sort(ar, 3);
    return 0;
}
