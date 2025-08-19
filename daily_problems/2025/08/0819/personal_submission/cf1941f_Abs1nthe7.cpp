#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//换个思维的二分
//我们如果正常去二分操作的话，时间复杂度肯定不允许，那回来看题目
//我们可以一开始先找到最大的间隔，如果这个间隙数量大于1的话，那就可以直接输出这个间隙
//不然的话，我们考虑进行这里的分割，我们可以二分找到离当前位置中心最近的的
//先选取一个元素，再二分找第二个元素，然后取最优的分割方式
void sol()
{
    int n,m,k;cin>>n>>m>>k;
    vector<i64>a(n),d(m),f(k);
    for(auto &c:a)cin>>c;
    for(auto &c:d)cin>>c;
    for(auto &c:f)cin>>c;

    sort(f.begin(),f.end());
    i64 _max_gap=0,cnt=0;
    for(int i=1;i<n;++i)
    {
        if(a[i]-a[i-1]>_max_gap)
        {
            _max_gap=a[i]-a[i-1];
            cnt=1;
        }
        else if(a[i]-a[i-1]==_max_gap)
        {
            cnt++;
        }
    }
    if(cnt>1)
    {
        cout<<_max_gap<<endl;
        return;
    }
    else
    {
        i64 second_gap=0;
        for(int i=1;i<n;++i)
        {
            if(a[i]-a[i-1]<_max_gap)
            {
                second_gap=max(second_gap,a[i]-a[i-1]);
            }
        }

        for(int i=1;i<n;++i)
        {
            if(a[i]-a[i-1]==_max_gap)
            {
                i64 tmp=a[i-1]+(a[i]-a[i-1])/2;
                i64 ans=_max_gap;
                for(auto &c:d)
                {
                   int res=tmp-c;
                   int p=lower_bound(f.begin(),f.end(),res)-f.begin();
                   for(int j=p-1;j<=p+1;++j)
                   {
                    if(j>=0&&j<k&&f[j]+c>=a[i-1]&&f[j]+c<=a[i])
                    {
                        ans=min(ans,max((f[j]+c-a[i-1]),(a[i]-f[j]-c)));
                    }
                   }
                }
                ans=max(ans,second_gap);
                cout<<ans<<endl;
                return;
            }
        }
    }
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
