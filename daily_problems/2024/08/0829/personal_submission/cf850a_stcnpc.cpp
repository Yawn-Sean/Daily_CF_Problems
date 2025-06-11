// https://codeforces.com/problemset/problem/850/A
#include <bits/stdc++.h>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 计算点积
double dot_product(const vector<int>& u, const vector<int>& v) {
    double result = 0.0;
    for (int i = 0; i < 5; ++i)
        result += u[i] * v[i];
    return result;
}

// 计算向量的模长
double norm(const vector<int>& v) {
    double result = 0.0;
    for (int i = 0; i < 5; ++i)
        result += v[i] * v[i];
    return sqrt(result);
}

double calculate_angle(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    vector<int> ab(5), ac(5);
    for (int i = 0; i < 5; ++i) {
        ab[i] = b[i] - a[i];
        ac[i] = c[i] - a[i];
    }

    double dot = dot_product(ab, ac);
    double norm_ab = norm(ab);
    double norm_ac = norm(ac);

    double cos_theta = dot / (norm_ab * norm_ac);
    // 限制 cos_theta 的范围在 [-1, 1] 之间以防浮点误差
    cos_theta = min(1.0, max(-1.0, cos_theta));
    
    double theta = acos(cos_theta);
    return theta;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(5));
    vector<int> res;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> nums[i][j];
    
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            for (int k = j + 1; k < n; ++k) {
                if (k == i) continue;
                double angle = calculate_angle(nums[i], nums[j], nums[k]);
                if (angle * 180 / M_PI < 90) { // 角度小于 90 度
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) res.push_back(i + 1); // 保存的是从1开始的索引
    }
    
    cout << res.size() << endl;
    for (const auto& v : res) cout << v << endl;
}

int main() {
    solve();
    return 0;
}
