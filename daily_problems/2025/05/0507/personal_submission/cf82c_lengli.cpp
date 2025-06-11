#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define VI vector<int>
#define AR(x) array<int, x>
#define MX vector<VI >
#define all(x) x.begin(), x.end()
#define IOS cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(){

    IOS;

    int n;
    cin >> n;

    VI a(n+1), c(n+1, 0);
    for(int i=1; i<=n; i++) cin >> a[i];

    VI lvl(n+1, 0), nx(n+1, 0);

    {
        vector<vector<AR(2) > > g(n+1);
        for(int i=1, x, y, z; i<n; i++){
            cin >> x >> y >> z;
            g[x].pb({y, z});
            g[y].pb({x, z});
        }

        auto dfs = [&](auto &&dfs, int i, int p) -> void {
            for(auto [j, k] : g[i]){
                if(j != p){
                    c[j] = k;
                    lvl[j] = lvl[i]+1;
                    nx[j] = i;
                    dfs(dfs, j, i);
                }
            }
        };

        dfs(dfs, 1, 1);
    }

    VI ord(n-1);
    iota(all(ord), 2);
    sort(all(ord), [&](auto l, auto r){ return lvl[l] < lvl[r]; });

    MX d(n+1);
    for(int i=1; i<=n; i++) d[i].pb(i);

    VI ans(n+1, 0);

    for(int i=0, cnt=0; cnt<n; i++){
        
        for(int j : d[1]) ans[j] = i;
        cnt += d[1].size();
        d[1].clear();

        for(int j : ord){

            sort(all(d[j]), [&](auto l, auto r){ return a[l] > a[r]; });

            int kn = min((int)d[j].size(), c[j]);
            for(int k=0; k<kn; k++){
                d[nx[j]].pb(d[j].back());
                d[j].pop_back();
            }
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
