#include <bits/stdc++.h>

#include <concepts>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <ranges>
#include <set>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T> struct Binary {
  static_assert(std::is_integral_v<T>);

  explicit Binary(T value_, int length_ = std::numeric_limits<T>::digits)
      : value{value_}, length{length_} {}

  T value;
  int length;
};

namespace std {

template <typename... T>
ostream &operator<<(ostream &out, const tuple<T...> &t) {
  out << '(';
  std::apply(
      [&out](const T &...args) {
        int index = 0;
        ((out << args << (++index != sizeof...(T) ? ", " : "")), ...);
      },
      t);
  return out << ')';
}

template <typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &v) {
  return out << tuple<A, B>(v.first, v.second);
}

template <typename T> ostream &operator<<(ostream &out, const Binary<T> &b) {
  out << "(";
  for (auto i : std::ranges::iota_view(0, b.length)) {
    out << (b.value >> i & 1);
  }
  return out << ")_2";
}

template <ranges::forward_range Range>
ostream &operator<<(ostream &out, Range &&range)
  requires(!same_as<ranges::range_value_t<Range>, char>)
{
  out << "[";
  bool first = true;
  for (auto &&elem : range) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << elem;
  }
  return out << "]";
}

template <typename T, typename S, typename C>
ostream &operator<<(ostream &out, priority_queue<T, S, C> pq) {
  vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  return out << v;
}

} // namespace std

struct DebugLine {
  explicit DebugLine(int lineno) { std::cerr << lineno << "L "; }

  ~DebugLine() { std::cerr << std::endl; }

  template <typename T> DebugLine &operator<<(T &&v) {
    std::cerr << std::forward<T>(v);
    return *this;
  }
};

#define KV(x) #x "=" << (x) << ";"
#define DEBUG DebugLine(__LINE__)

template <typename T> struct pref_sum_2d {
  int n, m;
  std::vector<std::vector<T>> sum;
  template <typename U>
  pref_sum_2d(const std::vector<std::vector<U>> &a)
      : n((int)a.size()), m((int)a[0].size()), sum(n + 1, std::vector<T>(m + 1)) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        sum[i + 1][j + 1] = a[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
      }
  }
  T query(int x1, int y1, int x2, int y2) {
    return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M, K, Q; std::cin >> N >> M >> K >> Q;
  std::vector timestamps(N, std::vector<int>(M, -1));

  int lo = 0, hi = 0;
  for (int i = 0; i < Q; i++) {
    int x, y, t;
    std::cin >> x >> y >> t;
    x--, y--;
    timestamps[x][y] = t;
    hi = std::max(hi, t);
  }

  int ans = -1;

  auto check = [&](int m) -> bool {
    auto now = timestamps;
    for (auto &row : now) for (auto &x : row) x = (x >= 0 && x <= m);
    // DEBUG << KV(m) << ' ' << KV(now) << '\n';
    auto psum = pref_sum_2d<int>(now);
    for (int i = 0; i+K <= N; i++) {
      for (int j = 0; j+K <= M; j++) {
        // std::cerr << i << ' ' << j << ' ' << i + K << ' ' << j + K << ' ' << psum.query(i, j, i+K-1, j+K-1) << '\n';
        if (psum.query(i, j, i+K-1, j+K-1) == K * K) {
          return true;
        }
      }
    }
    return false;
  };

  while (lo <= hi) {
    int m = (lo + hi) / 2;
    std::cerr << lo << ' ' << hi << ' ' << m << '\n';
    if (check(m)) {
      hi = m - 1;
      ans = m;
    } else {
      lo = m + 1;
    }
  }

  std::cout << ans << '\n';
}
