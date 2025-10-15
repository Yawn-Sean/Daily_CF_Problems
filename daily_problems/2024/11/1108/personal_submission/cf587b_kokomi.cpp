#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
ll a[N];
ll n, l, k;
//b中元素是循环的
//子序列需满足：1、长度<=k 2、相邻的元素在相邻的节 3、子序列单调不减 
//我们可以将所有元素都平移到第一节，这样对应的子序列一定由前nk个元素组成
//考虑第一项在第一节，第k项在第i个位置的子序列有多少个；考虑这样的子序列能平移多少次
//考虑第i节第j个位置的子序列有多少个，记为dp[i][j] i == 1为1 否则为前一节中不超过当前数字的元素对应的dp[i][j']相加
//直接算复杂度是kn^2的，但是后面求和的转移可以优化，可以把一节中的元素排序，然后求和相当于求前缀和
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(k == 1){
        cout << l % MOD;
        return 0; 
    }
    vector<ll> st_range(n);
    iota(st_range.begin(), st_range.end(), 0);
    sort(st_range.begin(), st_range.end(), [&](int i, int j) {return a[i] < a[j];});

    ll ans = 0;
    vector<ll> dp(n * k, 0);
    for(int i = 0; i < k; i++){
        int pt = 0, cur = 0;
        for(auto &j : st_range){
            int idx = i * n + j;
            if(i == 0) dp[idx] = 1;
            else{
                while(pt < n && a[st_range[pt]] <= a[j]){
                    cur += dp[(i - 1) * n + st_range[pt]];
                    if(cur > MOD) cur -= MOD;
                    pt++;
                }
                dp[idx] = cur;
            }
            ll times = (l - idx + 1) / n + 1;
            if(times){
                ans += (times % MOD * dp[idx]) % MOD;
                if(ans > MOD) ans -= MOD;
            }
        }
    }
    cout << ans;
}