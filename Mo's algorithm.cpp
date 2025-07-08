#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ed '\n'
void files()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int dx[] = {1, 0, -1, 0}; // right, up, left, down
int dy[] = {0, 1, 0, -1};
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Pi acos(-1)
#define MX_D numeric_limits<double>::max()
#define Ahmed                    \
    ios::sync_with_stdio(false); \
    cin.tie(nuintptr);
const double EPS = 1e-9;
// const int N = 1e5 + 5, log_mx = 20, MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int A = 1e6 + 6;
int a[N], pref[N], freq[N],SQ, res = 0, n, q, k;
vector<int>ans;
struct Query
{
    int l, r, idx;
    bool operator<(const Query &q) const
    {
        int b1 = l / SQ, b2 = q.l / SQ;
        if (b1 != b2)
            return b1 < b2;
        return r < q.r;
    }
};
vector<Query> qu;
void add(int idx)
{
    freq[a[idx]]++;
    if(freq[a[idx]] == 1)res++;
}

void remove(int idx)
{
    freq[a[idx]]--;
    if(freq[a[idx]] == 0)res--;
}
void Mo_algo()
{
    int l = 0, r = -1;
    for (auto &q : qu)
    {
        while (r < q.r)
            add(++r);
        while (r > q.r)
            remove(r--);
        while (l < q.l)
            remove(l++);
        while (l > q.l)
            add(--l);
        ans[q.idx] = res;
    }
}
void solve()
{

    cin >> n>>q;
    SQ = sqrt(n)+1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    qu.resize(q);
    ans.resize(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        qu[i] = {--l, --r, i};
    }
    sort(all(qu));
    Mo_algo();
    for (int i = 0; i < q; i++)
        cout << ans[i] << ed;
}

signed main()
{
// ( إِنَّ اللَّهَ وَمَلَائِكَتَهُ يُصَلُّونَ عَلَى النَّبِيِّ ۚ يَا أَيُّهَا الَّذِينَ آمَنُوا صَلُّوا عَلَيْهِ وَسَلِّمُوا تَسْلِيمًا )
#ifndef ONLINE_JUDGE
    files();
#endif

    // freopen("jaguar.in", "r", stdin);
    // freopen("distance4.out", "w", stdout);
    // Ahmed
    // init();
    // sieve();
    int t = 1;
    // cin >> t;
    //  bool fg = true;
    //  int cnt = 1;
    while (t--)
    {
        // if (!fg)cout << nl;
        // fg = false;
        solve();
    }
    return 0;
}
