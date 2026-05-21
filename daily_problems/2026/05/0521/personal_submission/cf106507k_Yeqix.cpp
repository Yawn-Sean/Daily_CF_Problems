#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

template <typename T>
T inv(const T& x, const T& y) {
	assert(x != 0);
	T u = 0, v = 1, a = x, m = y, t;
	while (a != 0) {
		t = m / a;
		swap(a, m -= t * a);
		swap(u -= t * v, v);
	}
	assert(m == 1);
	return u;
}

template <typename T>
class Modular {
public:
	using Type = typename decay<decltype(T::value)>::type;

	constexpr Modular() : value() {}
	template <typename U>
	Modular(const U& x) {
		value = normalize(x);
	}

	template <typename U>
	static Type normalize(const U& x) {
		Type v = static_cast<Type>((-mod() <= x && x < mod()) ? x : x % mod());
		if (v < 0)
			v += mod();
		return v;
	}

	const Type& operator()() const { return value; }
	template <typename U>
	explicit operator U() const {
		return static_cast<U>(value);
	}
	constexpr static Type mod() { return T::value; }

	Modular& operator+=(const Modular& other) {
		if ((value += other.value) >= mod())
			value -= mod();
		return *this;
	}
	Modular& operator-=(const Modular& other) {
		if ((value -= other.value) < 0)
			value += mod();
		return *this;
	}
	template <typename U>
	Modular& operator+=(const U& other) {
		return *this += Modular(other);
	}
	template <typename U>
	Modular& operator-=(const U& other) {
		return *this -= Modular(other);
	}
	Modular& operator++() { return *this += 1; }
	Modular& operator--() { return *this -= 1; }
	Modular operator++(int) {
		Modular result(*this);
		*this += 1;
		return result;
	}
	Modular operator--(int) {
		Modular result(*this);
		*this -= 1;
		return result;
	}
	Modular operator-() const { return Modular(-value); }

	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type & operator*=(const Modular& rhs) {
#ifdef _WIN32
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
		value = m;
#else
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
		return *this;
	}
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type & operator*=(const Modular& rhs) {
		long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template <typename U = T>
	typename enable_if < !is_integral<typename Modular<U>::Type>::value, Modular >::type & operator*=(const Modular& rhs) {
		value = normalize(value * rhs.value);
		return *this;
	}

	Modular& operator/=(const Modular& other) { return *this *= Modular(inv(other.value, mod())); }

	friend const Type& abs(const Modular& x) { return x.value; }
	template <typename U>
	friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename U>
	friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename U>
	friend bool operator>(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename V, typename U>
	friend V& operator>>(V& stream, Modular<U>& number);

private:
	Type value;
};

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
	return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
	return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
	return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
	return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
	return lhs.value < rhs.value;
}

template <typename T>
bool operator>(const Modular<T>& lhs, const Modular<T>& rhs) {
	return lhs.value > rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
	return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
	return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
	return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
	return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
	return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> qpow(const Modular<T>& a, const U& b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	for (U p = b; p; x *= x, p >>= 1)
		if (p & 1)
			res *= x;
	return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
}
template <typename T>
string to_string(const Modular<T>& number) {
	return to_string(number());
}

template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
	return stream << number();
}

template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
	typename common_type<typename Modular<T>::Type, long long>::type x;
	stream >> x;
	number.value = Modular<T>::normalize(x);
	return stream;
}

// using ModType = int;
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;// for mod can change
// using Mint = Modular<VarMod>;

// constexpr int md = (int)998244353;
constexpr int md = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

struct Fact {
	vector<Mint> fact, factinv;
	const int n;
	Fact(const int& _n) : n(_n), fact(_n + 1, Mint(1)), factinv(_n + 1) {
		for (int i = 1; i <= n; ++i)
			fact[i] = fact[i - 1] * i;
		factinv[n] = inv(fact[n](), md);
		for (int i = n; i; --i)
			factinv[i - 1] = factinv[i] * i;
	}
	Mint C(const int& n, const int& k) {
		if (n < 0 || k < 0 || n < k)
			return 0;
		return fact[n] * factinv[k] * factinv[n - k];
	}
	Mint A(const int& n, const int& k) {
		if (n < 0 || k < 0 || n < k)
			return 0;
		return fact[n] * factinv[n - k];
	}
	Mint invC(const int& n, const int& k) {
		if (n < 0 || k < 0 || n < k)
			return 0;
		return factinv[n] * fact[k] * fact[n - k];
	}
	Mint invA(const int& n, const int& k) {
		if (n < 0 || k < 0 || n < k)
			return 0;
		return fact[n - k] * factinv[n];
	}
};

Fact fc(200001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	Mint res = 0;
	vector<Mint> dp(n + 1);
	vector<i64> son(n + 1);
	auto dfs = [&](this auto && dfs, int u, int fa, int dep)->void{
		for (const auto& v : edge[u]) {
			if (v == fa) {
				continue;
			}
			dfs(v, u, dep + 1);
			son[u] += son[v];
			dp[u] += dp[v];
		}
		son[u]++;
		if (son[u] >= k) {
			Mint v = fc.C(son[u], k) - dp[u];
			res += v * dep;
			dp[u] += v;
		}
	};
	dfs(1, 0, 0);

	vector<Mint> ans(n + 1);
	auto get = [&](this auto && get, int u, int fa)->void{
		ans[u] = res;
		for (const auto& v : edge[u]) {
			if (v == fa) {
				continue;
			}
			Mint cur = fc.C(son[v], k);
			son[u] -= son[v], son[v] += son[u];
			cur -= fc.C(son[u], k);
			res -= cur;
			get(v, u);
			res += cur;
			son[v] -= son[u], son[u] += son[v];
		}
	};
	get(1, 0);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}