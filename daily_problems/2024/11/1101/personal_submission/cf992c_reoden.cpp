#include <iostream>
#include <cassert>
#include <iostream>

template <typename T> T mod_inv_in_range(T a, T m) {
  // assert(0 <= a && a < m);
  T x = a, y = m;
  // coeff of a in x and y
  T vx = 1, vy = 0;
  while (x) {
    T k = y / x;
    y %= x;
    vy -= k * vx;
    std::swap(x, y);
    std::swap(vx, vy);
  }
  assert(y == 1);
  return vy < 0 ? m + vy : vy;
}

template <typename T> struct extended_gcd_result {
  T gcd;
  T coeff_a, coeff_b;
};
template <typename T> extended_gcd_result<T> extended_gcd(T a, T b) {
  T x = a, y = b;
  // coeff of a and b in x and y
  T ax = 1, ay = 0;
  T bx = 0, by = 1;
  while (x) {
    T k = y / x;
    y %= x;
    ay -= k * ax;
    by -= k * bx;
    std::swap(x, y);
    std::swap(ax, ay);
    std::swap(bx, by);
  }
  return {y, ay, by};
}

template <typename T> T mod_inv(T a, T m) {
  a %= m;
  a = a < 0 ? a + m : a;
  return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  int v;

public:
  modnum() : v(0) {}
  modnum(int64_t v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream &operator<<(std::ostream &out, const modnum &n) {
    return out << int(n);
  }
  friend std::istream &operator>>(std::istream &in, modnum &n) {
    int64_t v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }

  friend bool operator==(const modnum &a, const modnum &b) { return a.v == b.v; }
  friend bool operator!=(const modnum &a, const modnum &b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = mod_inv_in_range(v, MOD);
    return res;
  }
  friend modnum inv(const modnum &m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum &m) { return m.neg(); }

  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }

  modnum &operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum &operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum &operator+=(const modnum &o) {
    v -= MOD - o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = int(int64_t(v) * int64_t(o.v) % MOD);
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= o.inv(); }

  friend modnum operator++(modnum &a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum &a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum &a, const modnum &b) { return modnum(a) += b; }
  friend modnum operator-(const modnum &a, const modnum &b) { return modnum(a) -= b; }
  friend modnum operator*(const modnum &a, const modnum &b) { return modnum(a) *= b; }
  friend modnum operator/(const modnum &a, const modnum &b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}

template <typename U, typename V> struct pairnum {
  U u;
  V v;

  pairnum() : u(0), v(0) {}
  pairnum(long long val) : u(val), v(val) {}
  pairnum(const U &u_, const V &v_) : u(u_), v(v_) {}

  friend std::ostream &operator<<(std::ostream &out, const pairnum &n) {
    return out << '(' << n.u << ',' << ' ' << n.v << ')';
  }
  friend std::istream &operator>>(std::istream &in, pairnum &n) {
    long long val;
    in >> val;
    n = pairnum(val);
    return in;
  }

  friend bool operator==(const pairnum &a, const pairnum &b) {
    return a.u == b.u && a.v == b.v;
  }
  friend bool operator!=(const pairnum &a, const pairnum &b) {
    return a.u != b.u || a.v != b.v;
  }

  pairnum inv() const { return pairnum(u.inv(), v.inv()); }
  pairnum neg() const { return pairnum(u.neg(), v.neg()); }
  pairnum operator-() const { return pairnum(-u, -v); }
  pairnum operator+() const { return pairnum(+u, +v); }

  pairnum &operator++() {
    ++u, ++v;
    return *this;
  }
  pairnum &operator--() {
    --u, --v;
    return *this;
  }

  pairnum &operator+=(const pairnum &o) {
    u += o.u;
    v += o.v;
    return *this;
  }
  pairnum &operator-=(const pairnum &o) {
    u -= o.u;
    v -= o.v;
    return *this;
  }
  pairnum &operator*=(const pairnum &o) {
    u *= o.u;
    v *= o.v;
    return *this;
  }
  pairnum &operator/=(const pairnum &o) {
    u /= o.u;
    v /= o.v;
    return *this;
  }

  friend pairnum operator++(pairnum &a, int) {
    pairnum r = a;
    ++a;
    return r;
  }
  friend pairnum operator--(pairnum &a, int) {
    pairnum r = a;
    --a;
    return r;
  }
  friend pairnum operator+(const pairnum &a, const pairnum &b) { return pairnum(a) += b; }
  friend pairnum operator-(const pairnum &a, const pairnum &b) { return pairnum(a) -= b; }
  friend pairnum operator*(const pairnum &a, const pairnum &b) { return pairnum(a) *= b; }
  friend pairnum operator/(const pairnum &a, const pairnum &b) { return pairnum(a) /= b; }
};

template <typename tag> struct dynamic_modnum {
private:
#if __cpp_inline_variables >= 201606
  // C++17 and up
  inline static int MOD_ = 0;
  inline static uint64_t BARRETT_M = 0;
#else
  // NB: these must be initialized out of the class by hand:
  //   static int dynamic_modnum<tag>::MOD = 0;
  //   static int dynamic_modnum<tag>::BARRETT_M = 0;
  static int MOD_;
  static uint64_t BARRETT_M;
#endif

public:
  // Make only the const-reference public, to force the use of set_mod
  static constexpr int const &MOD = MOD_;

  static void set_mod(int mod) {
    assert(mod > 0);
    MOD_ = mod;
    BARRETT_M = (uint64_t(-1) / MOD);
  }
  static uint32_t barrett_reduce_partial(uint64_t a) {
    return uint32_t(a - uint64_t((__uint128_t(BARRETT_M) * a) >> 64) * MOD);
  }
  static int barrett_reduce(uint64_t a) {
    int32_t res = int32_t(barrett_reduce_partial(a) - MOD);
    return (res < 0) ? res + MOD : res;
  }

  struct mod_reader {
    friend std::istream &operator>>(std::istream &i, mod_reader) {
      int mod;
      i >> mod;
      dynamic_modnum::set_mod(mod);
      return i;
    }
  };
  static mod_reader MOD_READER() { return mod_reader(); }

private:
  int v;

public:
  dynamic_modnum() : v(0) {}
  dynamic_modnum(int64_t v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream &operator<<(std::ostream &out, const dynamic_modnum &n) {
    return out << int(n);
  }
  friend std::istream &operator>>(std::istream &in, dynamic_modnum &n) {
    int64_t v_;
    in >> v_;
    n = dynamic_modnum(v_);
    return in;
  }

  friend bool operator==(const dynamic_modnum &a, const dynamic_modnum &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const dynamic_modnum &a, const dynamic_modnum &b) {
    return a.v != b.v;
  }

  dynamic_modnum inv() const {
    dynamic_modnum res;
    res.v = mod_inv_in_range(v, MOD);
    return res;
  }
  friend dynamic_modnum inv(const dynamic_modnum &m) { return m.inv(); }
  dynamic_modnum neg() const {
    dynamic_modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend dynamic_modnum neg(const dynamic_modnum &m) { return m.neg(); }

  dynamic_modnum operator-() const { return neg(); }
  dynamic_modnum operator+() const { return dynamic_modnum(*this); }

  dynamic_modnum &operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  dynamic_modnum &operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  dynamic_modnum &operator+=(const dynamic_modnum &o) {
    v -= MOD - o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  dynamic_modnum &operator-=(const dynamic_modnum &o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  dynamic_modnum &operator*=(const dynamic_modnum &o) {
    v = barrett_reduce(int64_t(v) * int64_t(o.v));
    return *this;
  }
  dynamic_modnum &operator/=(const dynamic_modnum &o) { return *this *= o.inv(); }

  friend dynamic_modnum operator++(dynamic_modnum &a, int) {
    dynamic_modnum r = a;
    ++a;
    return r;
  }
  friend dynamic_modnum operator--(dynamic_modnum &a, int) {
    dynamic_modnum r = a;
    --a;
    return r;
  }
  friend dynamic_modnum operator+(const dynamic_modnum &a, const dynamic_modnum &b) {
    return dynamic_modnum(a) += b;
  }
  friend dynamic_modnum operator-(const dynamic_modnum &a, const dynamic_modnum &b) {
    return dynamic_modnum(a) -= b;
  }
  friend dynamic_modnum operator*(const dynamic_modnum &a, const dynamic_modnum &b) {
    return dynamic_modnum(a) *= b;
  }
  friend dynamic_modnum operator/(const dynamic_modnum &a, const dynamic_modnum &b) {
    return dynamic_modnum(a) /= b;
  }
};

template <typename T> struct mod_constraint {
  T v, mod;

  friend mod_constraint operator&(mod_constraint a, mod_constraint b) {
    if (a.mod < b.mod) std::swap(a, b);
    if (b.mod == 1) return a;

    extended_gcd_result<T> egcd = extended_gcd<T>(a.mod, b.mod);
    assert(a.v % egcd.gcd == b.v % egcd.gcd);
    T extra = (b.v - a.v % b.mod) / egcd.gcd;
    extra *= egcd.coeff_a;
    extra %= b.mod;
    extra += (extra < 0) ? b.mod : 0;

    return mod_constraint{a.v + extra * a.mod, a.mod * b.mod};
  }
};

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	using num = modnum<1'000'000'007>;
	int64_t N, K;
	std::cin >> N >> K;
  if (N == 0) {
    std::cout << 0 << '\n';
    return 0;
  }
  num ans = pow(num(2), K) * (num(N) * 2 - 1) + 1;
	std::cout << ans << '\n';
}
