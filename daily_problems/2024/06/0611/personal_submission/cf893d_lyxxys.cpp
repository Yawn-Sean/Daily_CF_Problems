#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using ull = unsigned long long;
const int N = 1011, P = 1e9+7, inf = 1e9;

void solve(){
    int n, d;
    cin >> n >> d;
    vector <int> trans(n+1);
    for (int i = 1; i <= n; ++ i) cin >> trans[i];
    int res, cost1, cost2;
    res = cost1 = cost2 = 0;
    // 贪心的根据左右边界调整
    for (int i = 1; i <= n; ++ i){
        if (!trans[i]){
            if (cost1 < 0) cost1 = 0;
            if (cost2 < 0) cost2 = d, ++ res;
        }
        cost1 += trans[i], cost2 += trans[i];
        if (cost1 > d){
            res = -1;
            break;
        }
        if (cost2 > d) cost2 = d;
    }
    cout << res << "\n";
}
 
