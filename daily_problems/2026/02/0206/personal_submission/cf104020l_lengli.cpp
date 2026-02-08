#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<long long, 3>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    sort(a.begin(), a.end());

    long long INF = ((1LL << 62) - 1) << 1;
    long long best = INF;

    for(int i = 0; i < n; ++i){
        long long x1 = a[i][0], y1 = a[i][1], z1 = a[i][2];
        for(int j = max(0, i - 100); j < i; ++j){
            long long x2 = a[j][0], y2 = a[j][1], z2 = a[j][2];
            long long dx = x2 - x1;
            long long dy = y2 - y1;
            long long dz = z2 - z1;
            long long dist2 = dx*dx + dy*dy + dz*dz;
            if(dist2 < best) best = dist2;
        }
    }

    double ans = sqrt((double)best);
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}
