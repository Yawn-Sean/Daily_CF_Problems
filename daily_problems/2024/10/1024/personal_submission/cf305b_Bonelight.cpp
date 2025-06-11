/*
    Bonelight * v *
    20241024：CF,Goodnight
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int son,mom; 
    {
        cin >> son >> mom;
        int d = __gcd(son,mom);
        son /= d, mom /= d;
    }
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    if(n > 1 && a[n - 1] == 1){
        a[n - 2] ++; n --;
        a.pop_back();
    }


    vector<int> ans;
    while(mom){
        ans.push_back(son / mom);
        son %= mom;
        swap(son,mom);
    }
    // for(auto i:ans) cout << i << ' '; cout << endl;
    // for(auto i:a) cout << i << ' '; cout << endl;
    cout << (a == ans? "YES":"NO") << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
