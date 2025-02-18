#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int h, m, q;
    cin >> h >> m >> q;
    vector<int> gid(h + 1,-1), b(h + 1),gpos(h+1);
    int top1 = -1,top2=0;
    for (int i = 0; i < h; i++)
    {
        if (gid[i]==-1)
        {
            top1++;
            top2=0;
            while(gid[i]==-1)
            {
            	gid[i]=top1;
            	gpos[i]=top2++;
            	i=(i+m)%h; 
            }
        }
    }
     vector<set<int>> vs(top1+1);
    for(int i=0;i<=top1;i++)
    {
    	for(int j=0;j<top2;j++)
    	{
    		vs[i].insert(j);
    	}
    }
    map<int, array<int,2>> mp;
     
    ll ans = 0;
    for (int i = 1; i <= q; i++)
    {
        char op;
        int val, hs;
        cin >> op >> val;
        if (op == '+')
        {
            cin >> hs;
            int id = gid[hs],pos=gpos[hs];
            if (*vs[id].rbegin() < pos)
            {
            	int x=*vs[id].begin();
                ans += top2 - (pos-x);
                mp[val] = {id,x};
                vs[id].erase(vs[id].begin()); 
            }
            else
            {
                int k = *vs[id].lower_bound(pos);
                ans += k-pos;
                mp[val] = {id,k};
                vs[id].erase(k); 
            }
        }
        else
        {
            int gid = mp[val][0];
            int pos = mp[val][1];
            vs[gid].insert(pos);
        }
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
