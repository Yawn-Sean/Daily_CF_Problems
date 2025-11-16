#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 5E5 + 10;
ll n, a[N];
ll pre[N], pre2[N];
ll tree[1000010];
ll lowbit(ll x){
    return x & -x;
}
void add(int j, ll x){
    for (int i = j; i <= 1000004; i += lowbit(i)){
        tree[i] += x;
    }
}
void work(ll j){
    for (int i = j; i <= 1000004; i += lowbit(i)) tree[i] = 0;
}
ll sum(int j){
    ll ret = 0;
    for (int i = j; i; i -= lowbit(i)){
        ret += tree[i];
    }
    return ret;
}
void solve(){
    cin >> n;
    map<ll, vector<int>> mp;
    mp[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        pre2[i] = pre2[i - 1] + ((a[i] > 0) ? 1 : -1);
        mp[pre[i]].push_back(i);
    }
    ll ans = 0;
    for (auto [i, j]: mp){
        if (j.size() == 1) continue;
        int len = j.size();
        for (int k = 0; k < len; ++k){
            int id = j[k];
            ans += sum(1000004) - sum(pre2[id] - 1 + 500004);
            add(pre2[id] + 500004, 1);
        }
        for (int k = 0; k < len; ++k){
            int id = j[k];
            work(pre2[id] + 500004);
        }         
    }
    cout << ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}