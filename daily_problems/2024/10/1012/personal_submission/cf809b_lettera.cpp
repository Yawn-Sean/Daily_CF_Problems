 #include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
int ask(int x, int y)
{
    cout <<1<<" "<< x << " " << y << endl;
    string s;
    cin >> s;
    return s[0] == 'T';
}
void solve()
{
    int n, k;
    cin >> n >> k;
    auto get = [&](int l, int r) {
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (ask(mid, mid + 1))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    };
    int ans1=get(1,n);
    int ans2=get(1,ans1-1);
    if(ans2==0||!ask(ans2,ans1))
    {
    	ans2=get(ans1+1,n);
    }
    cout<<2<<" "<<ans1<<" "<<ans2<<endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
   //cin >> t;
    while (t--)
    {
        solve();
    }
}
