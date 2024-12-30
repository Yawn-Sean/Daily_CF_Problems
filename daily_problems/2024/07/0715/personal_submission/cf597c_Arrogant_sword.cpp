// LUOGU_RID: 149143526
#include<bits/stdc++.h>

#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}

//////////////////////////////////////////////////

const int N = 1e5 + 10;
int n, k;
int dp[N][12];
vector<int> a(N);

class BIT {
private:
    vector<int> tree;

public:
    BIT(int n) : tree(n) {}

    void add(int x, int c) {
        while (x < tree.size()) {
            tree[x] += c;
            x += x & -x;
        }
    }

    int query(int x) {
        int res = 0;
        while (x > 0) {
            res += tree[x];
            x &= x - 1;
        }
        return res;
    }
};

void solve() 
{
    
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    for (int i = 1; i <= n; i ++ ) {
        dp[i][1] = 1;
    }
    
    for (int j = 2; j <= k+1; j ++ ) {
        auto t = new BIT(N);
        for (int i = 1; i <= n; i ++ ) {
            dp[i][j] += t->query(a[i]);
            t->add(a[i], dp[i][j-1]);
        }
    }

    int ans = 0;
    for (int i = k+1; i <= n; i ++) {
        ans += dp[i][k+1];
    }
    
    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}