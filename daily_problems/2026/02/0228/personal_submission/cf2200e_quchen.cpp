#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
int n;
ll a[N];
ll pr[N];
ll cnt[N];

bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[i-1])continue;
        else return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int  cmd = 1;
    if(check())
    {
        cout<<"Bob\n";
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i]]>1)
        {
            cmd = 0;
        }
        a[i] = pr[a[i]];
    }

    if(cmd==0)cout<<"Alice\n";
    else 
    {
        if(check())cout<<"Bob\n";
        else cout<<"Alice\n";
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=N;i++)
    {
        pr[i]=i;
    }
    for(int i=2;i<=N;i++)
    {
        if(pr[i]==i)
        {
            for(int j=i;j<=N;j+=i)
            {
                pr[j]=i;
                cnt[j]++;
            }
        }
    }
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
