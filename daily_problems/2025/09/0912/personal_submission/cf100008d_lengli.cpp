#include <bits/stdc++.h>
using namespace std;

static vector<vector<int>> buildPrefix(const vector<pair<int,int>>& pts, int n) {
    vector<vector<int>> ps(n+1, vector<int>(n+1, 0));
    for (auto [x,y] : pts) ps[x][y] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
    return ps;
}

inline int query(const vector<vector<int>>& ps,int x1,int y1,int x2,int y2){
    return ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  
    if(!(cin >> T)) return 0;
    while(T--){
        int n,w,l;
        cin >> n >> w >> l;
        vector<pair<int,int>> pts(w);
        for(auto &p:pts) cin >> p.first >> p.second;

        auto ps = buildPrefix(pts,n);

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        int best = 0;

        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                int side = dp[i-1][j-1]+1;
                while(side>0 && query(ps,i-side+1,j-side+1,i,j)>l) --side;
                dp[i][j]=side;
                best = max(best,side);
            }
        }
        cout << 1LL*best*best << '\n';
    }
    return 0;
}
