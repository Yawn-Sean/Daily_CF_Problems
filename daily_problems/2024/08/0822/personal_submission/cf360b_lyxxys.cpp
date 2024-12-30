#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 300, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n);
    for (auto &x : A) cin >> x;

    auto call = [&](int mid)->int{
        vector <int> f(n);
        int Max = 0;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < i; ++ j){
                if (abs(A[i]-A[j]) <= 1ll*(i-j)*mid) f[i] = max(f[i], f[j]+1);
            }
            Max = max(Max, f[i]+1);
        }
        return n-Max;
    };

    int l = 0, r = 2e9;
    while (l < r){
        int mid = l + (r-l)/2;
        if (call(mid) <= k) r = mid;
        else l = mid+1;
    }

    cout << l << "\n";
}
