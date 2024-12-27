#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> A(n), vis(n), loc0;
    vector <array<int,3>> ans;
    int neg = 0, ma = -2e9, pos = -1;
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        if (A[i] == 0) loc0.push_back(i);
        if (A[i] < 0){
            neg += 1;
            if (A[i] > ma){
                pos = i, ma = A[i];
            }
        }
    }

    if (loc0.size()){
        int lst = -1;
        if (neg%2) lst = pos, vis[pos] = 1;
        for (auto &x : loc0){
            if (lst != -1) ans.push_back({1, lst, x});
            lst = x;
            vis[x] = 1;
        }
        if (ans.size() < n-1) ans.push_back({2, lst, -1});
    } else if (neg%2){
        ans.push_back({2, pos, -1});
        vis[pos] = 1;
    }

    for (int i = 0, lst = -1; i < n; ++ i){
        if (vis[i]) continue;
        if (lst != -1) ans.push_back({1, lst, i});
        lst = i;
    }

    assert(ans.size() == n-1);
    for (auto &it : ans){
        cout << it[0] << " ";
        if (it[0] == 1) cout << it[1]+1 << " " << it[2]+1 << "\n";
        else cout << it[1]+1 << "\n";
    }
}
