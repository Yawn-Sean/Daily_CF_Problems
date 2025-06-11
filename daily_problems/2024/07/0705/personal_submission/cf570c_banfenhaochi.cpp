#include <bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
int a[N];

void solve()
{
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='.')
        {
            int j=i;
            int cnt=0;
            while(j<s.size() && s[j]=='.')
                ++cnt,++j;

            i=j;
            ans+=cnt-1;
        }
    }

    while(m--)
    {
        int pos;
        char ch;
        cin>>pos>>ch;
        --pos;
        if((ch==s[pos]) || (isalpha(ch) && isalpha(s[pos])) )
        {
            cout<<ans<<endl;
            continue;
        }
        if(ch=='.')
        {
            s[pos]=ch;
            if(pos>0 && s[pos-1]=='.')
                ++ans;
            if(pos<s.size()-1 && s[pos+1]=='.')
                ++ans;
        }
        else
        {
            if(s[pos]=='.')
            {
                s[pos]=ch;
                if(pos==0 && s[pos+1]=='.')
                    --ans;
                else if(pos==s.size()-1 && s[pos-1]=='.')
                    --ans;
                else
                {
                    if(s[pos-1]=='.')
                        --ans;
                    if(s[pos+1]=='.')
                        --ans;
                }
            }
        }

        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    solve();

    return 0;
}
