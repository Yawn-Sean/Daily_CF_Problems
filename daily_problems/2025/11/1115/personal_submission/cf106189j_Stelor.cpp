#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 210;
int n, a[N];
int dp[N][N];
vector<array<int, 2>> lst[N][N];
vector<int> ans[N][N];
int st[N];
void work(int l, int r){
    for (auto [subl, subr]: lst[l][r]){
        for (auto p: ans[l][r]){
            st[p] = 1;
        }
        work(subl, subr);
    }

}
bool check(int x, int y){
    if (x % y == 0 || y % x == 0) return true;
    return false;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if (check(a[i], a[j]) && dp[i + 1][j - 1] + 2 > dp[i][j]){
                dp[i][j] = dp[i + 1][j - 1] + 2;
                lst[i][j].clear();
                ans[i][j].clear();
                ans[i][j].push_back(i);
                ans[i][j].push_back(j);
                lst[i][j].push_back({i + 1, j - 1});
            }else{
                dp[i][j] = dp[i + 1][j - 1];
                lst[i][j].clear();
                lst[i][j].push_back({i + 1, j - 1});                
            }
            for (int k = i; k < j; ++k){
                if (dp[i][k] + dp[k + 1][j] > dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k + 1][j];
                    lst[i][j].clear();
                    lst[i][j].push_back({i, k});
                    lst[i][j].push_back({k + 1, j});
                }
            }
        }
    }    
    int len = n - dp[1][n];
    cout << len << endl;
    work(1, n);
    for (int i = 1; i <= n; ++i){
        if (!st[i]){
            cout << i << " ";
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}