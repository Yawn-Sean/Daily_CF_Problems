#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    string s;cin>>s;
    int n;cin>>n;
    vector<string>str(n);
    for(int i=0;i<n;++i)cin>>str[i];
    int length=0,st=0,tmp=0;
    for(int i=0;i<s.size();++i)//枚举右端点
    {
        for(auto x:str)
        {
            if(i+1>=x.size()&&s.substr(i+1-x.size(),x.size())==x)
            {
               tmp=max(tmp,i+1-(int)x.size()+1);//可行的左端点
            }
        }
        if(i-tmp+1>length)//现在的长度
        {
            length=i-tmp+1;
            st=tmp;
        }
    }
    cout<<length<<' '<<st<<endl;
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
