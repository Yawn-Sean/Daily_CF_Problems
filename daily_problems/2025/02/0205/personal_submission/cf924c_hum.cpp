#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << "," << a.second << ")";
}

template<typename T, size_t N>
ostream &operator<<(ostream &out, const array<T, N> &a) {
  out << "[";
  for (size_t i = 0; i < N; ++i) out << a[i] << (i != N - 1 ? ", " : "");
  return out << "]";
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &a) {
  out << "[";
  for (size_t i = 0; i < a.size(); ++i) out << a[i] << (i != a.size() - 1 ? ", " : "");
  return out << "]";
}

template<typename T, class Cmp>
ostream &operator<<(ostream &out, const set<T, Cmp> &a) {
  out << "{";
  bool first = true;
  for (auto &v: a) out << (first ? "" : ", ") << v, first = false;
  return out << "}";
}

template<typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const map<U, T, Cmp> &a) {
  out << "{";
  bool first = true;
  for (auto &p: a) out << (first ? "" : ", ") << p.first << ":" << p.second, first = false;
  return out << "}";
}

auto rng = mt19937(random_device()());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 res = -accumulate(a.begin(), a.end(), 0ll);
  for (int i = n - 2; i >= 0; i--)
    a[i] = max(a[i], a[i + 1] - 1);

  res += a[0];

  for (int i = 1; i < n; i++) {
    a[i] = max(a[i - 1], a[i]);
    res += a[i];
  }
  cout << res << endl;
}
