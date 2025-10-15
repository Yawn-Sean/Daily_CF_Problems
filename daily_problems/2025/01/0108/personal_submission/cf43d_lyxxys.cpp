#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}

void solve(){
    auto move = [&](int n, int m)->vector<array<int,2>>{
        vector <array<int,2>> ans;
        for (int i = 1; i <= m; ++ i) ans.push_back({1,i});
        for (int i = 2; i <= n; ++ i) ans.push_back({i, m});
        int x = n, y = m-1;
        bool jg = 1;
        while (x > 1 && y >= 1 && y <= m-1){
            ans.push_back({x,y});
            if (jg){
                if (y == 1){
                    x -= 1;
                    jg = 0;
                } else y -= 1;
            } else {
                if (y == m-1){
                    x -= 1;
                    jg = 1;
                } else y += 1;
            }
        }
        ans.push_back({1,1});
        return ans;
    };

    int n, m;
    cin >> n >> m;
    array <int,5> res;
    vector <array<int,2>> ans;
    bool swap_jg = 0;  // jgdue for wherther swap
    if (n == 1 || m == 1){   // row or column is 1
        if (max(n, m) > 2){
            if (n > m){
                swap(n, m);
                swap_jg = 1;
            }
            for (int i = 1; i <= m; ++ i){
                ans.push_back({1,i});
            }
            ans.push_back({1,1});
            res = {1, 1, m, 1, 1};
        } else {
            res[0] = 0;
            if (n == 1) ans = {{1,1},{1,2},{1,1}};
            else ans = {{1,1},{2,1},{1,1}};
        }
    } else if (n%2==0 || m%2 == 0){
        if (n%2){
            swap(n, m);
            swap_jg = 1;
        }
        ans = move(n, m);
        res[0] = 0;
    } else {
        ans = move(n, m);
        res = {1, 2, m-1, 1, 1};
    }


    cout << res[0] << "\n";
    if (res[0] > 0){
        if (swap_jg){
            swap(res[1], res[2]);
            swap(res[3], res[4]);
        }
        cout << res[1] << " " << res[2] << " " << res[3] << " " << res[4] << "\n";
    }
    assert(ans.size() == n*m+1);
    for (int i = 0; i < ans.size(); ++ i){
        if (swap_jg) swap(ans[i][0], ans[i][1]);
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
}
