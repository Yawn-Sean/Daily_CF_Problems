#include <bits/stdc++.h>
struct fenwick {
    vector <int> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void init(int n){
        info.resize(n+1), n = n;
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
    fenwick Y(n);
    vector <int> nums(n+1), cnt(n+1);
    int ct = 0;
    bool flg = 1;

    for (int i = 1; i <= n; ++ i){
        cin >> nums[i];
        if (cnt[nums[i]]) flg = 0;
        ++ cnt[nums[i]];
        ct += Y.query(n)-Y.query(nums[i]);
        Y.add(nums[i], 1);
    }

    if (flg && ct%2) cout << "NO\n";
    else cout << "YES\n";
}
