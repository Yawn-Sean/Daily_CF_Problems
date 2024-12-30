#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
void solve()
{
    int n,c,d;
    cin>>n>>c>>d;
    vector<PII> p1;
    vector<PII> p2;

    for(int i=1;i<=n;i++)
    {
        int b,p;
        int w1,v1,w2,v2;
        char ch;
        cin>>b>>p>>ch;
        if(ch=='C')
        {
            w1 = b;
            v1 = p;
            p1.push_back({v1,w1});
        }
        else
        {
            w2 = b;
            v2 = p;
            p2.push_back({v2,w2});
        }
    }
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    vector<int> max1(n+10);
    vector<int> max2(n+10);
    if(p1.size())
        max1[0] = p1[0].second;
    if(p2.size())
        max2[0] = p2[0].second;
    for(int i = 1;i<p1.size();i++) max1[i] = max(max1[i-1],p1[i].second);
    for(int i = 1;i<p2.size();i++) max2[i] = max(max2[i-1],p2[i].second);
    int s1 = 0;
    int s2 = 0;
    for(int i=p1.size()-1;i>=0;i--)
    {
        if(p1[i].first<=c)
        {
            int sy = c - p1[i].first;
            PII qq = {sy,1e5+10};
            int it = lower_bound(p1.begin(),p1.begin()+i+1,qq) - p1.begin();
            it--;
            if(it==i) it--;
            if(it>=0)
            {
                s1 = max(p1[i].second+max1[it],s1);
            }
            
        }
    }
    for(int i=p2.size()-1;i>=0;i--)
    {
        if(p2[i].first<=d)
        {
            int sy = d - p2[i].first;
            PII qq = {sy,1e5+10};
            int it = lower_bound(p2.begin(),p2.begin()+i+1,qq) - p2.begin();
            it--;
            if(it==i) it--;
            if(it>=0)
            {
                s2 = max(p2[i].second+max2[it],s2);
            }
        }
    }
    int s3 = 0;
    int t1 = 0;
    int t2 = 0;
    for(int i=0;i<p1.size();i++)
    {
        if(p1[i].first<=c)
        {
            t1 = max(t1,p1[i].second);
        }
    }
    s3+=t1;
    for(int i=0;i<p2.size();i++)
    {
        if(p2[i].first<=d)
        {
            t2 = max(t2,p2[i].second);
        }
    }
    s3+=t2;
    if(t1&&t2)
        cout<<max({s1,s2,s3})<<endl;
    else cout<<max(s1,s2)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
