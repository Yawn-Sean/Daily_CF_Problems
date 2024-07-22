#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
using ll=long long;
ll a[N],d[N],s[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)d[i]=a[i+1]-a[i];
    sort(d+1,d+n);
    d[0]=0;
    for(int i=1;i<=n-1;i++)s[i]=s[i-1]+d[i];
    int q;cin>>q;
    while(q--)
    {
        ll l,r;cin>>l>>r;
        ll ans=0,k=r-l+1;
        l=1,r=n-1;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(d[mid]>=k)r=mid;
            else l=mid+1;
        }
        if(d[r]>k)r--;
        ans=s[r]+(n-r)*k; 
        cout<<ans<<' '; 
    }
    return 0;
}
