class DSU
{
public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};
