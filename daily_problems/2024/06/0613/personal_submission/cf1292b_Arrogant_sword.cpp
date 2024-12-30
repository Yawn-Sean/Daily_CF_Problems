
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 70;

int dist(int x0, int y0, int x1, int y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

void solve(int _) 
{
    vector<int> x(70), y(70);
    int a, b, c, d;
    cin >> x[0] >> y[0] >> a >> b >> c >> d;
    int xs, ys, t;
    cin >> xs >> ys >> t;
    
    // 找到起点右上角最远可以到达的点。
    int n = 0;
    while (++n) {
        x[n] = a * x[n - 1] + c;
        y[n] = b * y[n - 1] + d;
        if (x[n] > xs && y[n] > ys && dist(xs, ys, x[n], y[n]) > t) {
            break;
        } 
    }
    
   
    int ans = 0;
    // 最优解一定是从起点到达某个点i,然后到（x0,y0),再往无穷远处走。
    for (int i = 0; i <= n; i ++ ) {
        int tans = 0, tt = t;
        if (dist(xs, ys, x[i], y[i]) <= tt) {
            tt  -= dist(xs, ys, x[i], y[i]);
            tans ++;
        } else {
            continue;
        }
        
        int j = i;
        for (; j; j -- ) {
            if (dist(x[j], y[j], x[j-1], y[j-1]) <= tt) {
                tt -= dist(x[j], y[j], x[j-1], y[j-1]);
                tans ++;
            } else {
                break;
            }
        }
        if (j != 0) {
            ans = max(ans, tans);
            continue;
        }
        j = 1;
        for (; j <= n; j ++ ) {
            if (dist(x[j], y[j], x[j-1], y[j-1]) <= tt) {
                tt -= dist(x[j], y[j], x[j-1], y[j-1]);
                tans += j > i;
            } else {
                break;
            }
        }
        ans = max(ans, tans);
    }

    cout << ans << endl;
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