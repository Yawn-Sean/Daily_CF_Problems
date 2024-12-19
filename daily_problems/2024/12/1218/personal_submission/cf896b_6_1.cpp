#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    int n,m,c;cin >> n >> m >> c;

    vector<int> v(n+2,0);
    int l = 0,r = n+1;
    v[l] = 0,v[r] = c+1;    
    while(m--)
    {
        int now;cin >> now;
        if(now<=(c+1)/2)
        {
            if(now<v[l])
            {
                auto it = upper_bound(v.begin()+1,v.begin()+l+1,now);
                *it = now;
                cout << (it-v.begin()) << endl;
            }
            else v[++l] = now,cout << l<<endl;
        }
        else
        {
            if(now>v[r])
            {
                auto it = lower_bound(v.begin()+r,v.end(),now)-1;
                *it = now;
                cout << (it-v.begin()) << endl;
            }
            else v[--r] = now,cout << r<<endl;
        }
        // cout << l << ' ' << r << endl;
        // for(int i = 1;i<=n;i++)cout << v[i] << ' ' ;
        // cout << endl;
        if(r-l==1)
        {
            break;
        }
    }
    return;



}

signed main()
{
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
}
