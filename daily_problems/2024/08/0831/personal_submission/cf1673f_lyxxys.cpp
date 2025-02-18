#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    需要尽可能减少 所需的路径权值和
*/
void solve(){
    vector <int> w = {0};
    // 求 格雷编码
    for (int i = 0; i < 5; ++ i){
        for (int j = (1<<i)-1; j >= 0; -- j){
            w.push_back(w[j]|(1<<2*i));
        }
    }
    vector <array<int,2>> Ps(1024);
    for (int i = 0; i < 32; ++ i){
        for (int j = 0; j < 32; ++ j){
            Ps[w[i]^(2*w[j])] = {i+1, j+1};
        }
    }

    int n, q;
    cin >> n >> q;
    int res = 0;

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n-1; ++ j){
            cout << (w[j]^w[j+1])*2 << " ";
            res +=(w[j]^w[j+1])*2;
        }
        cout << "\n";
    }
    for (int i = 0; i < n-1; ++ i){
        for (int j = 0; j < n; ++ j){
            cout << (w[i]^w[i+1]) << " ";
            res +=(w[i]^w[i+1]);
        }
        cout << "\n";
    }
    cout << flush;
    int msk = 0;
    while (q--){
        int v;
        cin >> v;
        msk ^= v;
        cout << Ps[msk][0] << " " << Ps[msk][1] << "\n" << flush;
    }

}
