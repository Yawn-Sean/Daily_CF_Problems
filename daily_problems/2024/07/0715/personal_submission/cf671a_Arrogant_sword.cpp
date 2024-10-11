#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int ax, ay, bx, by, sx, sy;
    cin >> ax >> ay >> bx >> by >> sx >> sy;
    int n;
    cin >> n;
    vector<array<int, 2>> points(n);
    rep0(i, n) {
        cin >> points[i][0] >> points[i][1];
    }

    double sum = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> a, b;
    rep0(i, n) {
        double ta = sqrt((ax - points[i][0]) * (ax - points[i][0]) + (ay - points[i][1]) * (ay - points[i][1]));
        double tb = sqrt((bx - points[i][0]) * (bx - points[i][0]) + (by - points[i][1]) * (by - points[i][1]));
        double ds = sqrt((sx - points[i][0]) * (sx - points[i][0]) + (sy - points[i][1]) * (sy - points[i][1]));
        a.emplace(ta - ds, i); b.emplace(tb - ds, i);
        sum += ds * 2;
    }
    double ans = min({sum + a.top().first, sum + b.top().first});

    

    if (a.top().second != b.top().second) {
        ans = min(ans, sum + a.top().first + b.top().first );
    } else if (n > 1) {
        auto ta0 = a.top().first; a.pop();
        auto ta1 = a.top().first;
        auto tb0 = b.top().first; b.pop();
        auto tb1 = b.top().first;
        ans = min({ans, sum + ta0 + tb1, sum + ta1 + tb0});
    }
    cout << fixed << setprecision(10) << ans << endl;
    
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}