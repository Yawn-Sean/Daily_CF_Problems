#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//字符串匹配，很显然的kmp匹配，但是正常从前缀开始跑的话是n2，但是模式串越长，匹配的数量肯定越少，所以采用二分；
void sol()
{
    string s;getline(cin,s);
    string p;getline(cin,p);
    int res;cin>>res;
    int n=s.size(),m=p.size();
    int l=1,r=m;
    string g;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(mid>m)break;
        string tmp=p.substr(0,mid);
        int len=tmp.size();
        vector<int>nxt(len+1,0);
        int ans=0;
        for(int i=1,j=0;i<len;++i)
        {
            while(j&&tmp[i]!=tmp[j])j=nxt[j];
            if(tmp[i]==tmp[j])j++;
            nxt[i+1]=j;
        }
        //aba
        //nxt[2]=0,nxt[3]=1
        for(int i=0,j=0;i<n;++i)
        {
            while(j&&s[i]!=tmp[j])j=nxt[j];
            if(s[i]==tmp[j])j++;
            if(j==len)
            {
                ans++;
                j=nxt[j];
            }
        }
        //ababa
        if(ans>=res)
        {
            g=tmp;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if(!g.empty())
    {
        cout<<g<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
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
