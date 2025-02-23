#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> vec;
    for (int i = 0; i < 3; i++) {
        long long x; scanf("%lld", &x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    if ((vec[0] + vec[1]) & 1) printf("%lld\n", vec[2]);
    else printf("%lld\n", vec[1]);
    return 0;
}
