#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0, cnt = 1;
    vector<int> diff;
    int last = 0;
    for (int i = 0, t, a, x, k; i < n; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &a, &x);
            sum += a * x;
            if (a == cnt) {
                last += x;
            } else {
                diff[a - 1] -= x;
            }
        } else if (t == 2) {
            scanf("%d", &k);
            diff.push_back(k - last);
            last = k;
            cnt += 1;
            sum += k;
        } else {
            cnt -= 1;
            sum -= last;
            last = last - diff.back();
            diff.pop_back();
        }
        printf("%.08f\n", 1.0 * sum / cnt);
    }
    return 0;
}

