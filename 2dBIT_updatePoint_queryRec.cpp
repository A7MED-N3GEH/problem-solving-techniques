#include <bits/stdc++.h>
using namespace std;
#define int long long
//update point and get sum rectangle
//https://cses.fi/problemset/task/1739
struct BIT2D
{
    int n, m;
    vector<vector<int>> tree;
    BIT2D(int _n, int _m)
    {
        n = _n + 5, m = _m + 5;
        tree = vector<vector<int>>(n, vector<int>(m));
    }
    // update a single point (x,y) by val
    void update(int x, int y, int val)
    {
        for (; x < n; x |= (x + 1))
        {
            for (int o = y; o < m; o |= (o + 1))
            {
                tree[x][o] += val;
            }
        }
    }
    // get from (0,0) to (x,y)
    int get(int x, int y)
    {
        int ans = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
        {
            for (int o = y; o >= 0; o = (o & (o + 1)) - 1)
            {
                ans += tree[x][o];
            }
        }
        return ans;
    }
    // Returns sum of all elements in rectangle defined by
    // top-left (t,l) and bottom-right (b,r)
    int query(int l, int r, int t, int b)
    {
        return get(b, r) - get(t - 1, r) - get(b, l - 1) + get(t - 1, l - 1);
    }
};
void nageh()
{
    int n, q;
    cin >> n >> q;
    BIT2D bt(n, n);
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int o = 0; o < n; o++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                grid[i][o] = 1;
                bt.update(i, o, 1);
            }
        }
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int x, y;
            cin >> x >> y;
            --x, --y;
            bt.update(x, y, (grid[x][y] == 1 ? -1 : 1));
            grid[x][y] ^= 1;
        }
        else
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            --r1;
            --c1;
            --r2;
            --c2;
            cout << bt.query(c1, c2, r1, r2) << '\n';
        }
    }
}
signed main()
{
    // إِنَّ اللَّهَ وَمَلَائِكَتَهُ يُصَلُّونَ عَلَى النَّبِيِّ ۚ يَا أَيُّهَا الَّذِينَ آمَنُوا صَلُّوا عَلَيْهِ وَسَلِّمُوا تَسْلِيمًا
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)nageh();
    return 0;
}
