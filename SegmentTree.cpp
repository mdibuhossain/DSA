class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, int ar[])
    {
        if (low == high)
        {
            seg[ind] = ar[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, ar);
        build(2 * ind + 2, mid + 1, high, ar);
        // can be changed
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return INT_MAX;

        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        // can be changed
        return min(left, right);
    }

    void update(int ind, int low, int high, int id, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (id <= mid)
            update(2 * ind + 1, low, mid, id, val);
        else
            update(2 * ind + 2, mid + 1, high, id, val);
        // can be changed
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
