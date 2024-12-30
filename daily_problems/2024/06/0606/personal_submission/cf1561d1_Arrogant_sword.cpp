
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
const int N = 2e5 + 10;

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> prime_factors(n+1);
    for (int i = 2; i <= n; i ++ ) {
        if (prime_factors[i] == 0) {
            prime_factors[i] = i;
            if (i <= n / i) {
                for (int j = i; j <= n; j += i) {
                    prime_factors[j] = i;
                }
            }
        }
    }
    function<vector<int>(int)> get = [&](int x) -> vector<int> {
        vector<int> ans = {1};
        while (x > 1) {
            int p = prime_factors[x];   
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c ++;
            }
            int now = SZ(ans);
            for (int i = 0; i < now; i ++ ) {
                int val = ans[i];
                for (int j = 0; j < c; j ++ ) {
                    val *= p;
                    ans.emplace_back(val);
                }
            }
        }

        return ans;
    };
    vector<int> dp(n+1), s(n+1);
    dp[1] = 1; s[1] = 1;
    int last = 0;
    for (int i = 2; i <= n; i ++ ) {
        dp[i] = s[i-1];
        int cur = 0;
        for (int x: get(i)) {
            if (x > 1) {
                cur = (cur + dp[i / x]) % m;
                cur = (cur - dp[(i - 1) / x] + m) % m ;
            }
        }
        cur = (cur + last) % m;
       
        dp[i] = (dp[i] + cur) % m;
        s[i] = (s[i-1] + dp[i]) % m;
        last = cur;
        
    }
    cout << dp[n] << endl;
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