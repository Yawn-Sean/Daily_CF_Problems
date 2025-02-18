#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> A(m);
    for (auto &x : A) cin >> x;
    map <int, vector<int>> mps;
    vector <long long> all(n+1);
    // 枚举 x 会 变成 什么数字，取 它对应式子另一个数字构成序列的中位数
    long long res = 0;
    for (int i = 1; i < m; ++ i){
        int d = abs(A[i]-A[i-1]);
        res += d;
        if (A[i] != A[i-1]){
            all[A[i]] += d;
            all[A[i-1]] += d;
            mps[A[i]].push_back(A[i-1]);
            mps[A[i-1]].push_back(A[i]);
        }
    }

    long long cur = 0;
    for (auto &it : mps){
        auto &vec = it.second;
        sort(vec.begin(), vec.end());
        int len = vec.size(), ans = 0, mids = vec[len/2];
        for (auto &x : vec) ans += abs(mids - x);
        cur = max(cur, all[it.first]-ans);
    }

    cout << res-cur << "\n";
}
