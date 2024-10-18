#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9+7, inf = 1e9;
/*
    f[i] 表示某个人先手取完前i个数时的最优差值
*/
void solve(){
    int n;
    cin >> n;
    vector <int> Pre(n+1), A(n+1), f(n+1);
    for (int i = 1; i <= n; ++ i) cin >> A[i];
    for (int i = 1; i <= n; ++ i) Pre[i] = Pre[i-1] + A[i];

    f[n-1] = Pre[n];
    int Max = f[n-1];
    for (int i = n-2; i >= 1; -- i){
        f[i] = max(f[i+1], Pre[i+1]-f[i+1]);
    }

    cout << f[1] << "\n";
}
