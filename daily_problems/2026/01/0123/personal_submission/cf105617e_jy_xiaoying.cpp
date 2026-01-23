#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/105617/problem/E

//    2026-1-23-(思维+树状数组+第k小)- cfgym105617E 
//

//日期： 2026-1-23 
//格式化： ctrl+shift+ a

typedef long long ll;
const int MAX=2e5+10;


// Fenwick for prefix sums (counts), supports kth (1-indexed)
struct FenwickSum {
    int n;
    vector<int> bit;
    FenwickSum(int n=0): n(n), bit(n+1,0) {}
    
    void add(int i, int delta){
        for(; i<=n; i+=i&-i) bit[i] += delta;
    }
    int sumPrefix(int i) const{
        int s=0;
        for(; i>0; i-=i&-i) s += bit[i];
        return s;
    }
    // smallest idx such that prefix_sum(idx) >= k (assumes 1 <= k <= sumPrefix(n))
    int kth(int k) const{
        int idx = 0; int cur = 0;
        int bitmask = 1;
        while ((bitmask<<1) <= n) bitmask <<= 1; // highest power of 2 <= n
        
        for(int step = bitmask; step; step >>= 1){
            int next = idx + step;
            if(next <= n && cur + bit[next] < k){
                cur += bit[next];
                idx = next;
            }
        }
        return idx + 1;
    }
};

// Fenwick for prefix max, point update with max, prefix query max
struct FenwickMax {
    int n;
    vector<int> bit;
    FenwickMax(int n=0): n(n), bit(n+1,0) {}
    
    void update(int i, int val){
        for(; i<=n; i+=i&-i) bit[i] = max(bit[i], val);
    }
    int query(int i) const{
        int res = 0;
        for(; i>0; i-=i&-i) res = max(res, bit[i]);
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n+1), pos(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];

    // Step 1: compute final positions pos[i] by reverse placement
    FenwickSum fw(n);
    for(int i=1;i<=n;i++) fw.add(i, 1); // all slots empty
    for(int i=n;i>=1;i--){
        int idx = fw.kth(p[i]);   // p[i]-th empty slot
        pos[i] = idx;
        fw.add(idx, -1);          // mark filled
    }

    // Step 2: LIS on positions with increasing values
    FenwickMax fm(n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int best = fm.query(pos[i]-1);
        int cur = best + 1;
        fm.update(pos[i], cur);
        ans = max(ans, cur);
        cout << ans << "\n";
    }
    return 0;
}

/*



*/

