#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const ll N = 5010,mod = 1000000007;

ll T,n,m,f[N][N],last[N][30];
char s[N],t[N];

void build_last() {
    vector<int> pre(30,0); 
    
    for (int i = 1; i <= m; ++i) {
        for (int c = 0; c < 26; ++c)  
            last[i][c] = pre[c];
        int ch = t[i] - 'a';
        pre[ch] = i;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> s + 1 >> t + 1;

    n = strlen(s + 1);
    m = strlen(t + 1);

    build_last();
    
    for (int i = 1;i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int p = last[j][s[i] - 'a'];
            
            if (s[i] == t[j]) {
                f[i][j] = (1 + f[i - 1][j - 1] % mod + f[i][p] % mod) % mod;
            } else {
                f[i][j] = f[i][p];
            }
        }
    }
    
//    for (int i = 1;i <= n; i++) {
//    	for (int j = 1; j <= m; j++) {
//    		cout << f[i][j] << " ";
//		}
//		
//		cout << "\n";
//	}
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + f[i][m]) % mod; 
    }
    
    cout << ans << "\n";

    return 0;
}
