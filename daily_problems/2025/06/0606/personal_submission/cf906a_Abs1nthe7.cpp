#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//我们只需要找到query.size==1的时候，后面的全是ans++
void sol()
{
    int n;cin>>n;
    set<char>query;
    for(char i='a';i<='z';++i)query.insert(i);
    int ans=0;
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        char op;
        cin>>op;
        if(op=='!')
        {
            string s;
            cin>>s;
            if(ok)ans++;
            else
            {
                set<char>now;
                for(char c:s)
                {
                    if(query.count(c))
                    {
                        now.insert(c);
                    }
                }
                query=now;
            }
        }
        else if(op=='?')
        {
            char c;
            cin>>c;
            if(ok)
            {
                if(query.size()==1&&!query.count(c))ans++;
            }
            else
            {
                if(query.size()!=1)query.erase(c);
            }
        }
        else
        {
            string s;cin>>s;
            if(!ok)
            {
                for(char c:s)
                {
                    query.erase(c);
                }
            }
        }
        if(query.size()==1)ok=true;
    }
    cout<<ans<<endl;
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
