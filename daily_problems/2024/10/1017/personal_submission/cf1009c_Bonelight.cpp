/*
    Bonelight * v *
    20241014：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m; cin >> n >> m;
    int sum = 0;
    while(m --){
        int x,d; cin >> x >> d;
        sum += x * n;
        if(d >= 0) sum += d * (n - 1)*n / 2;
        else{
            int t1 = n / 2 + 1;
            int t2 = (n - 1) / 2 + 1;
            sum += d * ((t1)*(t1 - 1) / 2 + (t2)*(t2 - 1) / 2);
        }
    }
    cout << fixed << setprecision(15) << (double)sum / n << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
