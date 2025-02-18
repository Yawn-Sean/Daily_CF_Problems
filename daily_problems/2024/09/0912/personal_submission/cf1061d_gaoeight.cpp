#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int INF = int(1e9);
constexpr ll INFLL = 1E11 + 5;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

constexpr ll MOD = 1E9 + 7;
struct cmp1{
    bool operator()(pll i, pll j){
        return i.se > j.se;
    }
};
struct cmp2{
    bool operator()(pll i, pll j){
        return i.se < j.se;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, y, x;
    cin >> n >> x >> y;
    vector<pll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(), a.end(), [&](pll i, pll j){
        return i.fi < j.fi;
    });
    priority_queue<pll, vector<pll>, cmp1>usi;
    priority_queue<pll, vector<pll>, cmp2>fin;

    for(int i = 0; i < n; i++){
        while(usi.size() && usi.top().se < a[i].fi){
            fin.push(usi.top());
            usi.pop();
        }
        if(!fin.size() || (a[i].fi - fin.top().se) * y > x){
            usi.push(a[i]);
        }
        else {
            pll temp = fin.top();
            fin.pop();
            temp.se = a[i].se;
            usi.push(temp);
        }
    }
    
    ll ans = 0;
    while(fin.size()){
        pll temp = fin.top();
        ans = (ans + x + (temp.se - temp.fi) * y % MOD) % MOD;
        //cout << temp.fi << ' ' << temp.se << "\n";
        fin.pop();
    }
    //cout << "\n";
    while(usi.size()){
        pll temp = usi.top();
        ans = (ans + x + (temp.se - temp.fi) * y % MOD) % MOD;
        //cout << temp.fi << ' ' << temp.se << "\n";
        usi.pop();
    }
    cout << ans << "\n";
}
