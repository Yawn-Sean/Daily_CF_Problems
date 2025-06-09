#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int check(int x,int len)
{
    int res=0;
    for(int i=1;i<=len;++i,x/=7)
    {
        int tmp=1<<(x%7);
        if(res&tmp)return 0b1111111;
        res|=tmp;
    }
    return res;
}
void sol()
{
    int n,m;cin>>n>>m;
    int ln=1,lm=1;
    for(int i=7;i<n;i*=7)
    {
        ln++;
    }
    for(int i=7;i<m;i*=7)
    {
        lm++;
    }
    int ans=0;
    if(ln+lm>7)
    {
        cout<<0<<endl;
        return;
    }
    else
    {
      for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            if((check(i,ln)&check(j,lm))==0)ans++;
        }
    }
    cout<<ans<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}
