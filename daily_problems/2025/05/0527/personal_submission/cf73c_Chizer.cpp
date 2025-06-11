/**
 * Problem: C. LionAge II
 * Contest: Codeforces Beta Round 66
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-05-27 20:30
 * 适度编程益脑，沉迷编程伤身，合理安排时间，享受快乐生活。
 */
#include "bits/stdc++.h"
#define rep(i, j ,k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;

int T;
int dp[105][105][26];   //在位置 i 更改 j 次后，当前字母为 k 的最大值 dp[i][j][k]
int c[26][26];
string s;
int kk;
int n;

void solve() {
    cin >> s >> kk >> n;
    rep(i, 1, n) {
        char x, y;
        int t;
        cin >> x >> y >> t;
        c[x - 'a'][y - 'a'] = t;
    }
    rep(i, 0, s.size() - 1) {
        rep(k, 0, kk) {
            rep(j, 0, 25) {
                dp[i][k][j] = -1e9;
            }
        }
    }
    rep(i, 0, s.size() - 1) {
        rep(j, 0, 25) {
            if(s[i] - 'a' == j) dp[i][0][j] = i - 1 >= 0 ? max(dp[i][0][j], dp[i - 1][0][s[i - 1] - 'a'] + c[s[i - 1] - 'a'][j]) : 0;
            else dp[i][1][j] = i - 1 >= 0 ? max(dp[i][1][j], dp[i - 1][0][s[i - 1] - 'a'] + c[s[i - 1] - 'a'][j]) : 0;
        }
    }
    rep(i, 1, s.size() - 1) {
        rep(k, 0, kk) {
            rep(j, 0, 25) {
                rep(h, 0, 25) {
                    if(s[i] - 'a' == h) {
                        dp[i][k][h] = max(dp[i][k][h], dp[i - 1][k][j] + c[j][h]);
                    } else if(k > 0) {
                        dp[i][k][h] = max(dp[i][k][h], dp[i - 1][k - 1][j] + c[j][h]);
                    }
                }
            }
        }
    }
    int ans = -1e9;
    rep(i, 0, kk) {
        rep(j, 0, 25) {
            ans = max(ans, dp[s.size() - 1][i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
