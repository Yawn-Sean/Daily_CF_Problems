#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
bool cmp1(array<int,3>a,array<int,3>b)
{
	return a[1]-a[2]<b[1]-b[2];
}
bool cmp2(array<int,3>a,array<int,3>b)
{
	return a[1]-a[2]>b[1]-b[2];
}
void solve()
{
    // long long
    int n, S;
    cin >> n >> S;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    ll cnta = 0, cntb = 0, ans = 0;
    vector<array<int,3>>c1,c2;
    for (int i = 0; i < n; i++)
    {
        if (a[i][1] > a[i][2])
        {
            cnta += a[i][0];
            c1.push_back(a[i]);
        }
        else
        {
            cntb += a[i][0];
             c2.push_back(a[i]);
        }
        ans += max(a[i][2], a[i][1]) * a[i][0];
    }
    if ((cnta + S - 1) / S + (cntb + S - 1) / S != (cnta + cntb + S - 1) / S)
    {
    	sort(c1.begin(),c1.end(),cmp1);
    	ll val1=0,val2=0;
    	for(int i=0;i<c1.size();i++)
    	{
    		ll need=min(cnta%S,c1[i][0]);
    		val1+=(c1[i][2]-c1[i][1])*need;
    		cnta-=need;
    	}
    	sort(c2.begin(),c2.end(),cmp2);
    	for(int i=0;i<c2.size();i++)
    	{
    		ll need=min(cntb%S,c2[i][0]);
    		val2+=(c2[i][1]-c2[i][2])*need;
    		cntb-=need;
    	}
    	ans=ans+max(val1,val2);
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
}
