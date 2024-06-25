#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+10);
    unordered_map<int,int> mp(n+10);
    
    for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
    sort(a.begin()+1,a.begin()+1+n);
    for(int s=n+1;s>=2;s--)
    {
        int ss = 0;
        bool pd = true;
        for(auto[zl,cnt] : mp){
            if(cnt%s==0)
            {
                ss+=cnt/s;
            }
            else if(cnt/s<(s-(cnt%s)-1))
            {
                pd = false;
                break;
            }
            else ss+=cnt/s+(cnt%s!=0);
        }
        if(pd)
        {
            cout<<ss<<endl;
            return;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    // t=1;
    while (t--)
    {
        solve();
    }
}
