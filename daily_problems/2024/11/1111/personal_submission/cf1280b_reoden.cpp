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


int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) {
		int N, M;
		std::cin >> N >> M;
		std::vector grid(N, std::vector<int>(M));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			std::string s;
			std::cin >> s;
			for (int j = 0; j < M; j++) {
				grid[i][j] = (s[j] == 'A');
				cnt += grid[i][j];
			}
		}

		if (cnt == 0) {
			std::cout << "MORTAL" << '\n';
			continue;
		}

		if (cnt == N * M) {
			std::cout << 0 << '\n';
			continue;
		}

		bool ok = false;
		for (const auto &_ : {0, M-1}) {
			cnt = 0;
			for (int i = 0; i < N; i++) { 
				cnt += grid[i][_];
			}
			// DEBUG << KV(_) << ' ' << KV(cnt) << ' ' << KV(ok) << '\n';
			if (cnt == N) {
				ok = true;
				break;
			}
		}

		for (const auto &_ : {0, N-1}) {
			cnt = 0;
			for (int i = 0; i < M; i++) {
				cnt += grid[_][i];
			}

			// DEBUG << KV(_) << ' ' << KV(cnt) << ' ' << KV(ok) << '\n';
			if (cnt == M) {
				ok = true;
				break;
			}
		}

		// DEBUG << KV(ok) << '\n';
		if (ok) {
			std::cout << 1 << '\n';
			continue;
		}

		for (int i = 1; i+1 < N; i++) {
			cnt = 0;
			for (int j = 0; j < M; j++) {
				cnt += grid[i][j];
			}
			if (cnt == M) {
				ok = true;
				break;
			}
		}

		for (int j = 1; j+1 < M; j++) {
			cnt = 0;
			for (int i = 0; i < N; i++) {
				cnt += grid[i][j];
			}
			if (cnt == N) {
				ok = true;
				break;
			}
		}
		if (grid[0][0] || grid[0][M-1] || grid[N-1][0] || grid[N-1][M-1] || ok) {
			std::cout << 2 << '\n';
		} else {
			for (int i = 0; i < N; i++) {
				ok |= (grid[i][0] || grid[i][M-1]);
			}
			for (int i = 0; i < M; i++) {
				ok |= (grid[0][i] || grid[N-1][i]);
			}

			std::cout << (4-ok) << '\n';
		}
	}
}
