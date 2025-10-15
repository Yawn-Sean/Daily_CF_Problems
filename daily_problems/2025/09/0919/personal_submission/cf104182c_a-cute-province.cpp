#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for(int i = 1; i <= n; i++)cin >> nums[i];
    int ans = n * (n+1)/ 2 + 1;
    vector<int> stk1 = {0}, stk2 = {n+1};
    for(int i = 1; i <= n; i ++){
        while(stk1.back() != 0 && nums[i] >= nums[stk1.back()])stk1.pop_back();
        ans -= i - stk1.back();
        stk1.emplace_back(i);
    } 
    for(int i = n ; i >= 1; i--){
        while (stk2.back() != n+1 && nums[i] <= nums[stk2.back()])stk2.pop_back();
        ans -= stk2.back() - i;
        stk2.emplace_back(i); 
    }
    stk1 = {n+1}, stk2 = {n+1};
    for(int i = n; i >= 1; i --){
        while (stk1.back() != n+1 && nums[i] > nums[stk1.back()])
            stk1.pop_back();
        while (stk2.back() != n+1 && nums[i] <= nums[stk2.back()])
            stk2.pop_back();
            
            int l = 0, r = stk1.size();
            while (l < r) {
            int mid = (l + r) / 2;
            if (stk1[mid] >= stk2.back()) l = mid + 1;
            else r = mid;
            }
        ans += stk1.size()-l+1;
        stk1.emplace_back(i);
        stk2.emplace_back(i);
    }
    cout << ans << '\n';

}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
