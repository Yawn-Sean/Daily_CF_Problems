
#include<bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;


//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int inf = 0;
    struct SegmentTree {
    int n;
    struct node {
        int l, r;
        int max, j;
    };
    std::vector<node> t;
    std::vector<int> a;
    SegmentTree() {}
    void init(int n) {
        this -> n = n;
        t.assign(4 * n + 1, (node){0, 0, 0, n+10});
        a.assign(n + 1, 0);
        build(1, 1, n);
    }
    void pushup(int u) {
        if (t[u << 1].max > t[u << 1 | 1].max) {
            t[u].max = t[u << 1].max;
            t[u].j = t[u << 1].j;
        } else if (t[u << 1].max < t[u << 1 | 1].max) {
            t[u].max = t[u << 1 | 1].max;
            t[u].j = t[u << 1 | 1].j;
        } else {
            t[u].max = t[u << 1].max;
            t[u].j = min(t[u << 1].j, t[u << 1 | 1].j);
        }   
    }
    void build(int u, int l, int r) {
        t[u] = {l, r, 0, n+10};
        if (l == r) {
            return ;
        }
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void update(int u, int l, int r, int val, int id) {
        if (t[u].l >= l && t[u].r <= r) {
            
            if (val > t[u].max) {
                t[u].max = val;
                t[u].j = id;
            } else if (val == t[u].max) {
                t[u].j = min(t[u].j, id);
            }
            return ;
        }
       
        int mid = t[u].l + t[u].r >> 1;
        if (l <= mid) update(u << 1, l, r, val, id);
        if (mid < r) update(u << 1 | 1, l, r, val, id);
        pushup(u);
    }
    PII query(int u, int l, int r) {
        if (t[u].l >= l && t[u].r <= r) {
            return {t[u].max, t[u].j};
        }
        
        PII res = {0, n+10};
        int mid = t[u].l + t[u].r >> 1;
        
        if (l <= mid && mid < r) {
            PII t1 = query(u << 1, l, r); PII t2 = query(u << 1 | 1, l, r);
            if (t1.first > t2.first) {
                res.first = t1.first;
                res.second = t1.second;
            } else if (t1.first < t2.first) {
                res.first = t2.first;
                res.second = t2.second;
            } else {
                res.first = t1.first;
                res.second = min({res.second, t1.second, t2.second});
            }
            return ;
        }
        
        if (l <= mid) {
            PII t = query(u << 1, l, r);
            if (t.first >= res.first) {
                res.first = t.first;
                res.second = min(res.second, t.second);
            }
        }
        if (mid < r) {
            PII t = query(u << 1 | 1, l, r);
            if (t.first >= res.first) {
                res.first = t.first;
                res.second = min(res.second, t.second);
            }
        }
        return res;
    }
};
void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1), dp(n+20);
    vector g(20, vector<int>(n+10));
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        g[0][i] = a[i];
    }
    for (int i = 1; i <= 18; ++i) for (int j = 1; j + (1 << i) - 1 <= n; ++j) g[i][j] = max(g[i - 1][j], g[i - 1][j + (1 << i - 1)]); 

    function<int(int, int)> gmax = [&](int l, int r) -> int {
        if (l > r) return 0; 
        int k = __lg(r - l + 1); 
        return max(g[k][l], g[k][r - (1 << k) + 1]); 
    };

    // 线段树值域中最大的dp值，pos维护每个dp值对应的最小下标
    SegmentTree tr;  tr.init(n+10);
    vector<int> pos(n+10); int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        auto [mx, j] = tr.query(1, 1, a[i]);
        dp[i] = mx + 1;
        if (j > n) j = 0;
        if (gmax(j+1,i-1) >= a[i]) {
            dp[i] ++;
        }
        ans = max(ans, dp[i]);
        if (pos[dp[i]]) pos[dp[i]] = min(pos[dp[i]], i);
        else pos[dp[i]] = i;
        tr.update(1, a[i], a[i], dp[i], i);
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