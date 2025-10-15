#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//第一眼，需要数据结构
//第二眼，1000**3>=1e9,那就是1e5*1e3的时间复杂度，直接暴力就行
void sol()
{
    int n;cin>>n;
    vector<int>a(n);
    for(auto &c:a)cin>>c;
    int q;cin>>q;
    while(q--)
    {
       int op;cin>>op;
       int i;cin>>i;
       //cout<<op<<' '<<i<<endl;
       if(op==1)
       {
          int x;cin>>x;
          a[i-1]=x;
       }
       else
       {
           if(n>=2000)
           {
              if(i<=1000)
              {
                cout<<n<<endl;
              }
              else
              {
                cout<<1<<endl;
              }
           }
           else
           {
              bool ok=true;
              i--;
              for(int j=0;j<n;++j)
              {
                if(abs((i-j)*(i-j)*(i-j))>=a[j])
                {
                    cout<<j+1<<endl;
                    ok=false;
                    break;
                }
              }
              if(ok)
              {
                cout<<-1<<endl;
              }
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
    //cin>>_;
    while(_--)sol();
    return 0;
}
