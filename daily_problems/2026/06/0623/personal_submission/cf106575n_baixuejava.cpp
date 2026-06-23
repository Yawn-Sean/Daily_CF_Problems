#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <cmath>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

bool mult_test = false;
const char ln = '\n';
const int mod1 = 998244353, mod2 = 1e9 + 7, N = 1e6 + 7, inf = 2147483647 - 1;


void INIT(){ 
    mult_test = true;
}
void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
   
    vector<int> f(n * 2 + 2, inf);
    for(int i = 0; i < n; i++) f[b[i]] = i; // 因为是无重复, 才能这样赋值, 不然是否 f[x] 不是最小位置
    for(int v = n << 1; v >= 1; v--) f[v] = min(f[v], f[v+1]);
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        int j = f[a[i] + 1];
        if(j != inf) ans = min(ans, 1LL * i * x + 1LL * j * y);
    }
    cout << ans << ln;
}     
int main(){ 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    INIT();
    int T = 1;
    if(mult_test) cin >> T; 
    while(T --> 0) solve();
}
