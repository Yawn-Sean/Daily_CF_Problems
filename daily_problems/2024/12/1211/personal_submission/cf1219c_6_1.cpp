#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void add(string &s)
{
    int n = s.size();
    for(int i = n-1;i>=0;i--)
    {

        if(s[i]=='9')
        {
            s[i] = '0';
            if(i==0)s = '1'+s;;
        }
        else {s[i]++;break;}
    }
}

void output(string &s,int times)
{
    while(times--)cout << s;
    cout << endl;
}

void solve()
{
    int l;cin >> l;
    string s;cin >> s;
    int n = s.size();
    if(n%l!=0)
    {
        int c = n/l+1;
        for(int i = 1;i<=c;i++)
        {
            cout << 1;
            for(int j = 1;j<=l-1;j++)cout << 0;
        }
        return ;
    }
    if(n==l)
    {
        add(s);
        int nn = s.size();
        if(nn!=n)
        {
            n=nn;
            int c = n/l+1;
            if(n==1)c--;
            for(int i = 1;i<=c;i++)
            {
                cout << 1;
                for(int j = 1;j<=l-1;j++)cout << 0;
            }
            return;
        }
        output(s,1);
        return;
    }
    string first;
    first =  s.substr(0,l);
    for(int i = 0;i<=s.size()-1;)
    {
        string temp = s.substr(i,l);
        if(temp>first)
        {
            add(first);
            output(first,n/l);
            return;
        }
        if(temp<first)
        {
            output(first,n/l);
            return;
        }
        i=i+l;
    }
    int fn = first.size();
    add(first);
    int now = first.size();
    if(fn!=now)
    {
        add(s);
        if(l==1)
        {
            for(int i = 0;i<s.size();i++)cout << 1;
            cout << endl;
            return;
        }
        else
        {
            int c = s.size()/l+1;
            for(int i = 1;i<=c;i++)
            {
                cout << 1;
                for(int j = 1;j<=l-1;j++)cout << 0;
            }
            return;
        }
    }
    output(first,n/l);
    return;
}

signed main()
{
    IOS
    int tt = 1;

    while(tt--)
    {
        solve();
    }
    return 0;
}
