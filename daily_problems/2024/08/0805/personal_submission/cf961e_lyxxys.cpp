#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1050, M = 1<<10, mod = 998244353, inf = 1e9;
struct fenwick {
    vector <int> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void init(int n){
        info.resize(n+1), this->n = n;
        for (int i = 0; i <= n; ++ i) info[i] = 0;
    }
    void add(int x, int c){
        while (x <= n) info[x] += c, x += x&-x;
    }
    int query(int x) {
        int res = 0;
        while (x) res += info[x], x -= x & -x;
        return res;
    }
};

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n+2), tmps[n+2];
    for (int i = 1; i <= n; ++ i) cin >> nums[i];
    for (int i = 1; i <= n; ++ i)
        tmps[min(n, nums[i])].push_back(i);
    fenwick Y(n+1);

    ll res = 0;
    for (int i = n; i >= 1; -- i){
        for (auto &x : tmps[i]){
            Y.add(x, 1);
        }
        if (nums[i] > i){
            res += Y.query(min(n,nums[i])) - Y.query(i);
        }
    }
    cout << res << "\n";
}
