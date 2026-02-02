//https://cses.fi/problemset/task/1686/
//https://codeforces.com/problemset/problem/427/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define cin(a)        \
    for (auto &i : a) \
        cin >> i;

void files()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
const int OO = 2e18, LOG = 20, MOD = 1e9 + 7, N = 1e5 + 5;
struct SCC
{
    vector<vector<int>> adj[2]; // 0 for original , 1 for revecsed graph
    vector<int> order, ids, cost, dp, sccCost;
    vector<vector<int>> components;
    vector<vector<int>> dag;
    int cnt = 0;
    bool vis[N];
    SCC(int n)
    {
        adj[0].resize(n + 1);
        adj[1].resize(n + 1);
        ids.resize(n + 1, -1);
        cost.resize(n + 1, 0);
        sccCost.resize(n + 1, 0);
        dp.resize(n + 1, 0);
    }
    void add_edge(int u, int v)
    {
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    void dfs(int node, int tp)
    {
        vis[node] = 1;
        for (auto it : adj[tp][node])
            if (!vis[it])
                dfs(it, tp);
        if (tp == 0)
        {
            order.push_back(node);
        }
        else
        {
            ids[node] = cnt;
            components.back().push_back(node);
        }
    }
    // build kosaraju
    void build(int n)
    {
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                dfs(i, 0);
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int node = order[i];
            if (!vis[node])
            {
                components.push_back(vector<int>());
                dfs(node, 1);
                cnt++;
            }
        }
        for (int i = 1; i <= n; i++)
            sccCost[ids[i]] += cost[i];
    }

    void build_dag(int n)
    {
        dag.assign(cnt, {});
        set<pair<int, int>> st;
        for (int node = 1; node <= n; node++)
        {
            for (auto it : adj[0][node])
            {
                int cu = ids[node], cv = ids[it];
                if (cu != cv)
                {
                    if (st.insert({cu, cv}).second)
                        dag[cu].push_back(cv);
                }
            }
        }
    }
    vector<int> topo_sort()
    {
        vector<int> indeg(cnt, 0);
        for (int node = 0; node < cnt; node++)
            for (auto it : dag[node])
                indeg[it]++;

        queue<int> q;
        for (int i = 0; i < cnt; i++)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : dag[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
    // get count of scc
    int scc_count()
    {
        return cnt;
    }
    // get component id of node
    int component_id(int node)
    {
        return ids[node];
    }
    // get all components
    vector<int> get_SCC(int node)
    {
        return components[ids[node]];
    }
    vector<vector<int>> get_dag()
    {
        return dag;
    }
    int getMaxCost()
    {
        auto topo = topo_sort();
        for (auto node : topo)
        {
            dp[node] += sccCost[node];
            for (auto it : dag[node])
                dp[it] = max(dp[it], dp[node]);
        }
        return *max_element(all(dp));
    }
};
void nageh()
{
    int n, m;
    cin >> n;
    SCC scc(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> scc.cost[i];
    cin>>m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        scc.add_edge(u, v);
    }
    scc.build(n);
    scc.build_dag(n);
    int ans1 = 0, ans2 = 1;
    for (int i = 0; i < scc.cnt; i++)
    {
        int mn = OO, cnt = 0;
        for (auto it : scc.components[i])
        {
            if (mn > scc.cost[it])
            {
                mn = scc.cost[it];
                cnt = 1;
            }
            else if (mn == scc.cost[it])
            {
                cnt++;
            }
        }
        ans1 += mn;
        ans2 = ans2 * cnt % MOD;
    }
    cout << ans1 << " " << ans2 << "\n";
}

signed main()
{
    // إِنَّ اللَّهَ وَمَلَائِكَتَهُ يُصَلُّونَ عَلَى النَّبِيِّ ۚ يَا أَيُّهَا الَّذِينَ آمَنُوا صَلُّوا عَلَيْهِ وَسَلِّمُوا تَسْلِيمًا
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    files();
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        nageh();
    return 0;
}
