#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    string s, op;
    cin >> s >> op;
    DSU R = DSU(n+2), L = DSU(n+2);
    vector<int> l(n+2), r(n+2);
    stack<int> stk;
    s = " " + s;
    for(int i = 1 ; i <= n; i++){
        if(s[i] == ')'){
            if(s[stk.top()] == '('){
                l[i] = stk.top();
                r[stk.top()] = i;
                stk.pop();
            }
            else stk.push(i);
        }
        else stk.push(i);
    }
    for(int i = 0 ; i< m; i++){
        char x = op[i];
        if(x == 'R'){
            p = R.find(p+1);
        }
        else if(x == 'L'){
            p = L.find(p-1);
        }
        else{
            if(s[p] == '('){
                R.merge(r[p]+1, p);
                L.merge(p-1, r[p]);
                int ed = R.find(p);
                if(ed <= n)p = ed;
                else p = L.find(p-1);
            }
            else{
                L.merge(l[p]-1, p);
                R.merge(p+1, l[p]);
                int ed = R.find(p+1);
                if(ed <= n)p = ed;
                else p = L.find(l[p]-1);
            }
        }
    }
    for(int i = 1 ; i <= n; i++){
        if(R.find(i) != i)i = R.find(i);
        if(i <= n)cout << s[i];
    }
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
