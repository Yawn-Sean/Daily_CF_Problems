/*
    Bonelight (=v=)
    20251115 Bonelight's submission for 106189/problem/J
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF (int)2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define ForR(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define RofR(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define For(_i,_l,_r) for(int _i = _l; _i < _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i > _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int n; cin >> n;
    VC nums(n); For(i,0,n) cin >> nums[i];
    MAT dp(n, VC(n));

    For(gap,1,n){
        For(l,0,n-gap){
            int r = l + gap;
            dp[l][r] = dp[l+1][r-1];

            if(nums[l] % nums[r] == 0 || nums[r] % nums[l] == 0){
                dp[l][r] += 2;
            }

            For(k,l,r){
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
        }
    }

    VC used(n);
    auto check = [&](auto &self, int l, int r){
        if(l >= r) return;

        For(k,l,r){
            if(dp[l][r] == dp[l][k] + dp[k+1][r]){
                self(self,l,k);
                self(self,k+1,r);
                return;
            }
        }
        if(nums[l] % nums[r] == 0 || nums[r] % nums[l] == 0){
            used[l] = 1;
            used[r] = 1;
        }
        self(self,l+1,r-1);
    };

    check(check,0, n-1);

    cout << n - dp[0][n-1] << endl;
    For(i,0,n){
        if(used[i] == 0){
            cout << i+1 << ' ';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1;
    while(T --) solve();
    return 0;
}
