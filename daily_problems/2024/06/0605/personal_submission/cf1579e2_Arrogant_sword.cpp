
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
void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    set<int> s;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        s.insert(a[i]);
    }   

    map<int,int> mp, cc;
    int idx = 1;
    for (int x: s) {
        mp[x] = idx ++;
    }

    int ans = 0;
    BIT *tr = new BIT(n * 2);

    for (int i = 1; i <= n; i ++ ) {
        a[i] = mp[a[i]];
        int cnt = tr->query(a[i]);
        ans += min(cnt - cc[a[i]], i - 1 - cnt);
        cc[a[i]] ++;
        tr->add(a[i], 1);
    }

    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}