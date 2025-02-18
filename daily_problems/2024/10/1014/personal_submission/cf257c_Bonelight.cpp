/*
    Bonelight * v *
    20241014：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    const double pi = acos(-1.0);
    int n; cin >> n;
    vector<pii> p(n);
    for(auto &[x,y]:p) cin >> x >> y;
#pragma region  
    auto dis2 = [&](int x1, int y1, int x2, int y2){
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    auto angle = [&](int x, int y) -> double{
        double dist = sqrt(dis2(x,y,0,0));
        double angcos = (double)x / dist;
        // if(y < 0 || (y == 0 && x < 0) ) angcos *= -1;  
        double ang = acos(angcos) * 180 / pi;
        return ang;
    };
#pragma endregion
    vector<double> angs(n, INF);
    for(int i = 0; i < n; i ++){
        auto &[x,y] = p[i];
        angs[i] = angle(x,y);
        if(y < 0) angs[i] = 360 - angs[i];
    }
    sort(begin(angs), end(angs));

    double ans = 360;
    for(int i = 0; i < n - 1; i ++){
        ans = min(ans, 360 - abs(angs[i] - angs[i + 1]));
        // cout << fixed << setprecision(10) << ans << ' ' << abs(angs[i] - angs[i + 1]) << endl;
    }
    ans = min(ans, abs(angs[n - 1] - angs[0]));
    cout << fixed << setprecision(10) << ans << endl;
    // for(auto i:angs){
    //     cout << i << endl;
    // }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
