#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
//#define endl "\n" //交互题记得用endl
//每次查询半边,然后按顺序查询[2-n-1],这样就是n/2次，对于n为奇数的，直接多求一个最后的数，然后正常query就行
// 5 2 3 1 4 6
// 1.query(1,3)-2 3 5
// 2.query(2,5)-2 3 1 4
// 3.query(3,4)-3 1 
//每一次从l,r中找没有的就行
set<int>query(int l,int r)
{
    cout<<"Q "<<l<<' '<<r<<endl;
    set<int>st;
    for(int i=l;i<=r;++i)
    {
       int x;cin>>x;
       st.insert(x);
    }
    return st;
}
void sol()
{
    int n;cin>>n;
    int orn=n;
    vector<int>ans(n+1);
    set<int>tmp;
    for(int i=1;i<=n;++i)tmp.insert(i);
    if(n&1)
    {
        set<int>c=query(n,n);
        n--;
        ans[n+1]=*c.begin();
        tmp.erase(ans[n+1]);
    }
    if(n==1)
    {
        cout<<"A "<<1<<endl;
    }
    if(n>1)
    {
        auto left=query(1,n/2);
        set<int> right;
        for(auto &c:tmp)
        {
            if(left.find(c)==left.end())
            {
                right.insert(c);
            }
        }
        for(int i=2;i<=n/2;++i)
        {
            auto now=query(i,n-i+1);
            for(auto &c:left)
            {
                if(now.find(c)==now.end())
                {
                    left.erase(c);
                    ans[i-1]=c;
                    break;
                }
            }
            for(auto &c:right)
            {
                if(now.find(c)==now.end())
                {
                    right.erase(c);
                    ans[n-i+2]=c;
                    break;
                }
            }
        }
        ans[n/2]=*left.begin();
        ans[n/2+1]=*right.begin();
    }
    cout<<"A ";
    for(int i=1;i<=orn;++i)
    {
        cout<<ans[i]<<" \n"[i==orn];
    }
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
