#include <bits/stdc++.h>
using namespace std;

struct Bigint {
	std::vector<long long> a;

	Bigint() { }

	Bigint(const std::string& s) {
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] >= '0' && s[i] <= '9') a.emplace_back(s[i] - '0');
		}
		while (a.size() >= 2 && a.back() == 0) a.pop_back();
	}

	Bigint(long long x) {
		if (x == 0) { a.emplace_back(0); return; }
		if (x < 0) x = ~x + 1;
		while (x) a.emplace_back(x % 10), x /= 10;
	}

	friend long long Bigint_to_int(const Bigint& B) {
		long long b = 0;
		for (int i = B.a.size() - 1; i >= 0; i--) {
			b = b * 10 + B.a[i];
		}
		return b;
	}

	Bigint operator + (const Bigint& B) {
		Bigint C;
		std::vector<long long>& c = C.a;
		const std::vector<long long>& b = B.a;
		long long t = 0;
		for (int i = 0; i < a.size() || i < b.size() || t; i++) {
			if (i < a.size()) t += a[i];
			if (i < b.size()) t += b[i];
			c.emplace_back(t & 1); // 0bxxx
			t /= 2;
		}
		return C;
	}

	Bigint operator + (long long b) {
		return *this + Bigint(b);
	}

	Bigint operator * (long long b) {
		long long t = 0;
		Bigint C;
		std::vector<long long>& c = C.a;
		for (int i = 0; i < a.size() || t; i++) {
			if (i < a.size()) t += a[i] * b;
			c.emplace_back(t % 10);
			t /= 10;
		}
		while (c.size() >= 2 && c.back() == 0) c.pop_back();
		return C;
	}

	Bigint operator * (const Bigint& B) {
		const auto& A = this->a;
		Bigint C;
		C.a = std::vector<long long>(A.size() + B.a.size());
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.a.size(); j++) {
				C.a[i + j] += A[i] * B.a[j];
			}
		}
		long long t = 0;
		for (int i = 0; i < C.a.size(); i++) {
			t += C.a[i];
			C.a[i] = t % 10;
			t /= 10;
		}
		while (C.a.size() >= 2 && C.a.back() == 0) C.a.pop_back();
		return C;
	}

	Bigint operator - (const Bigint& B) {
		Bigint C;
		std::vector<long long>& c = C.a;
		const std::vector<long long>& b = B.a;
		long long t = 0;
		for (int i = 0; i < a.size(); i++) {
			t += a[i];
			if (i < b.size()) t -= b[i];
			c.emplace_back((t + 10) % 10);
			if (t < 0) t = -1;
			else t = 0;
		}
		while (c.size() >= 2 && c.back() == 0) c.pop_back();
		return C;
	}

	Bigint operator - (long long b) {
		return *this - Bigint(b);
	}

	Bigint operator / (long long b) {
		Bigint C;
		std::vector<long long>& c = C.a;
		long long t = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			t = t * 10 + a[i];
			c.emplace_back(t / b);
			t %= b;
		}//t as the remainder == A%b
		reverse(c.begin(), c.end());
		while (c.size() >= 2 && c.back() == 0) c.pop_back();
		return C;
	}

	Bigint operator / (const Bigint& B) {
		return (*this) / Bigint_to_int(B);
	}

	Bigint operator % (long long b) {
		long long t = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			t = (t * 10 + a[i]) % b;
		}
		return Bigint(t);
	}

	Bigint operator % (const Bigint& B) {
		return (*this) % Bigint_to_int(B);
	}

	int cmp(const Bigint& B) {
		const std::vector<long long>& b = B.a;
		if (a.size() != b.size()) {
			return a.size() > b.size() ? 1 : -1;
		}
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] != b[i]) {
				return a[i] > b[i] ? 1 : -1;
			}
		}
		return 0;
	};

	void operator += (const auto& b) { *this = *this + b; }
	void operator -= (const auto& b) { *this = *this - b; }
	void operator *= (const auto& b) { *this = *this * b; }
	void operator /= (const auto& b) { *this = *this / b; }
	void operator %= (const auto& b) { *this = *this % b; }
	bool operator > (const auto& b) { return cmp(b) == 1; }
	bool operator < (const auto& b) { return cmp(b) == -1; }
	bool operator == (const auto& b) { return cmp(b) == 0; }
	bool operator != (const auto& b) { return cmp(b) != 0; }
	bool operator >= (const auto& b) { return cmp(b) != -1; }
	bool operator <= (const auto& b) { return cmp(b) != 1; }

	friend std::ostream& operator << (std::ostream& o, const Bigint& t) {
		for (int i = t.a.size() - 1; i >= 0; i--) {
			o << t.a[i];
		}
		return o;
	}

	friend std::istream& operator >> (std::istream& o, Bigint& t) {
		std::string s; o >> s;
		t = s;
		return o;
	}
};

void soviet() {
	int n, m, k; std::cin >> n >> m >> k;
	if (n == m) {
		std::cout << 1;
		return;
	}
	int v = std::abs(n - m);
	std::vector<Bigint> combs = {{1}};

	for (int i = 1; i <= k; i++){
		std::vector<Bigint> ncombs(i + 1);
		ncombs[0] = {1};
		ncombs[i] = {1};
		for (int j = 1; j < i; j++) {
			ncombs[j] = combs[j - 1] + combs[j];
		}
		combs = ncombs;
	}
	Bigint carry = 0;
	long long ans = 0;
	for (auto &x: combs) {
		x += carry;
		int val = std::min(v, (int)x.a.size());

		Bigint ncarry;

		for (int i = 0; i < x.a.size(); i++) {
			if (i < val) ans += x.a[i];
			else ncarry.a.emplace_back(x.a[i]);
		}
		carry = ncarry;
	}
	for (auto &x: carry.a) ans += x;
	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
