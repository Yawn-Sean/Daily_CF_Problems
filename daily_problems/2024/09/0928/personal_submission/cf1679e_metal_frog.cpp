const int N = 1005;
const ll mod = 998244353;
bool valid[N][N];
int require[N][N], contri[N][N], wildcard[N][N];
ll dp[18][1 << 18];

ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1)
      ans = ans * b % mod;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?')
      tot++;
  }
  for (int i = 0; i < n; i++) {
    valid[i][i] = true;
    if (s[i] == '?') {
      contri[i][i] = 1;
      wildcard[i][i] = 1;
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    valid[i][i + 1] = false;
    if (s[i] == s[i + 1]) {
      valid[i][i + 1] = true;
      if (s[i] == '?') {
        contri[i][i + 1] = 1;
        wildcard[i][i + 1] = 2;
      }
    } else if (s[i] == '?' || s[i + 1] == '?') {
      char ch = (s[i] == '?') ? s[i + 1] : s[i];
      valid[i][i + 1] = true;
      require[i][i + 1] |= (1 << (ch - 'a'));
      wildcard[i][i + 1] = 1;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len - 1;
      if (!valid[i + 1][j - 1]) {
        valid[i][j] = false;
        continue;
      }
      valid[i][j] = true;
      contri[i][j] = contri[i + 1][j - 1];
      require[i][j] = require[i + 1][j - 1];
      wildcard[i][j] = wildcard[i + 1][j - 1];
      if (s[i] == s[j]) {
        contri[i][j] += (s[i] == '?');
        wildcard[i][j] += 2 * (s[i] == '?');
      } else if (s[i] == '?' || s[j] == '?') {
        char ch = (s[i] == '?') ? s[j] : s[i];
        require[i][j] |= (1 << (ch - 'a'));
        wildcard[i][j]++;
      } else {
        valid[i][j] = false;
      }
    }
  }
  ll base = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (valid[i][j]) {
        for (int k = 0; k < 18; k++) {
          ll val = modpow(k, contri[i][j] + (tot - wildcard[i][j]));
          dp[k][require[i][j]] += val;
          dp[k][require[i][j]] %= mod;
        }
      }
    }
  }
  for (int k = 0; k < 18; k++) {
    for (int i = 0; i < 18; i++) {
      for (int j = 0; j < (1 << 18); j++) {
        if (j & (1 << i)) {
          dp[k][j] += dp[k][j ^ (1 << i)];
          dp[k][j] %= mod;
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int mask = 0;
    string ss;
    cin >> ss;
    for (int i = 0; i < ss.length(); i++) {
      mask |= (1 << (ss[i] - 'a'));
    }
    cout << dp[sz(ss)][mask] << "\n";
  }
}
