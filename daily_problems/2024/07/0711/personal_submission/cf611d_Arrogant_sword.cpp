
#include<bits/stdc++.h>
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
const int mod = 1e9 + 7;
void solve(int _) 
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n+1);
    rep(i, n) {
        a[i] = s[i-1] - '0';
    }
    // s[i:]与s[j:]的最长公共前缀的长度
    vector lcp(n+1, vector<int>(n+1));
    for (int i = n; i >= 1; i -- ) {
        for (int j = n; j >= 1; j -- ) {
            if (a[i] == a[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
        }
    }

    // f[i][j]表示结尾数字为s[j : i]的合法方案数。
    vector f(n+1, vector<int>(n+1)), sum(n+1, vector<int>(n+1));
    rep(i, n) f[i][1] = 1;

    auto check = [&](int i, int j) -> bool {
        // 以两个数相同
        if (lcp[i][j] >= j - i) return false;
        return (a[i + lcp[i][j]] < a[j + lcp[i][j]]);
    };

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            if (a[j] == 0) continue;
            // 先算长度小于当前长度的数的贡献，再处理相等的情况
            int k = 2 * j - i; k = max(1, k);
            f[i][j] = (f[i][j] + sum[j-1][j-1] - sum[j-1][k - 1] + mod) % mod;
            k --;
            if (k == 2 * j - i - 1 && check(k, j)) {
                f[i][j] = (f[i][j] + f[j-1][k]) % mod;
            } 
        }
        for (int j = 1; j <= i; j ++ ) {
            sum[i][j] = (sum[i][j-1] + f[i][j]) % mod;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        ans = (ans + f[n][i]) % mod;
    }
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