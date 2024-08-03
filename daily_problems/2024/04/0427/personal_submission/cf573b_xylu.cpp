#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    h[0] = 1, h[n-1] = 1;
    for (int i = 1; i < n; i++) h[i] = min(h[i], h[i-1] + 1);
    for (int i = n-2; i >= 0; i--) h[i] = min(h[i], h[i+1] + 1);
    cout << *max_element(h.begin(), h.end()) << endl;

    return 0;
}
