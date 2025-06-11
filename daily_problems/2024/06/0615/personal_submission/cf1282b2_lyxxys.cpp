#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18, mod = 998244353, N = 200050;

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    vector <int> nums(n+1), f(n+1), Pre(n+1);
    // f[i] 表示买前i件商品最少需要多少钱(排序后)
    for (int i = 1; i <= n; ++ i) cin >> nums[i];

    sort(nums.begin()+1, nums.end());
    for (int i = 1; i <= n; ++ i) Pre[i] = Pre[i-1] + nums[i];
    for (int i = 1; i <= n; ++ i) {
        if (i < k) f[i] = f[i-1] + nums[i];
        else f[i] = f[i-k] + nums[i];
    }
    int res = 0;
    // 要倒序遍历
    for (int i = n; i >= 1; -- i){
        if (f[i] <= p){
            res = i;
            break;
        }
    }
    cout << res << "\n";
}
