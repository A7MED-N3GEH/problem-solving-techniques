#include <bits/stdc++.h>
using namespace std;
# define int long long
#define all(v) v.begin(),v.end() 
#define Rall(v) v.rbegin(),v.rend() 
#define ed '\n' 

// sparse table (max , min,lcm,gcd)=>o(1)
// prefix sum (sum , xor , multible)=>o(1)
const int N = 2e5+5;
int n,q,s[N],Table[N][22],log_arr[N];

int merge(int a,int b )
{
    // return max(a,b);
    // return a+b;
    return min(a,b);
}
void build_log() {
    log_arr[1] = 0;  // log2(1) = 0
    for (int i = 2; i < N; i++) {
        log_arr[i] = log_arr[i / 2] + 1;  // log2(i) = log2(i / 2) + 1
    }
}
void build()
{
    for(int i = 0 ; i < n ;i++) // o(n)
    {
        Table[i][0] = s[i]; 
    }
    for (int pw = 1; (1<<pw) <= n; pw++)// log(n)
    {
        for (int i = 0; i+(1<<pw)<=n; i++) // o(n) // (1<<pw) == 2^pw 
        { 
            Table[i][pw] = merge(Table[i][pw-1] , Table[i+(1<<(pw-1))][pw-1]);
        } 
    }
    
}
int query(int l , int r)
{
    int size = r-l+1;
    int ans = INT_MAX;
    for(int i = 21 ; i>=0 ; i--)
    {
        if((size>>i) & 1)//bit is one
        {
            ans = merge(ans,Table[l][i]);
            l+=(1<<i);//power of tow
        }
    }
    return ans;
}
int query2(int l,int r) // o(1)
{
    int size = r-l+1;
    int pw = log_arr[size];
    return merge(Table[l][pw] , Table[r-(1<<pw)+1][(pw)]);
}
signed main()
{
    build_log();
    cin>>n>>q;
    for(int i = 0 ; i<n ; i++)cin>>s[i];
    build();

    while (q--)
    {
        int l,r;cin>>l>>r;
        l--,r--;
        cout<<query2(l,r)<<ed;
    }
    


    // for(int i = 0; i<n ; i++)
    // {
    //     for (int o = 0; o <4; o++)
    //     {
    //         cout<<Table[i][o]<<" ";
    //     }cout<<ed;
    // }
    return 0;
}
