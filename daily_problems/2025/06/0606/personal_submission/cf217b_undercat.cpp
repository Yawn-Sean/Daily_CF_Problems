#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,r;cin>>n>>r;
    string res="";
    int cnt=n+1;
    for(int i=1;i<=r;i++)for(int j=0;j<2;j++){
        int a=i,b=r;
        if(j)a=r,b=i;
        string temp="";
        int flag=0,len=0;
        while(a>0&&b>0){
            if(a<b)len+=b/a,b%=a;
            else len+=a/b,a%=b;
            // cout<<a<<' '<<b<<' '<<len<<'\n';
            if(len>n)flag=1;
            if(flag)break;
        }
        if(flag)continue;
        auto [mi,mx]=minmax({a,b});
        if(mi!=0||mx!=1)continue;
        if(len!=n)continue;
        a=i,b=r;
        if(j)a=r,b=i;
        while(a>1||b>1){
            if(a<b)temp.push_back('B'),b-=a;
            else temp.push_back('T'),a-=b;
        }
        reverse(temp.begin(),temp.end());
        temp="T"+temp;
        int sum=0;
        for(int j=1;j<temp.size();j++){
            sum+=temp[j]==temp[j-1];
        }
        if(sum<cnt)res=temp,cnt=sum;
    }
    if(res.size()==0)cout<<"IMPOSSIBLE";
    else cout<<cnt<<'\n'<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}