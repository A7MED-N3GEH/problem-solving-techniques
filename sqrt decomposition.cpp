#include <bits/stdc++.h>
using namespace std;
# define ed '\n'
class SqrtDecomposition {
private:
    vector<int> arr, block_sum;
    int block_size;
public:
    // Constructor
    SqrtDecomposition(vector<int>& input) {
        arr = input;
        int n = arr.size();
        block_size = sqrt(n);
        block_sum.resize((n + block_size - 1) / block_size, 0);

        // Precompute block sums
        for (int i = 0; i < n; ++i) {
            block_sum[i / block_size] += arr[i];
        }
    }
    // Update value at index idx
    void update(int idx, int value) {
        int block_idx = idx / block_size;
        block_sum[block_idx] -= arr[idx];
        arr[idx] = value;
        block_sum[block_idx] += arr[idx];
    }
    // Range query: sum from index l to r
    int range_query(int l, int r) {
        int sum = 0;
        int block_l = l / block_size;
        int block_r = r / block_size;

        // If l and r are in the same block, simply sum the elements
        if (block_l == block_r) {
            for (int i = l; i <= r; ++i) {
                sum += arr[i];
            }
        } else {
            // Sum elements from l to the end of its block
            for (int i = l; i < (block_l + 1) * block_size; ++i) {
                sum += arr[i];
            } 
            // Sum full blocks between l and r
            for (int i = block_l + 1; i < block_r; ++i) {
                sum += block_sum[i];
            }
            // Sum elements from the start of r's block to r
            for (int i = block_r * block_size; i <= r; ++i) {
                sum += arr[i];
            }
        } 
        return sum;
    }
};
// 8 4
// 3 2 4 5 1 1 5 3
// 2 1 4
// 2 5 6
// 1 3 1
// 2 1 4
int main() {
    int n,q;cin>>n>>q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    SqrtDecomposition sqrt_decomp(arr);
    while (q--)
    {
        int l,r,x;
        cin>>x;
        if (x==2){
                cin>>l>>r;
                l--,r--;
                cout << sqrt_decomp.range_query(l, r) << ed;
        }else{
            int u,v;
            cin>>u>>v;
            u--;
            sqrt_decomp.update(u, v); 
        }
    }
    return 0;
}
