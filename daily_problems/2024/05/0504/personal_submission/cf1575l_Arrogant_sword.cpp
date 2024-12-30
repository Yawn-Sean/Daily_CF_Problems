
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
const int N = 2e5 + 10;
const int inf = 1e14;
class BIT {
private:
    vector<int> tree;

public:
    BIT(int n) : tree(n) {}

    void add(int x, int c) {
        while (x < tree.size()) {
            tree[x] = max(tree[x], c);
            x += x & -x;
        }
    }

    int query(int x) {
        int res = 0;
        while (x > 0) {
            res = max(res, tree[x]);
            x &= x - 1;
        }
        return res;
    }
};
void solve(int _) 
{
    int n;
    cin >> n;
    vector<PII> a;
    for (int i = 1, x; i <= n; i ++ ) {
        cin >> x;
        if (i >= x) a.emplace_back(i - x, x);
    }
    sort(all(a));
    auto t = new BIT(N);
    int ans = 0;
    for (int i = 0; i < SZ(a) ; i ++ ) {
        int y = t->query(a[i].y - 1);
        t->add(a[i].y, y + 1);
        ans = max(ans, y + 1);
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