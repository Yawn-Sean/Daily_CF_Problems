#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
//非常简单的贪心
//不对。。,想简单了，对于前2n-1个东西，我们可以拿下n个，对于前n个东西，我们最多拿n/2+1，那就每次拿这n/2+1的最大就行，用pq
void sol()
{
    int n;cin>>n;
    vector<int>a(n+1);
    i64 ans=0,tot=0;
    for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n;++i)
    {
        int cur=(i-1)/2+1;//3-2.2-1
        if(cur>pq.size())
        {
            ans+=a[i];
            pq.push(a[i]);
        }
        else if(pq.top()<a[i])
        {
            ans-=pq.top();
            ans+=a[i];
            pq.pop();
            pq.push(a[i]);
        }
    }
    cout<<ans<<' '<<tot-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
