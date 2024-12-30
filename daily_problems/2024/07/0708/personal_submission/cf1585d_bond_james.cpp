/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll=long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

template<typename T>
class FenwickTree {
public:
    explicit FenwickTree(int size) : data(size + 1, 0) {}

    void add(int index, T value) {
        for (++index; index < data.size(); index += index & -index) {
            data[index] += value;
        }
    }

    T sum(int index) const {
        T result = 0;
        for (++index; index > 0; index -= index & -index) {
            result += data[index];
        }
        return result;
    }

    T sum(int left, int right) const {
        if (left > right) return 0;
        return sum(right) - sum(left - 1);
    }

private:
    vector<T> data;
};

void solve(){
    int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x: nums) cin >> x, x --;

        vector<int> cnt(n);
        bool flg = false;

        for (auto &x: nums) {
            if (cnt[x]) flg = true;
            cnt[x] ++;
        }

        if (!flg) {
            int cnt = 0;
            FenwickTree<int> fen(n);
            for (int i = n - 1; i >= 0; i --) {
                cnt ^= fen.sum(0, nums[i]) & 1;
                fen.add(nums[i], 1);
            }
            flg = cnt == 0;
        }
        cout << (flg ? "YES\n" : "NO\n");
}

int32_t main()
{
    int tc=1;
    cin>>tc;
    while(tc--)
    {
    solve();
    }
    return 0;
}