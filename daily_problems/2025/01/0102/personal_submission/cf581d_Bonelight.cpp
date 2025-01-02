/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
    #pragma GCC optimize(2)
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    bool ok = 0;
    auto draw0 = [&](int n){
        ok = 1;
        cout << n << endl;
        For(i,1,y1) cout << string(n,'A') << endl;
        For(i,1,y2) cout << string(n,'B') << endl;
        For(i,1,y3) cout << string(n,'C') << endl;
    };
    auto draw =[&](char a, char b, char c, int y, int ya, int yb, int x){
        ok = 1;
        cout << y << endl;
        For(j,1,ya) cout << string(x,a) << string(y-x,b) << endl;
        For(j,1,yb) cout << string(x,a) << string(y-x,c) << endl;
    };

    For(i1,0,1){ swap(x1,y1); 
    For(i2,0,1){ swap(x2,y2); 
    For(i3,0,1){ swap(x3,y3);
        if(x1 == x2 && x2 == x3 && y1 + y2 + y3 == x1) draw0(x1);
        else if(y1 == y2 + y3 && x2 == x3 && y1 == x1 + x2) draw('A','B','C',y1,y2,y3,x1);
        else if(y2 == y1 + y3 && x1 == x3 && y2 == x2 + x3) draw('B','A','C',y2,y1,y3,x2);
        else if(y3 == y1 + y2 && x1 == x2 && y3 == x3 + x1) draw('C','A','B',y3,y1,y2,x3);
        
        if(ok) return;
    }}}
    if(!ok) cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1;
    while(T --) solve();
    return 0;
}
