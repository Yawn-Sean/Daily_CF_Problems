#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{

    // 找规律
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int oddmove = 0, evenmove = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            oddmove += x;
            evenmove += x;
        }
        else
        {
            if ((oddmove & 1)==0)
            {
                oddmove++;
            }
            else
            {
                oddmove--;
            }
            if ((evenmove & 1) == 1)
            {
                evenmove++;
            }
            else
            {
                evenmove--;
            }
        }

     oddmove=(oddmove+n)%n;
     evenmove=(evenmove+n)%n;
      
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i += 2)
    {
    	ans[(i+oddmove)%n]=a[i];
    }
    for (int i = 1; i < n; i += 2)
    {
    	ans[(i+evenmove)%n]=a[i];
    }
    for (auto x : ans)
    {
        cout << x << " ";
    };
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
