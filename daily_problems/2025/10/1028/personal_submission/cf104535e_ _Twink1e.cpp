#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    int k = n - 3;
    cout << -1 << " " << 2 << " ";
    cout << 0 << " " << 2 << " ";
    cout << 2 + k << " " << 1 << " ";
    cout << 3 + k << " " << 0 << " ";
    cout << 2 + k << " " << 0 << " ";
    cout << 0 << " " << 1 << endl;

    return 0;
}
