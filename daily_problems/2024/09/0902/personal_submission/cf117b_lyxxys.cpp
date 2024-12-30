#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){            
    int a, b, p;
    cin >> a >> b >> p;
    int p10 = int(1e9)%p;
    for (int i = 0, v = 0; i < min(a+1, p); ++ i){
        if ((-v + p)%p > b){
            cout << 1 << " " << setw(9) << setfill('0') << i << "\n";
            return;
        }
        v += p10, v %= p;
    }
    cout << 2 << "\n";
}
