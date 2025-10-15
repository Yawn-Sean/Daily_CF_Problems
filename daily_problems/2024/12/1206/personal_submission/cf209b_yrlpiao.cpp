#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a[3]; cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << (a[1] - a[0] & 1 ? a[2] : a[1]);
    return 0;
}
