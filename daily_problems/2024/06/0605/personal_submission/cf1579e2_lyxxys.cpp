#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 200550, mod = 1000001, inf = 1e9;
struct fenwick {
    int tr[N], n;
    fenwick(){}
    fenwick(int n): n(n) {
        memset(tr, 0, sizeof tr);
    }
    int operator[] (int i){
        return tr[i];
    }
    void init(){
        memset(tr, 0, sizeof tr);
    }
    void add(int x, int c){
        while (x <= n) tr[x] += c, x += x&-x;
    }
    ll query(int x){
        ll res = 0;
        while (x) res += tr[x], x -= x&-x;
        return res;
    }
};
void solve(){
    int n;
    cin >> n;
    vector <int> nums(n+1), Pos(n+1), dic;
    for (int i = 1; i <= n; ++ i) cin >> nums[i], dic.push_back(nums[i]);

    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    auto find = [&](int x)->int {
        return lower_bound(dic.begin(), dic.end(), x) - dic.begin();
    };
    for (int i = 1; i <= n; ++ i) Pos[i] = find(nums[i]);
    fenwick tr(n);
    deque <int> ans;
    for (int i = 1; i <= n; ++ i){
        int x = Pos[i];
        ++ x;
        ll d1 = tr.query(x-1), d2 = tr.query(n)-tr.query(x);
        if (d1 <= d2) ans.push_front(x);
        else ans.push_back(x);
        tr.add(x, 1);
    }

    tr.init();
    ll res = 0;
    for (auto &x : ans){
        res += tr.query(n) - tr.query(x);
        tr.add(x, 1);
    }
    cout << res << "\n";
}
 
int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
