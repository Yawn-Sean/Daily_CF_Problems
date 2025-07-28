
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10;
const int mod = 998244353;

void solve()
{

    int n;
    cin >> n;
    vector<int> f(n+1), nums(n+1);
    for(int i = 1; i <= n;i ++)cin >> nums[i];
    int res = 0;
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        int cur = 0;
        while(st.size() && nums[st.top()] <= nums[i]) {
            cur = max(cur, f[st.top()]);
            st.pop();
        }
        if(st.size()) {
            res = max(res, cur + 1);
            f[i] = cur + 1;
        }
        st.push(i);
    }
    cout << res << '\n';

}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
