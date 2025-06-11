#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;


const int N = 300100;
const int mod = 998244353;

int n;
int a[N];

void solve()
{
    int d;
    cin >> n >> d;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    int res = 0;
    
    // 一个比较重要的点就是其实只要在a[i] == 0的时候去修改就行了
    int s = 0;
    int mx = 0; // 维护一个{最小}的最大值，保证查询都是非负数，同时让这个数字尽可能小，这样尽可能不超过d
    for (int i = 0; i < n; i ++ )
    {
        if (a[i]) s += a[i];
        else
        {
            if (s < 0) // 非负数都ok不需要处理
            {
                // 如果没办法利用前面的查询(a[i] == 0) 或者说前面没有变，那只能自己变了
                // 然后前面的数字其实就无所谓了，最大值从当前开始算就行
                if (d - mx < -s || res == 0) res ++ , mx = 0; 
                else mx = mx - s; // 否则说明可以利用前面的0让当前这次查询合法化，让前面那个0在加个-s即可，正好保证当前为0，然后这一段的最大值也会增加-s
                s = 0; // 无论如何最后查询保证是0就是最优的，比0大对于后面就更可能造成大于d，不如变成0
            }
        }
        
        mx = max(mx, s); // 维护上一个被修改的查询处 到目前位置这一段的最大值，需要保证这个值不能大于d
        
        if (s > d)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << res << '\n';
}
    
signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	int t = 1;
// 	cin >> t;
	while (t -- ) solve();
}
