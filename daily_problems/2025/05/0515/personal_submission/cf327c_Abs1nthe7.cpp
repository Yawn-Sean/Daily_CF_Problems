#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod=1e9+7;
int qmi(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}
int inv(int x){return qmi(x,mod-2);}
void sol()
{
   string s;int k;
   cin>>s>>k;
   int n=s.size();
   int cnt=0;
   int cnt0=0,cnt5=0;
   vector<int>a;
   for(int i=0;i<s.size();++i)
   {
    if(s[i]=='0'||s[i]=='5')cnt++,a.push_back(i);
    if(s[i]=='0')cnt0++;
    if(s[i]=='5')cnt5++;
   }
   int ans=0;
   if(cnt==s.size())
   {
     cout<<qmi(2,cnt*k)-1;
     return;
   }
   //q-qmi(2,n);
   for(auto c:a)
   {
      ans+=qmi(2,c)*(qmi(qmi(2,n),k)-1)%mod*inv((qmi(2,n)-1)%mod);
      ans=ans%mod;
   }
   cout<<ans%mod<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}
