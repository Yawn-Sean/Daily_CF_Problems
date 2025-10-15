#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10,INF = 0x3f3f3f3f3f3f3f3f;

int a[N],st[N];

void solve()
{
    int n;cin >> n;
    int num = 0,num0 = 0,mi = INF,mii = -1,i0 = -1;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]<0)
        {
            num++;
            if(abs(a[i])<mi)mi = abs(a[i]),mii = i;
        }
    }
    vector<int> zero;
    for(int i = 1;i<=n;i++)
    {
        if(a[i]==0)zero.push_back(i),st[i] = 1;
    }
    int nn = zero.size();
    if(nn!=0&&mii!=-1&&num&1)zero.push_back(mii),nn++;
    for(int i = 0;i<nn;i++)
    {
        if(i+1>nn-1)break;
        cout << 1 << ' ' << zero[i] << ' ' << zero[i+1] << endl;
    }
    if(nn==n)return;
    int deli = 0;
    if(nn!=0)
    {
        deli = zero.back();
    }
    else
    {
        if(num&1)deli = mii;
    }
    st[deli] = 1;
    if(deli!=0)cout << 2 << ' ' << deli << endl;
    vector<int> ans;
    for(int i = 1;i<=n;i++)
    {
        if(!st[i])ans.push_back(i);
    }
    nn = ans.size();
    for(int i = 0;i<nn;i++)
    {
        if(i+1>nn-1)break;
        cout << 1 << ' ' << ans[i] << ' ' << ans[i+1] << endl;
    }
}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
