Z dp[110][110 * 25];

int main() {
  dp[0][0] = 1;
  for (int i = 1; i <= 100; i ++) {
    Z temp = 0;
    for (int j = 0; j <= i * 25; j ++) {
      temp += dp[i - 1][j];
      if (j >= 26)
        temp -= dp[i - 1][j - 26];
      dp[i][j] = temp;
    } 
  }

  multiCase() {
    string s; cin >> s;
    int cnt = 0;
    for (auto e: s)
      cnt = (cnt + e - 'a');
    printf("%d\n", (int)(dp[s.size()][cnt] - 1));
  }
  return 0;
}
