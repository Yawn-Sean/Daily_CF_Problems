#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 510;
int n;
char s[N][N];
int col[N];
void solve(){
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> s[i][j];
            if (s[i][j] == '1'){
                ans = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (s[j][i] == '1'){
                col[i]++;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            int num = 0, mx = 0;
            for (int k = 1; k <= n; ++k){
                if (s[i][k] == s[j][k] && s[i][k] == '1'){
                    num++;
                    mx = max(mx, col[k]);
                }
            }
            ans = max(ans, min(num, mx));


        }
    }    
    cout << ans << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    
    return 0;
}