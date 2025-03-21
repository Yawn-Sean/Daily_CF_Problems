#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> a(n+1); 
    for(int i=1; i<=n; i++)
        cin >> a[i];
    auto change = [&](string s, string t) {
        int tot = 0;
        for(int i=0; i<7; i++) {
            if(s[i] == '1' && t[i] == '0')
                return -1;
            if(s[i] == '0' && t[i] == '1')
                tot ++;
        }
        return tot;
    };
    vector<string> t(10);
    t[0] = "1110111";
    t[1] = "0010010";
    t[2] = "1011101";
    t[3] = "1011011";
    t[4] = "0111010";
    t[5] = "1101011";
    t[6] = "1101111";
    t[7] = "1010010";
    t[8] = "1111111";
    t[9] = "1111011";
    vector<vector<int>> cost(n+1, vector<int>(10));
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            cost[i][j] = change(a[i], t[j]);
        }
    }
    vector<vector<int>> dp(n+2, vector<int>(k+1, 0));
    dp[n+1][0] = 1;
    for(int i=n; i>=1; i--) {
        for(int c=0; c<=9; c++) {
            int t = cost[i][c];
            if(t == -1) continue;
            for(int j=t; j<=k; j++) {
                dp[i][j] |= dp[i+1][j-t];
            }
        }
    }
    int tot = 0;
    vector<int> res;
    for(int i=1; i<=n; i++) {
        bool p = 0;
        for(int c=9; c>=0; c--) {
            int t = cost[i][c];
            if(t == -1) continue;
            if(k-tot-t >= 0 && dp[i+1][k-tot-t]) {
                res.push_back(c);
                p = 1;
                tot += t;
                break;
            }
        }
        if(!p) {
            cout << "-1" << endl;
            return;
        }
    }
    for(int x: res)
        cout << x;
}
