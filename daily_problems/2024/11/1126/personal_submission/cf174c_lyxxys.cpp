#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<int,2>;
    int n;
    cin >> n;
    vector <int> A(n+1), ds(n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
        ds[i] = A[i]-A[i-1];
    }

    vector<ary2> ans;
    for (int i = 1, j = 1; i <= n; ++ i){
        while (ds[i] > 0){
            while (j <= n && ds[j] >= 0) j += 1;
            if (j > n){
                while (ds[i]){
                    ans.push_back({i,j-1});
                    ds[i] -= 1;
                }
            } else {
                assert(ds[j] < 0);
                int d = min(ds[i], -ds[j]);
                while (d){
                    ans.push_back({i, j-1});
                    d -= 1, ds[i] -= 1, ds[j] += 1;
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &it : ans){
        cout << it[0] << " " << it[1] << "\n";
    }
}
