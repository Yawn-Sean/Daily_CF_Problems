#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<double> vec;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec.push_back(atan2(y, x));
    }
    sort(vec.begin(), vec.end());

    const double PI = acos(-1);
    double ans = vec[0] + 2 * PI - vec.back();
    for (int i = 1; i < vec.size(); i++) ans = max(ans, vec[i] - vec[i - 1]);
    printf("%.12f\n", (2 * PI - ans) / PI * 180);
    return 0;
}
