#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int mm = 1e9;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++) cin>>a[i];
    int cz = 1;
    bool pd = false;
    int mmax = 0;
    for(int i=2;i<=n;i++)
    { 
        if(a[i]-a[i-1]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(!pd&&abs(a[i] - a[i-1])!=1)
        {
            cz = abs(a[i] - a[i-1]);
            pd = true;
        }
        else if(pd&&abs(a[i] - a[i-1])!=1&&cz!=abs(a[i] - a[i-1]))
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if(pd)
    {
        for(int i=2;i<=n;i++)
        {
            if(abs(a[i]-a[i-1])==1)
            {
                if(abs((a[i]-1)%cz-(a[i-1]-1)%cz)!=1||((a[i]-1)/cz!=(a[i-1]-1)/cz))
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    if(pd)
    {
        cout<<"YES"<<endl;
        cout<<mm<<" "<<cz<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<1<<" "<<mm<<endl;
        return;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}
