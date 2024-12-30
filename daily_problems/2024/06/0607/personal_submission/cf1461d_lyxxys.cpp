#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e18, mod = 998244353, N = 100060;
unordered_map <ll,bool> ump;
int nums[N], n, q;
ll sum[N];

void dfs(int l, int r){
    if (l == r) return ump[nums[l]] = true, void();
    if (l > r) return;
    ump[sum[r]-sum[l-1]] = true;
    if (nums[l] == nums[r]) return;

    int x = (nums[l] + nums[r]) / 2;
    int pos, lp = l, rp = r;
    while (lp < rp){
        int mid = lp + rp + 1 >> 1;
        if (nums[mid] <= x) lp = mid;
        else rp = mid-1;
    }
    pos = lp;
    dfs(l, pos), dfs(pos+1, r);
}

void solve(){
    ump.clear();
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> nums[i];
    sort(nums+1, nums+1+n);
    for (int i = 1; i <= n; ++ i) sum[i] = sum[i-1] + nums[i];
    dfs(1, n);
    while (q--){
        ll x;
        cin >> x;
        if (ump[x]) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
