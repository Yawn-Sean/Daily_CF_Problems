
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int mod = 1e9 + 7;
class BIT {
private:
    vector<int> tree;

public:
    BIT(int n) : tree(n) {}

    void add(int x, int c) {
        while (x < tree.size()) {
            tree[x] = (tree[x] + c + mod) % mod;
            x += x & -x;
        }
    }

    int query(int x) {
        int res = 0;
        while (x > 0) {
            res = (res + tree[x] + mod) % mod;
            x &= x - 1;
        }
        return res;
    }
};

const int N = 1e6 + 10;
void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    BIT *t = new BIT(N);
    vector<int> dp(N);
    for (int i = 1; i <= n; i ++ ) {
        int x = (a[i] + (a[i] * t->query(a[i]) % mod )) % mod;
        t->add(a[i], -dp[a[i]]);
        dp[a[i]] = x;
        t->add(a[i], dp[a[i]]);
    }
    int ans = 0;
    for (int i = 1; i < N; i ++ ) {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
   // cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}