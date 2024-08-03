#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

double cnt[N];
int n;
double s;

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        cnt[a] ++, cnt[b] ++;
    }
    double m = 0;
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 1) m ++;
    }
    cout << fixed << s / m * 2.0 << endl;
    return 0;
}
