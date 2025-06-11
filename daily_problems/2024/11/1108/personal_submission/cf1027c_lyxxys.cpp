#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<long long,2>;
    
    int n;
    cin >> n;
    map <int,int> mps;

    auto chk = [&](ary2 &u, ary2 v)->bool{
        bool jg = 0;
        if (u[0]*v[1] > v[0]*u[1]){
            u = v;
            jg = 1;
        }
        return jg;
    };

    for (int i = 0; i < n; ++ i){
        int x;
        cin >> x;
        mps[x] += 1;
    }

    long long lst = -1;
    ary2 ans = {}, A = {1000000000ll,1ll};  // 枚举相邻的，用分数取最小
    for (auto &it : mps){
        int x = it.first, y = it.second;
        if (y < 2) continue;

        if (y >= 4){
            ans = {x, x};
            break;
        }

        if (lst != -1){
            if (chk(A, {lst*lst+x*x, lst*x})){
                ans = {lst, x};
            }
        }

        if (y > 1){
            lst = x;
        }
    }

    cout << ans[0] << " " << ans[0] << " " << ans[1] << " " << ans[1] << "\n";
}
