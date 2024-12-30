#include<bits/stdc++.h>
#include<iostream>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

signed main()
{

    int n, m;
    cin >> n;
    cin>>m;
    int res = 0;

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= m; j ++)
            if ((i * i + j * j) % m == 0)
                res += 1ll * ((n + m - i) / m) * ((n + m - j) / m);
    
    cout << res << endl;
    
}
