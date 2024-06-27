#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    LL a,b;
    cin>>a>>b;
    LL res=a*b;
    LL x=pow(res,(double)1.0/3.0);
    bool ok=false;
    for(LL i=max(1LL,x-10);i<=x+10;i++)
    {
        if(i*i*i==res && a%i==0 && b%i==0)
            ok=true;
    }
    if(ok)
        cout<<"Yes"<<'\n';
    else
        cout<<"No"<<'\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
