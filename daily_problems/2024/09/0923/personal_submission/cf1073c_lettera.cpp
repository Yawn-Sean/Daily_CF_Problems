#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
    int n;
    cin >> n;
    string s, t = "LRUD";
    cin >> s;
    int x, y;
    cin >> x >> y;
    vector<int> cnt(4);
    vector<vector<int>> pre(4, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i] == t[j])
            {
                pre[j][i]++;
                cnt[j]++;
            }
            pre[j][i] += i > 0 ? pre[j][i - 1] : 0;
        }
    }
    if (n % 2 != abs((x + y) % 2)||n<abs(x)+abs(y))
    {
        cout << -1 << endl;
        return;
    }
    else
    {
    	if(cnt[1]-cnt[0]==x&&cnt[2]-cnt[3]==y)
    	{
    		cout<<0<<endl;
    		return;
    	}
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2, f = 0;
            for (int i = 0; i + mid - 1 < n; i++)
            {
                vector<int> c(4);
                c=cnt;
                for (int j = 0; j < 4; j++)
                {
                    c[j] -= pre[j] [i + mid - 1] - (i > 0 ? pre[j][i - 1]  : 0);
                }
                int t = abs(c[1]-c[0]-x)+ abs(c[2] - c[3]-y);
                //cerr<<mid<<" "<<i<<" C "<<t<<endl;
                if (t <= mid&& t % 2 == mid % 2)
                {
                	f=1;
                    break;
                }
            }
            if(f)
            {
            	 r = mid;
            }
            else
            {
            	l = mid + 1;
            }
           // cerr<<l<<" "<<r<<endl;
        }
        cout<<l<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
