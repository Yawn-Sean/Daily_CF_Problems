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
#define MAT vector<VC>
#define x first
#define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n; cin >> n;
    vector<int> ans(n+1);
    for(int i = n; i > 0; i --){
        if(ans[i]) continue;
        int k = i == 0? 0:31 - __builtin_clz(i);
        int msk = (1 << (k+1)) - 1;
        int tag = i ^ msk;
        if(tag <= n && !ans[i]) ans[i] = tag;
        if(tag <= n && !ans[tag]) ans[tag]= i;
    }

    int score = 0;
    for(int i = 0; i <= n; i ++) score += i ^ ans[i];
    cout << score << endl;
    for(int i = 0; i <= n; i ++) cout << ans[i] << ' ';
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
