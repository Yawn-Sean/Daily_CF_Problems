#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, int> cntMap;
    int f = 1;
    for (int i = 1; i <= k + 1; i++) {
        while (f-- > 0) {
            cout << endl;
        }
        cout << "? ";
        for (int j = 1; j <= k + 1; j++) {
            if (i != j) {
                cout << j << ' ';
            }
        }
        cout << endl;

        int x, y;
        cin >> x >> y;
        cntMap[y]++;
    }

    cout << "! " << cntMap.rbegin()->second << endl;
    return 0;
}