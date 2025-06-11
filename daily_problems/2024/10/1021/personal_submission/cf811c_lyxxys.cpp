#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int N = 5001;
    int n;
    cin >> n;
    vector <int> nums(n), L(N), R(N), f(n+1);
    for (auto &x : nums) cin >> x;
    for (int i = 0; i < n; ++ i){
        R[nums[i]] = i;
    }
    for (int i = n-1; i >= 0; -- i){
        L[nums[i]] = i;
    }

    vector <int> vis(N);
    for (int i = 0; i < n; ++ i){
        f[i+1] = max(f[i+1], f[i]);
        int v = 0;        
        for (int j = i, r = 0, y; j < n; ++ j){  //根据 第一次和最后一次出现 的位置 来 枚举转移
            y = nums[j];
            if (L[y] < i) break;
            if (R[y] > r) r = R[y];

            if (!vis[y]) v ^= y, vis[y] = 1;
            if (j == r){
                f[r+1] = max(f[r+1], f[i]+v);
            }
        }
        for (int j = i; j < n; ++ j) vis[nums[j]] = 0;
    }

    cout << f[n] << "\n";
}
