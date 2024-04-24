#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    vector<pair<int, int>> hs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
        hs[i].first = count(strs[i].begin(), strs[i].end(), 'h');
        hs[i].second = count(strs[i].begin(), strs[i].end(), 's');
    }
    vector<int> idx(n);
    // 0 - n - 1 的list idx
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j)
         { return 1LL * hs[i].first * hs[j].second < 1LL * hs[j].first * hs[i].second; });
    long long cnt_s = 0, ans = 0;
    for (int i : idx)
    {
        for (char c : strs[i])
        {
            if (c == 's')
                cnt_s++;
            else
                ans += cnt_s;
        }
    }
    cout << ans << endl;
    return 0;
}
