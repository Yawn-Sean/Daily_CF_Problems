#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

double calculate_value(int a, int b) {
    double area = (double)(a * b);
    double perimeter = 2 * (a + b);
    return (perimeter * perimeter) / area;
}

void solve() {
    int n;
    cin >> n;
    
    map<int, int> mp;  // 用 map 统计棍子长度的出现次数
    
    // 统计每个长度的棍子数量
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    bool found = false;
    vector<int> candidates;
    
    // 首先查找能组成正方形的棍子（即数量大于等于4的）
    for (auto &[k, v] : mp) {
        if (v >= 4) {
            cout << k << " " << k << " " << k << " " << k << "\n";
            found = true;
            break;  // 找到正方形，直接跳出
        }
        if (v >= 2) {
            candidates.push_back(k);  // 记录数量大于等于2的长度
        }
    }
    
    if (!found) {
        // 没找到正方形，排序候选棍子并计算最优矩形
        sort(candidates.begin(), candidates.end());
        
        double min_value = numeric_limits<double>::infinity();
        int best_a = 0, best_b = 0;
        
        for (int i = 1; i < candidates.size(); i++) {
            int a = candidates[i], b = candidates[i - 1];
            double value = calculate_value(a, b);
            if (value < min_value) {
                min_value = value;
                best_a = a;
                best_b = b;
            }
        }
        
        // 输出最优矩形
        cout << best_a << " " << best_a << " " << best_b << " " << best_b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
