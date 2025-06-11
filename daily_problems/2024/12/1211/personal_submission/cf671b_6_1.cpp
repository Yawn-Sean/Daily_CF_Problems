#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 5e5+10;

int a[N],suf[N];

void solve()
{
    int n,k;cin >> n >> k;

    for(int i = 1;i<=n;i++)cin >> a[i];
    
    sort(a+1,a+1+n);

    for(int i = 1;i<=n;i++)suf[i] = suf[i-1]+a[i];

    int l = a[1],r = a[n];

    while(l<r)
    {
        int mid = l+r+1>>1;
        int it = lower_bound(a+1,a+1+n,mid)-a-1;
        if(it*mid-suf[it]<=k)l = mid;
        else r = mid-1;
    }
    int ll = l;
    l = a[1],r = a[n];
    while(l<r)
    {
        int mid = l+r>>1;
        int sum = 0;
        int it = upper_bound(a+1,a+1+n,mid)-a;//改成二分还慢了20ms，，
        if((suf[n]-suf[it-1])-mid*(n-it+1)<=k)r = mid;
        else l = mid+1;
    }
    int rr = r;
    int c = (suf[n]%n==0?0:1);
    cout << max(rr-ll,c) << endl;
}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
