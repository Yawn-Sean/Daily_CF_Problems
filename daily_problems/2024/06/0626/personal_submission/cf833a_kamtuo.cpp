#include <bits/stdc++.h>

using namespace std;

const int N = 1001000;

typedef long long LL;
int pre[N], psum;
bool st[N];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void cal() {
    for (int i = 2; i <= N - 1; i ++) {
        if (st[i] == false) pre[psum ++] = i;
        for (int j = 0; j < psum && pre[j] <= (N - 1) / i; j ++) {
            st[pre[j] * i] = true;
            if (i % pre[j] == 0) break;
        }
    }
}

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < N; i ++) pre[i] = i, psum ++;
    // for (int i = 0; i < psum; i ++) cout << pre[i] << endl;
    for (int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        bool ok = true;
        // cout << a << ' ' << b << endl;
        LL l = 1, r = psum - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (pre[mid] >= 1ll * a * b / pre[mid] / pre[mid]) r = mid;
            else l = mid + 1;
        }
        // cout << pre[r] << endl;
        if (pre[r] == 1ll * a * b / pre[r] / pre[r] && a % pre[r] == 0 && b % pre[r] == 0) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    return 0;
}
