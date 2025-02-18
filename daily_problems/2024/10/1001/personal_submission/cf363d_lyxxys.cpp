#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m, all;
    cin >> n >> m >> all;
    vector <int> A(n), B(m);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    auto check = [&](int mid)->bool{
        int cur = all;
        for (int i = mid-1, j = n-1; i >= 0; -- i, -- j){
            if (A[j] >= B[i]) continue;
            cur -= B[i] - A[j];
            if (cur < 0) return false;
        }
        return true;
    };

    int l = 0, r = min(n, m);
    while (l < r){
        int mid = (l+r+1) >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    long long cost = accumulate(B.begin(), B.begin()+l, 0ll);

    cout << l << " " << max(0ll, cost-all) << "\n";
}
 
