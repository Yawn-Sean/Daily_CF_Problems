#include<bits/stdc++.h>
using namespace std;

void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    double ans = -1;
    for (int i = 0; i+2<n; i ++ ) {
        int pos = upper_bound(a.begin(), a.end(),a[i] + k) - a.begin() - 1;
        if (abs(pos - i) <= 1) continue;
        //cout << a[i] << ' ' << a[i+1] << ' ' << a[pos] << endl;
        ans = max(ans, (a[pos] - a[i+1]) / (a[pos] - a[i]));
    }
    cout << fixed << setprecision(10) << ans << endl;
} 