#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 3e5 + 10,M = 2 * N,mod = 1e9 + 7;
int T,n,m;

void solve()
{
   string x;
    cin >> x;
    int n = x.size();
    int totans = 0;
    bool flag = true;
    for(int j = 0;j < 10;j++){
        string save = x;
        for(int i = 0;i < n;i++){
            if(x[i] == 'X'){
                x[i] = j + '0';
                flag = false;
            }
        }
        if((n == 1 && !(x[0] == '0' || x[0] == '_')) || (n > 1 && x[0] == '0'))
        {
            x = save;
            if(flag)
            {
                break;
            }
            else continue;
        }
        else if(n == 1)
        {
            totans++;
            x = save;
            if(flag)
            {
                break;
            }
            else continue;
        }
        string tmp = x.substr(n - 2, 2);
        int ans = 0;
        if(tmp == "00" || tmp == "25" || tmp == "50" || tmp == "75" || tmp == "0_" || tmp == "2_" || tmp == "5_" || tmp == "7_")
        {
            if(n == 2 && (tmp == "00" || tmp == "0_")) ans = 0;
            else ans = 1;
        }
        else if(tmp == "_0" || tmp == "_5")
        {
            if(n == 2 && tmp == "_0") ans = 1;
            else ans = 2;
        }
        else if(tmp == "__")
        {
            if(n > 2) ans = 4;
            else ans = 3;
        }
        if(!ans)
        {
            x = save;
            if(flag)
            {
                break;
            }
            else
            continue;
        }
        if(x[0] >= '0' && x[0] <= '9'){
            for(int i = 1; i < n - 2; i++)
            {
                if(x[i] == '_')
                {
                    ans *= 10;
                }
            }
        }
        else if(x[0] == '_')
        {
            if(n > 2) ans *= 9;
            for(int i = 1; i < n - 2; i++)
            {
                if(x[i] == '_')
                {
                    ans *= 10;
                }
            }
        }
        totans += ans;
        x = save;
        if(flag)
        {
            break;
        }
    }
    cout << totans << endl;
}

signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--)
    {
        solve();
    }
}
