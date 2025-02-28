#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
const int N = 4E5 + 5;
ll st1[20][N]; // 祖先
ll st2[20][N]; // 到第2^i级祖先的最大点权,[l,r)
ll st3[20][N]; // 在题目要求的序列上做倍增,求祖先
ll st4[20][N]; // 点权和,[l,r)
ll ll_inf=2E15;
int int_inf=1E9;
void solve()
{
    // long long
    ll last = 0, cnt = 1;
    int q;
    cin >> q;
    //把节点0的点权当成inf结果没有影响
    for (int i = 0; i < 20; i++)
    {
    	if(i)
    	{
    		st2[i][1]=int_inf;
    		st4[i][1]=ll_inf;
    	}
        st2[i][0]=int_inf;
        st4[i][0]=ll_inf;
    }
    while (q--)
    {
        ll op, R, X;
        cin >> op >> R >> X;
        R^=last;
        X^=last;
        if (op == 1)
        {
        	ll u=++cnt;
            st1[0][u] = R;//祖先
            st2[0][u]=X;//最大点权
            st4[0][u]=X;
            for (int i = 1; i < 20; i++)
            {
            	 
                st1[i][u] = st1[i - 1][st1[i - 1][u]];
                st2[i][u] = max(st2[i-1][u],st2[i-1][st1[i-1][u]]);
            }
            u=R;
            for(int i=19;i>=0;i--)//找到第一个>=X的点
            {
            	if(st2[i][u]<X)
            	{
            		u=st1[i][u];
            	}
            }
            st3[0][cnt]=u;
            u=cnt;
            for(int i=1;i<20;i++)
            {
            	st3[i][u]=st3[i-1][st3[i-1][u]];
            }
             
            for(int i=1;i<20;i++)
            {
            	st4[i][u]=st4[i-1][u]+st4[i-1][st3[i-1][u]];
            	if(st4[i][u]>ll_inf)
            	{
            		for(int j=i;j<20;j++)
            		{
            			st4[j][u]=ll_inf;
            		}
            		break;
            	}
            }
        }
        else
        {
        	ll u=R;
        	ll ans=0;
        	for(int i=19;i>=0;i--)
        	{
        		if(st4[i][u]<=X)
        		{
        			X-=st4[i][u];
        			u=st3[i][u];
        			ans+=1<<i;
        		}
        	}
        	cout<<ans<<"\n";
        	last=ans;
        }
    }
    cerr<<st4[0][1];
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
