/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int k; cin >> k;
    if (k % 2 == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int sz = k - 1;
        int n = 4 * k - 2;
        int m = k * n / 2;
        cout << n << ' ' << m << endl;

        for(int i = 1; i <= sz; i ++){
            for(int j = 1; j <= sz; j ++){
                cout << i << ' ' << j + sz << endl;
                cout << i + sz*3 << ' ' << j + 2*sz << endl;
            }
        }

        for(int i = 1; i <= sz; i +=2){
            cout << i << ' ' << i + 1 << endl;
            cout << 3*sz + i << ' ' << 3*sz + i + 1 << endl;
        }

        for(int i = 1; i <= sz; i ++){
            cout << i + sz << ' ' << sz*4 + 1 << endl;
            cout << i + 2*sz << ' ' << sz*4 + 2 << endl;
        }
        cout << sz*4 + 1 << ' ' << sz*4 + 2 << endl;
    }

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
