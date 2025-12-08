#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct UInt128 {
    unsigned long long low;
    unsigned long long high;

    UInt128() : low(0), high(0) {}
    UInt128(unsigned long long l) : low(l), high(0) {}

    void add(const UInt128& other) {
        unsigned long long prev_low = low;
        low += other.low;
        if (low < prev_low) {
            high++;
        }
        high += other.high;
    }

    int popcount() const {
        return __builtin_popcountll(low) + __builtin_popcountll(high);
    }
};

vector<int> add_bits(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    c.reserve(n + 1);
    for (size_t i = 0; i < n || carry; ++i) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        c.push_back(sum % 2);
        carry = sum / 2;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    int k;
    cin >> n >> m >> k;
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }

    long long diff = abs(n - m);

    if (diff > 105) {
        vector<vector<UInt128>> C(k + 1, vector<UInt128>(k + 1));
        C[0][0] = UInt128(1);
        for (int i = 1; i <= k; ++i) {
            C[i][0] = UInt128(1);
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i-1][j-1];
                C[i][j].add(C[i-1][j]);
            }
            C[i][i] = UInt128(1);
        }

        long long total_ones = 0;
        for (int i = 0; i <= k; ++i) {
            total_ones += C[k][i].popcount();
        }
        cout << total_ones << endl;
    } else {
        vector<int> res;
        res.push_back(1);

        for (int i = 0; i < k; ++i) {
            vector<int> shifted;
            shifted.reserve(res.size() + diff);
            for (int j = 0; j < diff; ++j) shifted.push_back(0);
            for (int bit : res) shifted.push_back(bit);
            
            res = add_bits(res, shifted);
        }

        long long count = 0;
        for (int bit : res) {
            if (bit) count++;
        }
        cout << count << endl;
    }

    return 0;
}
