#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int x, y;
    cin >> x >> y;
    array<int, 3>a;
    a[0] = a[1] = a[2] = y;
    //正推不知道变为哪个数使答案优
    //要逆推
    int cnt = 0;
    while (a[0] != x || a[1] != x || a[2] != x) {

        //max+mid>min --> min = max+mid-1
        int s = a[1] + a[2] - 1;
        if (s >= x) {
            a[0] = x;
        }
        else {
            a[0] = s;
        }
        cnt++;
        //cerr << a[0] << " " << a[1] << " " << a[2] << "\n";
        sort(a.begin(), a.end());
    }
    cout << cnt;
    return 0;
}
