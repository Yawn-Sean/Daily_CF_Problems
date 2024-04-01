#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    map<LL, int> cnt;
    for (LL v : nums)
    {
        cnt[v & -v]++;
    }
    // cnt 按 second 从 大到小 排序
    vector<pair<LL, int>> sorted_cnt(cnt.begin(), cnt.end());
    sort(sorted_cnt.begin(), sorted_cnt.end(), [](auto a, auto b)
         { return a.second > b.second; });
    LL msk = sorted_cnt.begin()->first;
    vector<LL> chosen;
    for (LL v : nums)
    {
        if ((v & -v) != msk)
        {
            chosen.push_back(v);
        }
    }

    cout << chosen.size() << endl;
    for (int i = 0; i < chosen.size(); ++i)
    {
        cout << chosen[i];
        if (i < chosen.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
