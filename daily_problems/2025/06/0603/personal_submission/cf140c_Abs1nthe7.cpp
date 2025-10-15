#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    map<int, int> freq;
    for (int x : a) freq[x]++;
    
    priority_queue<pair<int, int>> pq;
    for (auto &[num, cnt] : freq) 
    {
        pq.push({cnt, num});
    }
    
    vector<tuple<int, int, int>> t;
    int ans = 0;
    
    while (pq.size() >= 3) 
    {
        // 取出频率最高的三种不同数字
        auto [cnt1, num1] = pq.top(); pq.pop();
        auto [cnt2, num2] = pq.top(); pq.pop();
        auto [cnt3, num3] = pq.top(); pq.pop();
        
        // 记录这三个数字（排序）
        vector<int> temp = {num1, num2, num3};
        sort(temp.begin(), temp.end(),greater<int>());
        t.push_back({temp[0], temp[1], temp[2]});
        ans++;
        
        // 如果还有剩余，重新加入队列
        if (--cnt1 > 0) pq.push({cnt1, num1});
        if (--cnt2 > 0) pq.push({cnt2, num2});
        if (--cnt3 > 0) pq.push({cnt3, num3});
    }
    
    cout << ans << endl;
    for (auto &[x, y, z] : t) {
        cout << x << ' ' << y << ' ' << z << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) sol();
    return 0;
}
