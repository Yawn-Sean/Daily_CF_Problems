#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//感觉是道模拟
//1.考虑如何读入
//2.如何递归实现
vector<vector<string>>ans;
int pos=0;
void digui(vector<string>&tmp,int depth)
{
    if(depth>ans.size())
    {
        ans.resize(depth);
    }
    string now=tmp[pos++];
    ans[depth-1].emplace_back(now);

    int son=stoi(tmp[pos++]);
    for(int i=0;i<son;++i)
    {
        digui(tmp,depth+1);
    }
}
void sol()
{
    string s;
    getline(cin,s);
    vector<string>tmp;
    string t;
    stringstream ss(s);
    while(getline(ss,t,','))
    {
        tmp.push_back(t);
    }
    while(pos<tmp.size())
    {
        digui(tmp,1);
    }
    cout<<ans.size()<<endl;

    for(const auto &level:ans)
    {
      for(const auto &t:level)
      {
        cout<<t<<' ';
      }
      cout<<endl;
    }  
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
