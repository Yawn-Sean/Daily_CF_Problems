#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        ++mp[a[i]];
    }

    /*
        第一个数组取出x 第二个数组取出y 能够得到的(x,y)对数max
        == 两个数组不同元素数量的乘积max
        只出现1次的数字
        出现多次的数字(>=2) 出现在两个数组中可以与数组的任意一个数字成对
    */
    vector<int> order(2 * n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return ((mp[a[i]] < mp[a[j]]) ? true : (mp[a[i]] == mp[a[j]]) && a[i] < a[j]);
    });

    set<int> st1, st2;
    vector<int> ans(2 * n, 1);
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2) {
            ans[order[i]] = 2;
            st2.insert(a[order[i]]);
        } else {
            st1.insert(a[order[i]]);
        }
    }

    cout << st1.size() * st2.size() << '\n';
    for (auto&x: ans) {
        cout << x << ' ';
    }


    return 0;
}
