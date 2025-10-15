#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//离散化不对,实质是结合两个数组，让他们错开
//1 2 1 1
//1 1 2 1

//1 2 2 1
//2 1 1 1 --如果一个最多的数<=n/2的话一定能错开cnt=n
//不然的话cnt=(n-_max)*2
void sol()
{
   int n,m;cin>>n>>m;
   vector<int>a(n),mp(m+1);   
   for(auto &x:a)cin>>x,mp[x]++;
   int _max=*max_element(mp.begin(),mp.end());
   cout<<min(n,2*n-2*_max)<<endl;
   sort(a.begin(),a.end());
   for(int i=0;i<n;++i)
   {
    cout<<a[i]<<' '<<a[(i+_max)%n]<<endl;
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
