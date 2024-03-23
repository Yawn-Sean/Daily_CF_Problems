// dp[i]表示以i为最大元素的最大集合大小，显然有dp[i] = max(dp[j](i%j==0)) + 1;但是这么做是O(n^2)的。
// 考虑计算贡献，用当前状态去更新其他状态，即用dp[i]去更新dp[2*i],dp[3*i ]……。
// 这么做时间复杂度为O(n logn)，感觉和埃氏筛的思想差不多，用因数去更新它的倍数。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 1e6 + 10;
void solve() 
{
    int n;
    cin >> n;

    vector<int> dp(N);
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        dp[x] ++;
        for (int j = i; j < N; j += i) {
            dp[j] = max(dp[j], dp[i]);
        }
    }

    cout << *max_element(all(dp)) << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}