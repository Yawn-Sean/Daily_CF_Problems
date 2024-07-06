/**
 * @file cf570c_liryc.cpp
 * @author your name (you@domain.com)
 * @brief 570C 1600
 * @version 0.1
 * @date 2024-07-05
 * @copyright Copyright (c) 2024
 * map manipulations
 * attention: no need segment tree
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, int> a; // 保存格式：<ind, count> 例如 a[5]=3，表示从下标5开始有连续3个.，也就是[5,6,7]
int ans = 0;

/**
 * @brief 执行一次查询
 * 
 * @param i 修改的位置下标，已修正成0-indexed
 * @param p 修改为'.'则为true，否则false
 */
void solve(int i, bool p) {
    // cout << "solve: i=" << i << " p=" << p << endl;
    if (p) {
        // # insert

        // (1) 如果i位置上已经是'.'了，无需新增
        auto it = a.upper_bound(i); // 查找i位置或其左边的第一个区间
        if (it == a.begin()) it = a.end();
        else /*if (it != a.end())*/ --it;
        if (it != a.end() && it->first + it->second > i)
            return;

        // (2) 否则更新(i, 1)，注意同时要merge左右的区间
        int j = i, c = 1;
        if (it != a.end() && it->first + it->second == i) {
            ans -= it->second - 1;
            j = it->first;
            c = it->second + 1;
            a.erase(it);
        }
        it = a.find(j + c); // 查找i+1位置为起点的区间
        if (it != a.end()) {
            ans -= it->second - 1;
            c += it->second;
            a.erase(it);
        }
        // 新增合并后的区间
        a[j] = c;
        ans += c - 1;
    } else {
        // # delete

        // (1) 如果当前位置本来就不是'.'，无需删除
        auto it = a.upper_bound(i); // 查找i位置或其左边的第一个区间
        if (it == a.begin()) it = a.end();
        else //if (it != a.end()) 
            --it;
        if (it == a.end() || it->first + it->second <= i)
            return;

        // (2) 否则，将i位置上的'.'删除，删除后如果有左右两个剩余区间，要新增回去
        // cout << "solve: delete(2)" << endl;
        int j = it->first, c = it->second;
        ans -= c - 1;
        a.erase(it);
        if (j < i) {
            a[j] = i - j;
            ans += i - j - 1;
        }
        if (j + c > i + 1) {
            a[i + 1] = j + c - i - 1;
            ans += j + c - i - 2;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    int c = 0;
    cin >> s;
    for (int i = 0; i <= s.size(); ++i) {
        if (i < s.size() && s[i] == '.')
            ++c;
        else {
            if (c > 0) {
                a[i - c] = c;
                ans += c - 1;
                c = 0;
            }
        }
    }
    while (m--) {
        cin >> c >> s;
        solve(c - 1, s[0] == '.');
        // for (auto it = a.begin(); it != a.end(); ++it)
            // cout << it->first << " " << it->second << endl;
        cout << ans << endl;
    }
    return 0;
}