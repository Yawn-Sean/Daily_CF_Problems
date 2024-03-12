// 二分！
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

void solve() 
{
    int n;
    cin >> n;
    vector<array<double, 2>> per(n);
    for (int i = 0; i < n; i ++ ) cin >> per[i][0];
    for (int i = 0; i < n; i ++ ) cin >> per[i][1];

    double l = 0, r = 1e9 / 2;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        double sr = per[0][0] + mid * per[0][1], sl = per[0][0] - mid * per[0][1];
        bool ok = true;
        for (int i = 1; i < n; i ++ ) {
            double tl = per[i][0] - mid * per[i][1];
            double tr = per[i][0] + mid * per[i][1];
            if (tr < sl || tl > sr) {
                ok = false;
                break;
            }
            sl = max(sl, tl);
            sr = min(sr, tr);
        } 
        if (ok) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(12) << r << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}