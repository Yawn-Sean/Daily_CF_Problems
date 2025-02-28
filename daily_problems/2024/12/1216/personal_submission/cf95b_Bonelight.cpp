/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define int long long
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
    string s; cin >> s;
    int n = s.size();
    auto cmp = [&](string a, string b){
        if(a.size() != b.size()) return a.size() > b.size()? 1:-1;
        For(i,0,n-1){
            if(a[i] != b[i]) {return (a[i] > b[i])? 1:-1;}
        }
        return 0;
    };

    if(n % 2 == 1){
        n ++;
        cout << string(n/2,'4') << string(n/2,'7') << endl;
    } else {
        string mx = string(n/2,'7') + string(n/2,'4');
        if(cmp(mx, s) == -1) {
            cout << "11" << endl;
            n += 2;
            cout << string(n/2,'4') << string(n/2,'7') << endl;            
        } else {
            int x = n/2;
            string ans = s;
            int c4 = x, c7 = x;
            bool flg = false;

            for (int i = 0; i < n; i ++) {
                if (flg) {
                    if (c4) ans[i] = '4', c4 --;
                    else ans[i] = '7', c7 --;
                }
                else {
                    if (s[i] == '4') {
                        if (c4) ans[i] = '4', c4 --;
                        else ans[i] = '7', c7 --, flg = true;
                    }
                    else if (s[i] > '4' && s[i] <= '7' && c7) {
                        if (s[i] != '7') flg = true;
                        ans[i] = '7', c7 --;
                    }
                    else if (s[i] > '4') {
                        flg = true;
                        for (int j = i - 1; j >= 0; j --) {
                            if (ans[j] == '4') {
                                if (c7) {
                                    c4 ++, c7 --, ans[j] = '7';
                                    i = j;
                                    break;
                                }
                                else c4 ++;
                            }
                            else c7 ++;
                        }
                    }
                    else {
                        flg = true;
                        if (c4) ans[i] = '4', c4 --;
                        else ans[i] = '7', c7 --;
                    }
                }
            }
            cout << ans;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; //cin >> T;
    while(T --) solve();
    return 0;
}
