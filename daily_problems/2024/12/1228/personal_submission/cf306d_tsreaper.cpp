#include <bits/stdc++.h>
#define MAXN 100
#define EPS (1e-3)
using namespace std;

int n;
double X[MAXN], Y[MAXN];
const double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double rnd(double x, double y) {
    return uniform_real_distribution<double>(x, y)(rng);
}

bool check() {
    vector<double> vec;
    for (int i = 0; i < n; i++) {
        double dx = X[(i + 1) % n] - X[i], dy = Y[(i + 1) % n] - Y[i];
        double len = sqrt(dx * dx + dy * dy);
        if (len < 1 + EPS || len > 1000 - EPS) return false;
        vec.push_back(len);
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++) if (vec[i] - vec[i - 1] < EPS) return false;
    return true;
}

vector<double> gen(int cnt) {
    while (true) {
        double sm = 0;
        vector<double> vec;
        for (int i = 1; i < cnt; i++) {
            double t = rnd(1, 10);
            vec.push_back(t);
            sm += t;
        }
        if (sm > cnt * 5) continue;
        vec.push_back(cnt * 5 - sm);
        return vec;
    }
}

int main() {
    scanf("%d", &n);
    if (n <= 4) { printf("No solution\n"); return 0; }
    while (true) {
        int cnt = (n - 1) / 2;
        vector<double> vec = gen(cnt);

        if (n & 1) {
            double delta = PI - (n - 2) * PI / n, theta = PI / 2 + delta / 2;
            X[0] = 0; Y[0] = 0;
            for (int i = 0; i < cnt; i++) {
                theta -= delta;
                X[i + 1] = X[i] + vec[i]; Y[i + 1] = Y[i] + vec[i] * tan(theta);
            }

            vec = gen(cnt);
            theta = PI / 2 + delta / 2;
            X[n] = 0; Y[n] = 0;
            for (int i = 0; i < cnt; i++) {
                theta -= delta;
                X[n - 1 - i] = X[n - i] + vec[i]; Y[n - 1 - i] = Y[n - i] - vec[i] * tan(theta);
            }
        } else {
            double delta = PI - (n - 2) * PI / n, theta = PI / 2;
            X[0] = 0; Y[0] = rnd(100, 200);
            for (int i = 0; i < cnt; i++) {
                theta -= delta;
                X[i + 1] = X[i] + vec[i]; Y[i + 1] = Y[i] + vec[i] * tan(theta);
            }

            vec = gen(cnt);
            theta = PI / 2;
            X[n - 1] = 0; Y[n - 1] = rnd(-200, -100);
            for (int i = 0; i < cnt; i++) {
                theta -= delta;
                X[n - 2 - i] = X[n - 1 - i] + vec[i]; Y[n - 2 - i] = Y[n - 1 - i] - vec[i] * tan(theta);
            }            
        }
        if (Y[cnt] - Y[cnt + 1] < 1 + EPS) continue;
        if (check()) break;
    }
    for (int i = n - 1; i >= 0; i--) printf("%.12f %.12f\n", X[i], Y[i]);
    return 0;
}
