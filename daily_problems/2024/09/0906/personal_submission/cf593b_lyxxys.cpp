#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, inf = 1e9, Pi = acos(-1.0);
struct Seg {
    long long Y1, Y2;
};
void solve(){
    int n, X1, X2;
    cin >> n >> X1 >> X2;
    vector <Seg> segs(n);
    for (int i = 0, k, b; i < n; ++ i){
        cin >> k >> b;
        long long Y1 = 1ll*k*X1+b, Y2 = 1ll*k*X2+b;
        segs[i] = {Y1, Y2};
    }

    sort(segs.begin(), segs.end(), [&](Seg &A, Seg &B){
        return A.Y1 == B.Y1 ? A.Y2 > B.Y2 : A.Y1 > B.Y1;
    });


    // Mins 维护 第二维 的最小值
    long long Mins = 1e18;
    for (auto &it : segs){
        Mins = min(Mins, it.Y2);
        if (it.Y2 > Mins){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
