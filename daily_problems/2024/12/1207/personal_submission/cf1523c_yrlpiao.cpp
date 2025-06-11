#include <iostream>
#include <vector>
using namespace std;

void output(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (i) cout << ".";
        cout << a[i];
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) a.push_back(x);
        else {
            while (a.back() + 1 != x) a.pop_back();
            a.back() += 1;
        }
        output(a);
    }
    return 0;
}
