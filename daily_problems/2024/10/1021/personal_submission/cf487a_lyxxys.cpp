#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int inf = 1e9;
    auto ceil = [&](int a, int b){
        if (b == 0) return inf;
        return (a + b-1) / b;
    };

    int a1, b1, c1, a2, b2, c2, sp1, sp2, sp3;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> sp1 >> sp2 >> sp3;

    int a, b, c;
    auto ck = [&]()->bool{
        return ceil(a2, max(0,b-c2)) < ceil(a, max(0, b2-c));
    };

    int res = inf;
    for (int i = 0; i <= 1000; ++ i){
        for (int j = 0; j <= 1000; ++ j){
            a = a1+i, b = b1+j;
            int l = 0, r = 1000;
            while (l < r){
                int mid = (l+r) >> 1;
                c = c1+mid;
                if (ck()) r = mid;
                else l = mid+1;
            }
            c = c1+l;
            if (ck()){
                res = min(res, sp1*i + sp2*j + sp3*l);
            }
        }
    }

    cout << res << "\n";
}
