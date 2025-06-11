#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    思想：控制坦克的移动
    策略：如果坦克在奇数位置那被第一次炸后一定会移动到偶数位置，但是原本在偶数位置的坦克没被炸过
    然后炸一次偶数位置那么从奇数位置移动到偶数位置的坦克会被炸毁，原本在偶数位置的坦克会移动到奇数位置
    再炸一次奇数位置那么坦克就都会被炸毁。
    次数:
    先炸一次偶数位置的坦克：n/2
    再一次奇数一次偶数：n
    所以说n+n/2
    补充：
    必须先炸偶数位置，如果先炸奇数位置
    如果n为偶数就不影响
    如果n为奇数：
    先炸一次奇数 n/2+1
    再一次奇数一次偶数：n
    就是n+n/2+1
    会多出来1
*/
void solve()
{
    int n = 0, m = 0;
    string s;
    cin >> n;
    int ans = 0;
    cout << (n + n / 2) << endl;
    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
