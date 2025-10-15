#include <bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> xs(n), ys(n);
    int r;
    for(int i = 0; i < n; i++)
        cin >> xs[i] >> ys[i] >> r;
    auto prt = [&](const vector<int>& lst){
        cout << string(n - 1, '(');
        for(int i = 0; i < n; i++){
            if(i) cout << '+';
            cout << '(' << lst[i] / 2 << "*((1-abs((t-" << i << ")))+abs((1-abs((t-" << i << "))))))";
            if(i) cout << ')';
        }
        cout << endl;
    };
    prt(xs);
    prt(ys);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
