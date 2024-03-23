#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(12);

    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    for (auto& xi : x) {
        cin >> xi;
    }
    
    auto calc = [&] (int xi, int x1, double y1) -> double {
        double dy = sqrt(4*r*r - (xi-x1)*(xi-x1));
        return y1 + dy;
    };
    
    vector<double> y(n);
    set<pair<int, double>> st;

    for (int i = 0; i < n; i++) {
        auto it1 = st.upper_bound({x[i] - 2 * r, 0});
        auto it2 = st.lower_bound({x[i] + 2 * r + 1, 0});
        double yi = r;
        while (it1 != it2) {
            auto [x1, y1] = *it1;
            yi = max(yi, calc(x[i], x1, y1));
            it1++;
        }
        y[i] = yi;
        st.emplace(x[i], y[i]);
    }

    for (auto& yi : y) {
        cout << yi << " ";
    }
    cout << "\n";
    
    return 0;
}

