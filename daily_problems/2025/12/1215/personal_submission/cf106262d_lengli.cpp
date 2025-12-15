#include<bits/stdc++.h>

using namespace std;

struct Bottle {
    double v, a, c;
};

double calculate_integral_area(int n, vector<Bottle> bottles) {
    double total_integral = 0;
    double current_s = 0;
    double current_a = 0;

    for (int i = 0; i < n; ++i) {
        double next_s = current_s + bottles[i].v;
        
        if (i == 0) {
            total_integral += bottles[i].a;
        } else {
            double constant_part = current_a - current_s * bottles[i].c;
            total_integral += constant_part * log(next_s / current_s) + bottles[i].a;
        }
        
        current_s = next_s;
        current_a += bottles[i].a;
    }
    return total_integral;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<Bottle> bottles(n);
    double total_v = 0;
    for (int i = 0; i < n; ++i){
        int x;
        std::cin>>x;
        bottles[i].v = x;
    }
    for (int i = 0; i < n; ++i){
        int x;
        std::cin>>x;
        bottles[i].a = x;
    }
    
    for (int i = 0; i < n; ++i) {
        bottles[i].c = bottles[i].a / bottles[i].v;
        total_v += bottles[i].v;
    }
    sort(bottles.begin(), bottles.end(), [](const Bottle &a, const Bottle &b) {
        return a.c < b.c;
    });
    double min_area = calculate_integral_area(n, bottles);
    sort(bottles.begin(), bottles.end(), [](const Bottle &a, const Bottle &b) {
        return a.c > b.c;
    });
    double max_area = calculate_integral_area(n, bottles);
    double probability = (max_area - min_area) / total_v;
    cout << fixed << setprecision(15) << probability << "\n";

    return 0;
}
