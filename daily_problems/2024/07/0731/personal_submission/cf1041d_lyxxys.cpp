#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9 + 7;
const double inf = 1e9;
double eps = 1e-10;

void solve(){
    int n, h;
    cin >> n >> h;
    vector<array<int,2>> segs(n+2);
    for (int i = 1; i <= n; ++ i) cin >> segs[i][0] >> segs[i][1];

    ll res = 0;
    {
        ll sum = 0;
        for (int i = 1, j = 0; i <= n; ++ i){
            while (j==0 || (j+1 <= n && sum+segs[j+1][0]-segs[j][1] < h)){
                if (j != 0) sum += segs[j+1][0]-segs[j][1];
                ++ j;
            }
            res = max(res, segs[j][1]-segs[i][0] + (h-sum));
            if (i != n) sum -= segs[i+1][0]-segs[i][1];
            // 补回原来的高度
        }
    }
    cout << res << "\n";
}
