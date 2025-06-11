/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e9
#define INFF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)


void solve(){
    auto cmpstr = [&](string s1, string s2) ->int {
        if(s1 == s2) return 0;
        if(s1.size() == s2.size()){
            For(i,0,s1.size()-1){
                if(s1[i] != s2[i]) return s1[i] > s2[i]? 1:-1;
            }
        }
        return s1.size() > s2.size()? 1:-1;
    };
    auto check = [&](string s){
        for(auto i:s) if(i != '9') return false;
        return true;
    };

    int L; cin >> L;
    string s; cin >> s;
    string sub_s = s.substr(0,L);
    if(s.size() % L == 0 && !check(s)){
        bool ok1 = true;
        for(int i = 0; i < s.size(); i += L){ // 大了 不加1， 小了 加1 
            bool ok2 = false;
            if(cmpstr(sub_s, s.substr(i,L)) == 1){ok1 = false; break;}
            else if(cmpstr(sub_s, s.substr(i,L)) == -1){ok2 = true; break;}
            if(!ok1 || ok2) break;
        }
        if(ok1){
            Rof(i, sub_s.size()-1, 0){
                if(sub_s[i] == '9') sub_s[i] = '0';
                else {sub_s[i] ++; break;}
            }
        }
        For(i,1,s.size()/sub_s.size()) cout << sub_s;
           
    } else {
        sub_s = "1" + string(L-1, '0');
        For(i,1,s.size()/L + 1) cout << sub_s;
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
