#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 2000001, mod = 1000001, inf = 1e9;
int pos[N], cnt[N];

void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> nums(n+1);
    for (int i = 1; i < N; ++ i) pos[i] = n+1;
    for (int i = 1; i <= n; ++ i)
        cin >> nums[i];

    for (int i = n; i >= 1; -- i){  //预处理每个数字最右边的值
        if (pos[nums[i]] == n+1) pos[nums[i]] = i;
        ++ cnt[nums[i]];
    }
    
    int res = 0;
    int l = 1, r = 1, v = 0;
    for (int i = 1; i <= n; ++ i){  //考虑合并每一个区间，最小代价为当前区间长度减去出现频率最大的
        if (r < i){
            res += r-l+1 - v;
            l = r = i;
            v = 0;
        }
        if (pos[nums[i]] > r) r = pos[nums[i]];
        if (cnt[nums[i]] > v) v = cnt[nums[i]];
    }
    res += r-l+1 - v;
    cout << res << "\n";
}
 
int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
