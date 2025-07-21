#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const i64 inf=1e18;
//每个东西最后被吃掉，肯定的它相邻的才能吃
//每一元素有可能是从一段区间和而来
//如果一段的元素大小都不相等，总是能合并，只需要找最大的往前后吃就行
//本题思路，对于一个数如果前后有比它大的，直接输出1
//不然的话，考虑前后找一个pos，使得这个数能左边或者右边被吃，不能就-1
void sol()
{
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=0;i<n;++i)cin>>a[i];

    vector<i64>prefix(n+1,0),suf(n+1,0);
    for(int i=0;i<n;++i)
    {
        prefix[i+1]=prefix[i]+a[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        suf[i]=suf[i+1]+a[i];
    }
    vector<int>lst(n+1,0),next(n+1,0);//左右边连续相同的长度
    lst[0]=1;
    for(int i=1;i<n;++i)
    {
        if(a[i]==a[i-1])
        {
            lst[i]=lst[i-1]+1;
        }
        else
        {
          lst[i]=1;
        }
    }
    next[n-1]=1;
    for(int i=n-2;i>=0;--i)
    {
        if(a[i]==a[i+1])
        {
          next[i]=next[i+1]+1;
        }
        else
        {
            next[i]=1;
        }
    }
    for(int i=0;i<n;++i)
    {
        i64 ans=inf;
        bool left=(i-1>=0&&a[i-1]>a[i]);
        bool right=(i+1<n&&a[i+1]>a[i]);
        if(left||right)
        {
            cout<<"1 ";
            continue;
        }
        if(i>0&&prefix[i]>a[i]&&lst[i-1]<i)
        {
            auto it=lower_bound(suf.begin(),suf.end(),suf[i]+a[i],greater<i64>());
            int pos=distance(suf.begin(),it);
            ans=min(ans,max((i64)lst[i-1]+1,(i64)i- pos+1));
        }
        if(i+1<n&&suf[i+1]>a[i]&&next[i+1]<n-i-1)
        {
            auto it=upper_bound(prefix.begin(),prefix.end(),prefix[i+1]+a[i]);//prefix[pos]-prefix[i+1]>a[i];
            int pos=distance(prefix.begin(),it);
            ans=min(ans,max((i64)next[i+1]+1,(i64)pos-i-1));
        }
        cout<<(ans==inf?-1:ans)<<' ';
    }
    cout<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)sol();
    return 0;
}
