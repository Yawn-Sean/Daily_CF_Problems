#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
using ll=long long;
int a[N];
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)cin>>a[i],ans=gcd(a[i],ans);
    if(ans>1)cout<<"YES"<<'\n'<<0<<'\n';
    else {
        ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]%2!=0&&a[i+1]%2!=0)ans++,i++;
            else if(a[i]%2!=0)ans+=2;
        }
        cout<<"YES"<<'\n'<<ans<<'\n';
    }
    return 0;
}
