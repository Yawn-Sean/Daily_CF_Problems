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

string rev(string s){string ss = s; reverse(all(ss)); return ss;};
void solve(){
    string s; cin >> s;
    VC fst(26,-1);
    auto toi = [&](int i){return s[i]-'A';};
    int key = -1,key2 = -1;
    For(i,0,26) {
        if(fst[toi(i)] == -1) fst[toi(i)] = i;
        else if(fst[toi(i)] != -1 && i - fst[toi(i)] != 1) {key = fst[toi(i)], key2 = i; break;}
    }
    if(key == -1) return void(cout << "Impossible" << endl);
    int mid = key2 - key - 1;
    int lv1 = 13 - (mid-mid/2);
    string s1 = s.substr(key+1+mid/2, mid-mid/2);
    string s2 = rev(s.substr(key+1, mid/2));

    if(27 - (key2+1) >= lv1){
        s1 += s.substr(key2+1,lv1);
        s2 += s[key] + rev(s.substr(0,key)) + rev(s.substr(key2+1+lv1));
    } else {
        int used = lv1 - (27 - (key2+1));
        s1 += s.substr(key2+1) + s.substr(0,used);
        s2 += s[key] + rev(s.substr(used,key-used));
    }
    cout << s1 << endl << s2 << endl;   
    // cout << s1.size() << ' ' << s2.size() << endl;
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
