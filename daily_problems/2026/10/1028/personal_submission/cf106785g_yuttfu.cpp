#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> x(n+1,0);
    vector<int> y(n+1,0);
    vector<int> st(n+1,0);
    map<int,int> cntx,cnty;
    int minx = INT_MAX,maxx = INT_MIN,miny = INT_MAX,maxy = INT_MIN;
    for(int i = 1;i <= n;i++){
        cin >> x[i] >> y[i];
        minx = min(minx,x[i]);
        miny = min(miny,y[i]);
        maxx = max(maxx,x[i]);
        maxy = max(maxy,y[i]);
    }
    vector<pair<int,int>> res;
    res.push_back({minx,miny});
    res.push_back({minx,maxy});
    res.push_back({maxx,miny});
    res.push_back({maxx,maxy});
    for(auto [xx,yy] : res){
        bool flag = false;
        for(int i = 1;i <= n;i++){
            if(x[i] == xx && y[i] == yy){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
