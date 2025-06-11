#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;

    int n = 1e6;
    vector<long long> h(n);
    for(int i=1; i<n; i++) h[i] = (long long) i * i * i;

    long long l = 8, r = 1e18;
    while(l < r) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for(int i=2; i<n; i++) sum += mid / h[i];
        if(sum >= x) r = mid;
        else l = mid + 1;
    }

    long long sum = 0;
    for(int i=2; i<n; i++) sum += l / h[i];
    if(sum == x) cout << l << endl;
    else cout << -1 << endl;
}
