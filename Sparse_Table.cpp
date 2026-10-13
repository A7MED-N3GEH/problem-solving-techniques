struct SparseTable {
    int n, LOG;
    vector<vector<int>> table;
    vector<int> lg;

    int merge(int a, int b) {
        return max(a, b); 
    }

    SparseTable(const vector<int> &arr) {
        n = arr.size();
        LOG = 32 - __builtin_clz(n);

        table.assign(LOG, vector<int>(n));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        table[0] = arr;

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                table[k][i] =
                    merge(table[k - 1][i],
                          table[k - 1][i + (1 << (k - 1))]);
    }

    int query(int l, int r) {
        int k = lg[r - l + 1];
        return merge(table[k][l],
                     table[k][r - (1 << k) + 1]);
    }
};
