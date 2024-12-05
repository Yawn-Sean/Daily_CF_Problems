static void solve() {
    char[] a = sc.next().toCharArray(), b = sc.next().toCharArray();
    int cnt = 0;
    for (char c : a) {
        cnt += c - '0';
    }
    if (cnt % 2 != 0) {
        cnt++;
    }
    for (char c : b) {
        cnt -= c - '0';
    }
    out.println(cnt >= 0 ? "YES" : "NO");
}
