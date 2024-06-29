#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int> ans;
    for(int j=0;j<=30;j++)
    {
        int res=(1<<30)-1;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>>j&1)
            {
                res&=a[i];
                v.push_back(a[i]);
            }
        }
        if(res%((1<<j))==0)
            ans=v;
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans)
        cout<<x<<' ';
    cout<<'\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
