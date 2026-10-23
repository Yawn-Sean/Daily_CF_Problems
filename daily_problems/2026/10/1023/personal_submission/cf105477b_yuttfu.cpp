#include <iostream>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;
const int N = 410;
ll c[N][N];

void init(){
    for(int i = 0;i < N;i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j < i;j++){
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
        }
    }
}

ll C(int n,int m){
    if(m < 0 || m > n) return 0;
    return c[n][m];
}

ll F(int l,int H){
    int D = H + 2;
    ll ans =  0;
    for(int k = -(l/D);k <= (l+1)/D;k++){
        ans = (ans + C(2*l,l-k*D) - C(2*l,l+1-k*D) + mod) % mod;
    }
    return ans;
}

void solve(){
    int l,h;
    cin >> l >> h;
    ll ans = (F(l,h) - F(l,h-1)+mod) % mod;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}