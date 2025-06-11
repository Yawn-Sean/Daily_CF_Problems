/*
    有长度为 n 的数列 a,b,
    将数列 b 重新排列，使得数列 c 字典序最小，c[i]=a[i]^b[i].
    维护一个结构，支持：增删元素 + 查询剩余元素和某个x的最小异或值。
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
class Trie {
    struct node {
        int son[2];
        int cnt = 0;
        node() {
            son[0] = son[1] = 0;
        }
    } NIL;
    vector<node> tr;
    int idx;

public:
    Trie() : tr(1), idx(0) {}
    void insert(int x) {
        int p = 0;
        for (int k = 30; k >= 0; k--) {
            tr[p].cnt ++;
            int cur = x >> k & 1;
            if (! tr[p].son[cur]) {
                tr.push_back(NIL);
                tr[p].son[cur] = ++idx;
            }
            p = tr[p].son[cur];
        }
        tr[p].cnt++;
    }
    void remove(int x) {
        if (tr[0].cnt == 0) return;
        int p = 0;
        vector<int> path;
        for(int k = 30; k >= 0; k--) {
            path.push_back(p);
            int cur = x >> k & 1;
            if(!tr[p].son[cur] || tr[tr[p].son[cur]].cnt <= 0) return;
            p = tr[p].son[cur];
        }
        path.push_back(p);
        // 逆向递减计数
        for (int i = path.size()-1; i >= 0; i--) {
            tr[path[i]].cnt--;
        }
    }
    long long search_min_xor(int x) {
        long long res = 0;
        int p = 0;
        for (int k = 30; k >= 0; k--) {
            int v = x >> k & 1;
            if(tr[p].son[v] && tr[tr[p].son[v]].cnt > 0) {
                p = tr[p].son[v];
            } else if(tr[p].son[!v] && tr[tr[p].son[!v]].cnt > 0) {
                res += 1 << k;
                p = tr[p].son[!v];
            } else break;
        }
        return res;
    }
};
inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    Trie T;
    for(int i=1; i<=n; i++) {
        int b;
        cin >> b;
        T.insert(b);
    }
    for(int i=1; i<=n; i++) {
        int c = T.search_min_xor(a[i]);
        T.remove(c^a[i]);
        cout << c << " ";
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
