#include<bits/stdc++.h>
using namespace std;

class Qinput {
	static constexpr int BufferSize = 1 << 20;
	char iBuffer[BufferSize];
	char *q = iBuffer;
	char *p = iBuffer;

	char nextChar() noexcept {
		if (p != q) {
			return *q++;
		}
		q = iBuffer;
		p = q + fread(iBuffer, 1, BufferSize, stdin);
		return p == q ? EOF : *q++;
	}

	template <class T>
	T readInt() {
		T res = 0;
		char ch = nextChar();
		while (!isdigit(ch)) {
			ch = nextChar();
		}

		while (isdigit(ch)) {
			res = res * 10 + ch - '0';
			ch = nextChar();
		}

		return res;
	}

	Qinput() = default;
public:
	static Qinput &shared() {
		static Qinput object;
		return object;
	}

	Qinput &operator>>(int &obj) {
		obj = readInt<int>();
		return *this;
	}

	Qinput &operator>>(long long &obj) {
		obj = readInt<long long>();
		return *this;
	}

	Qinput &operator>>(__int128 &obj) {
		obj = readInt<__int128>();
		return *this;
	}

	Qinput &operator>>(char &ch) {
		do {
			ch = nextChar();
		} while (ch == ' ' or ch == '\n' or ch == '\r' or ch == '\t' or ch == EOF);

		return *this;
	}

	Qinput &operator>>(std::string &str) {
		str.clear();
		char ch = nextChar();
		while (ch == ' ' or ch == '\n' or ch == '\r' or ch == '\t') {
			ch = nextChar();
		}
		while (ch != ' ' and ch != '\n' and ch != '\r' and ch != '\t' and ch != EOF) {
			str += ch;
			ch = nextChar();
		}
		return *this;
	}

	Qinput &getLine(std::string &str) {
		str.clear();
		char ch = nextChar();
		while (ch == '\n' or ch == '\r') {
			ch = nextChar();
		}
		while (ch != '\n' and ch != '\r' and ch != EOF) {
			str += ch;
			ch = nextChar();
		}
		if (ch == '\r') { // 处理 Windows 换行符 \r\n
			ch = nextChar();
			if (ch != '\n' and ch != EOF) {
				q--;
			}
		}
		return *this;
	}
};

class Qoutput {
	template <class T>
	void writeint(T a) {
		if (a < 0) {
			putchar('-');
			writeint(-a);
			return;
		}
		if (a > 9) {
			writeint(a / 10);
		}
		putchar(a % 10 + '0');
	}

	Qoutput() = default;
public:
	static Qoutput &shared() {
		static Qoutput object;
		return object;
	}

	Qoutput &operator<<(int obj) {
		writeint(obj);
		return *this;
	}

	Qoutput &operator<<(long long obj) {
		writeint(obj);
		return *this;
	}

	Qoutput &operator<<(__int128 obj) {
		writeint(obj);
		return *this;
	}

	Qoutput &operator<<(char c) {
		putchar(c);
		return *this;
	}

	Qoutput &operator<<(const std::string &str) {
		for (char c : str) {
			putchar(c);
		}
		return *this;
	}
};
// qin默认不读入负数
Qinput qin = Qinput::shared();
Qoutput qout = Qoutput::shared();

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 1e6;
vector<vector<int>> fac(N + 1);

int main() {
	i64 n, k;
	qin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		qin >> a[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= N; j += i) {
			fac[j].push_back(i);
		}
	}

	vector<vector<int>> fst(k + 1, vector<int>(1, 0));
	for (int i = 1; i <= n; i++) {
		for (const auto& v : fac[a[i]]) {
			fst[v].push_back(i);
		}
	}

	vector<i64> du(n + 1);
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		qin >> u >> v;
		du[u]++, du[v]++;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for (int i = 1; i <= k; i++) {
		int len = fst[i].size() - 1;
		if (n == len) {
			qout << 0 << ' ';
			continue;
		}

		i64 ans = 1, sum = 0;
		for (int j = 1; j <= len; j++) {
			for (const auto&v : edge[fst[i][j]]) {
				if (a[v] % i != 0) {
					ans++;
				} else {
					sum++;
				}
			}
		}

		sum >>= 1;

		qout << ans - len + sum << " ";
	}
	return 0;
}