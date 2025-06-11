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
    int a; cin >> a;
    string s; cin >> s;
    int n = s.size();

    vector<int> num(n + 1), cnt(10 * n);
    for(int i = 0; i < n; i ++){
        int sum = 0;
        for(int j = i; j < n; j ++){
            sum += (s[j] - '0');
            cnt[sum] ++;
        }
    }

    if(a == 0){
        int t = n*(n+1) / 2;
        cout << cnt[0] * t * 2 - cnt[0] * cnt[0];
    } else {
        int ans = 0;
        for(int i = 1; i <= 9*n; i ++){
            if(a % i == 0 && a / i <= 9*n){
                ans += cnt[i] * cnt[a / i];
            }
        }
        cout << ans << endl;
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
