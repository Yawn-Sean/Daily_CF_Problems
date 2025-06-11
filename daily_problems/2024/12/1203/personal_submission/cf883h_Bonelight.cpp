/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define VCii vector<pii>
#define MAT vector<VC>
#define MATii vector<VCii>
#define For(_tag,x,y) for(int _tag = x; _tag <= y; _tag ++)
#define Rof(_tag,y,x) for(int _tag = y; _tag >= x; _tag --)
#define all(_tag) begin(_tag),end(_tag)
#define x first
#define y second



/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n; cin >> n; string s; cin >> s;
    unordered_map<char,int> mp; for(auto i:s) mp[i] ++;
    int odd = 0;
    for(auto [o,cnt]:mp) if(cnt & 1) odd ++; 

    VC yin,yinN;
    for(int i = 1, lit = sqrt(n); i <= lit; i ++){
        if(n % i == 0){
            yin.push_back(i);
            if(n / i != i) yinN.push_back(n/i);
        } 
    }
    while(yinN.size()) yin.push_back(yinN.back()), yinN.pop_back();
    reverse(all(yin));
    for(auto yi:yin){
        int cnt = n / yi;
        if(yi & 1){
            if(odd <= cnt && (odd & 1) == (cnt & 1)){
                cout << cnt << endl;
                int lv = cnt - odd;
                string mid;
                for(auto &[ch,c]:mp){
                    if(c%2 != 0) mid += string(1,ch), c --;

                    if(lv > 0) {
                        if(lv >= c) lv -= c, mid += string(c,ch), c = 0;
                        else c -= lv, mid += string(lv,ch), lv = 0;
                    }
                }
                string tmp;
                for(auto [ch,c]:mp) tmp += string(c/2,ch);
                For(i,0,cnt-1){
                    string t = tmp.substr(((yi-1)/2)*i,(yi-1)/2);
                    string t2 = t; reverse(all(t2));
                    string ans = t + string(1,mid.back()) + t2;
                    mid.pop_back();
                    cout << ans << ' ';
                }
                return;
            }
        } else {
            if(odd == 0) {
                cout << cnt << endl;
                string tmp;
                for(auto [ch,c]:mp) tmp += string(c/2,ch);
                For(i,0,cnt-1){
                    string t = tmp.substr((yi/2)*i,yi/2);
                    string t2 = t; reverse(all(t2));
                    string ans = t + t2;
                    cout << ans << ' ';
                }

                return;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    
    while(T --){
        solve();
    } 
}
