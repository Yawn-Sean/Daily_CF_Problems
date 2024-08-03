#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> nums[200010];
long long ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i].first);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i].second);
    sort(nums + 1, nums + n + 1);
    priority_queue<pair<int, int>> pq;
    int now = 0, i = 1;
    while (true)
    {
        if (pq.empty())
        {
            if (i > n)
                break;
            now = nums[i].first;
        }
        else
        {
            now++;
        }
        while (i <= n && nums[i].first <= now)
            pq.push(pair<int, int>(nums[i].second, nums[i].first)), i++;
        pair<int, int> p = pq.top();
        pq.pop();
        ans += 1LL * p.first * (now - p.second); // nums[i].first 要变到 now 的花费
    }
    printf("%lld\n", ans);
    return 0;
}
