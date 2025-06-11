#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    int ans=0,len=1,start=1;
    for(int i=2;i<=n;i++)
    {
    	if(a[i]!=a[i-1])
    	{
    		len++;
    	}
    	else
    	{
    		ans=max(ans,(len-1)/2);
    		if(len%2==0)
    		{
    			for(int j=0;j<len;j++)
    			{
    				if(j<len/2)
    				{
    					a[start+j]=a[start];
    				}
    				else
    				{
    					a[start+j]=a[i-1];
    				}
    			}
    		}
    		else
    		{
    			for(int j=start;j<=i-1;j++)
    			{
    				a[j]=a[start];
    			}
    		}
    		len=1;
    		start=i;
    	}
    }
    if(len>1)
    {
    	int i=n+1;
    	ans=max(ans,(len-1)/2);
    		if(len%2==0)
    		{
    			for(int j=0;j<len;j++)
    			{
    				if(j<len/2)
    				{
    					a[start+j]=a[start];
    				}
    				else
    				{
    					a[start+j]=a[i-1];
    				}
    			}
    		}
    		else
    		{
    			for(int j=start;j<=i-1;j++)
    			{
    				a[j]=a[start];
    			}
    		}
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
    
    {
    	cout<<a[i]<<" \n"[i==n];
    }
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
