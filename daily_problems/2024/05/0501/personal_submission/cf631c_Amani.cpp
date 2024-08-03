#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXL = 200005;
int a[MAXL], b[MAXL];
pair<int, int> a_n[MAXL];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    int top = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        while (top && y >= a_n[top - 1].second) {
            top--;
        }
        a_n[top].first = x;
        a_n[top].second = y;
        top++;
    }
    sort(b + 1, b + a_n[0].second + 1);
    int l = 1, r = a_n[0].second;
    for (int i = 0; i < top - 1; i++) {
        int j = a_n[i].second;
        if (a_n[i].first == 1) {
            while (j >= a_n[i + 1].second + 1) {
                a[j] = b[r--];
                j--;
            }
        } else {
            while (j >= a_n[i + 1].second + 1) {
                a[j] = b[l++];
                j--;
            }
        }
    }
    int j = a_n[top - 1].second;
    if (a_n[top - 1].first == 1) {
        while (j >= 1) {
            a[j] = b[r--];
            j--;
        }
    } else {
        while (j >= 1) {
            a[j] = b[l++];
            j--;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    return 0;
}