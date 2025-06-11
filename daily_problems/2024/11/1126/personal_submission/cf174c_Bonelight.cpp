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
#define MAT vector<vector<int>> 

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+2);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n+1; i >= 1; i --) a[i] -= a[i-1];

    vector<int> L,R;
    for(int i = 1; i <= n+1; i ++){
        if(a[i] >= 0){
            for(int j = 0; j < a[i]; j ++) L.push_back(i);
        } else {
            for(int j = 0; j < -a[i]; j ++) R.push_back(i-1);
        }
    }

    cout << L.size() << endl;
    for(int i = 0; i < L.size(); i ++) cout << L[i] << ' ' << R[i] << endl;
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
