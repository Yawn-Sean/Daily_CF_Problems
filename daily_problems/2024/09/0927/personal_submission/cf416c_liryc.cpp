// https://codeforces.com/contest/416/submission/283123710
// 2024/9/27 Y1 1600 rbt
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int ca[1001], pa[1001], ra[1001];

int main() {
    int n; cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        cin >> ca[i] >> pa[i];
        pq.emplace(pa[i] << 10 | i);
    }
    int k; cin >> k;
    set<int> rt;
    for (int i = 0; i < k; ++i) {
        cin >> ra[i];
        rt.emplace(ra[i] << 10 | i);
    }
    int money = 0;
    vector<int> ans;
    while (!pq.empty() && !rt.empty()) {
        int i = pq.top() & 1023; pq.pop();
        auto t = rt.lower_bound(ca[i] << 10);
        if (t != rt.end()) {
            int j = *t & 1023;
            rt.erase(t);
            money += pa[i];
            ans.push_back(i << 10 | j);
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << " " << money << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it)
        cout << (*it >> 10) + 1 << " " << (*it & 1023) + 1 << endl;
    
    return 0;
}