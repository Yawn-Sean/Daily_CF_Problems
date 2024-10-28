#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y; scanf("%d%d", &x, &y);
    vector<int> vec = {y, y, y};
    int ans = 0;
    while (vec[0] < x) {
        vec[0] = vec[1] + vec[2] - 1;
        sort(vec.begin(), vec.end());
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
