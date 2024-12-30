#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
constexpr int mod = 1e9 + 7;
i64 powf(i64 x, i64 y, i64 _mod) {
    if (y < 0) return 0;
    i64 res = 1;
    while (y > 0) {
        if (y & 1)
            res *= x, res %= _mod;
        x = x * x, x %= _mod;
        y >>= 1;
    }
    return res;
}
//二维差分 O(n^3)
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> g(n);
    for(int i=0;i<n;++i) cin>>g[i];
    vector diff(n, vi(m, 0));
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m;++j){
            if(g[i][j]=='1' && g[i-1][j] == '1' && g[i+1][j] == '1' && g[i][j-1] == '1'&& g[i][j+1] == '1')
                diff[i][j] = 1;
        }
    for(int i=0;i<n;++i)
        for(int j=1;j<m;++j)
            diff[i][j] += diff[i][j-1];

    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j)
            diff[i][j] += diff[i-1][j];

    i64 ans = 0;
    for(int up = 0;up < n; ++up){
        for(int down = up + 2;down < n; ++ down){
            int l = 0,r = 2;
            while(l < m && r < m) {
                int t = diff[down - 1][r - 1] - diff[down - 1][l] - diff[up][r - 1] + diff[up][l];
                if (t < k) r++;
                else {
                    ans += m - r ;
//                    cerr<< l << ' ' << r << ' '<< up << ' '<<down <<endl;
                    l++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}






