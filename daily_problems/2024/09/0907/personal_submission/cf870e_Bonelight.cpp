#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    class Dsu
    {   private:
            int n;
            vector<int> fa_size; // 父为size - ， 子为 fa +

        public:
            Dsu(){}
            Dsu(int _n): n(_n), fa_size(n,-1){}

            bool merge(int x, int y){
                assert(0 <= x && x < n);
                assert(0 <= y && y < n);
                int xx = f(x), yy = f(y);
                if(xx == yy) return false;
                if(-fa_size[xx] < -fa_size[yy]) swap(xx,yy);
                fa_size[xx] += fa_size[yy];
                fa_size[yy] = xx;
                return true;
            }

            int f(int x){
                assert(0 <= x && x < n);
                if(fa_size[x] < 0) return x;
                return fa_size[x] = f(fa_size[x]);
            }

            bool same(int x, int y){
                assert(0 <= x && x < n);
                assert(0 <= x && y < n);
                return f(x) == f(y);
            }

            int size(int x){
                assert(0 <= x && x < n);
                return -fa_size[f(x)];
            }

            vector<vector<int>> groups(){
                vector<int> fa(n), sizes(n);
                for(int i = 0; i < n; i ++){
                    fa[i] = f(i);
                    sizes[fa[i]] ++;
                }
                vector<vector<int>> res(n);
                for(int i = 0; i < n; i ++){
                    res[i].reserve(sizes[i]);
                }
                for(int i = 0; i < n; i ++){
                    res[fa[i]].push_back(i);
                }
                res.erase(remove_if(begin(res),end(res),[&](const auto &x){
                    return x.empty();})
                    ,end(res));
                return res;
            }
    };
    
    auto mypow = [&](int x, int y, int mod = 1e18 + 3){
        int res = 1;
        while(y){
            if(y & 1){
                res = res * x % mod; 
            }
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    };

    int n; cin >> n;
    const int mo = 1e9 + 7;
    vector<pii> ps(n);
    unordered_map<int,int> mp_x, mp_y;

    for(auto &[x,y]:ps){
        cin >> x >> y;
        mp_x[x] ++, mp_y[y] ++;
    }

    int cnt = 0;
    for(auto [x,y]:mp_x){
        mp_x[x] = cnt ++;
    }
    for(auto [x,y]:mp_y){
        mp_y[x] = cnt ++;
    }

    Dsu dsu(cnt + 1);
    vector<int> cnts(cnt + 1);

    for(int i = 0; i < n; i ++){
        int x = ps[i].first;
        int y = ps[i].second;
        dsu.merge(mp_x[x], mp_y[y]);
    }

    for(int i = 0; i < n; i ++){
        int x = ps[i].first;
        cnts[dsu.f(mp_x[x])] ++;
    }

    int ans = 1;
    for(int i = 0; i < cnt; i ++){
        if(cnts[i]){
            int c = dsu.size(i);
            ans = (cnts[i] >= c ? mypow(2, c, mo) : mypow(2, c, mo) - 1) * ans % mo;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
