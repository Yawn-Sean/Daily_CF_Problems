#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1001;
typedef long long LL;
LL C[N][N];
void init()
{
    for(int i = 0; i < N; i++)
    {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
    }
}

int main()
{
    init();
    string n; cin >> n;
    int k; cin >> k;
    if(k == 0)
    {
        cout << "1\n";
        return 0;
    }
    vector<int> f(1001);
    for(int i = 2; i <= 1000; i++)
    {
        int cnt = 0;
        for(int j = 15; j >= 0; j--)
            if(i >> j & 1) cnt++;
        f[i] = f[cnt] + 1;
    }
    LL ans = 0;
    for(int i = 1; i <= 1000; i++)
    {
        if(f[i] == k - 1)
        {
            int now = 0;
            for(int j = 0; j < n.size(); j++)
            {
                if(n[j] == '1')
                {
                    ans = (ans + C[n.size() - j - 1][i - now]) % mod;   //不选最高位，后面随便选的方案数
                    now++;      //选最高位
                }
                if(i == now)    //已经选完所有的1了，最后一个选法也是一种方案
                {
                    ans++;
                    break;
                }
            }
        }
    }

    if(k == 1) ans--;   //特判1，因为 1等于1，把1变成1的运算次数是0而不是1
    cout << ans;

}
