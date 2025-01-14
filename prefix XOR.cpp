#include<bits/stdc++.h>
using namespace std;
#define ed "\n"
#define int long long
#define Acin(arr) for(auto &i : arr)cin>>i;
int arr_xor[1000005];
void solve()
{
    int n,q;cin>>n>>q;
    vector<int>a(n);
    Acin(a);
    arr_xor[0] = a[0];
    for(int i =1; i<n ; i++)
    {
        arr_xor[i]=arr_xor[i-1]^a[i];
    }
    while (q--)
    {
        int l , r;cin>>l>>r;
        l--,r--;
        cout<<(l==0?arr_xor[r]:(arr_xor[l-1]^arr_xor[r]))<<ed;
    }
}
signed main()
{
    // int t;cin>>t;while (t--)
    // {
        solve();
    // }
    return 0;
}
