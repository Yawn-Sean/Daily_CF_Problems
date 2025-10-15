#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>


using namespace std;

#define ll long long

typedef array<int, 3> node;

const int N = 5e3 + 10;

int n, m;
double x;
int a[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> x;
    }

    int mx = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] >= a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }
    
    cout << n - mx << "\n";

    return 0;
}
