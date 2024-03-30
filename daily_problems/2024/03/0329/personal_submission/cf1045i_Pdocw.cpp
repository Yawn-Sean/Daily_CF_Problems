#include <bits/stdc++.h>
using namespace std;
// 回文串的对数
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    long long ans = 0;
    cin >> n;
    string s;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int len = s.length(), mask = 0;
        for (int j = 0; j < len; j++)
        {
            mask ^= (1 << (s[j] - 'a'));
        }
        ans += mp[mask]; // 本身就是回文串
        for (int j = 0; j < 26; j++)
        {
            ans += mp[mask ^ (1 << j)];
        }
        mp[mask]++;
    }
    cout << ans << endl;
    return 0;
}
