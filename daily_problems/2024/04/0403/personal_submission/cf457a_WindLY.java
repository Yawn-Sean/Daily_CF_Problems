public class cf457a_WindLY {
    // https://codeforces.com/contest/457/submission/254842871
    static double q;
    static {
        q = Math.sqrt(5);
        q += 1;
        q /= 2;
    }
    public static void main(String[] args) throws IOException {
        String sa = sc.readLine(), sb = sc.readLine();
        int m = sa.length(), n = sb.length();
        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < n - m; i++) {
            a.append(0);
        }
        a.append(sa);
        for (int i = 0; i < m - n; i++) {
            b.append(0);
        }
        b.append(sb);
        int[] s = f(a, b);
        n = s.length;
        boolean f = false;
        for (int i = 0; i < n - 2; i++) {
            if (Math.abs(s[i]) >= 2) {
                out.println(s[i] >= 2 ? ">" : "<");
                f = true;
                break;
            }
            if (i + 1 < n) s[i + 1] += s[i];
            if (i + 2 < n) s[i + 2] += s[i];
        }
        if (!f) {
            if (n == 1) {
                out.println(s[0] > 0 ? ">" : (s[0] < 0 ? "<" : "="));
            } else {
                double d = s[n - 2] * q + s[n - 1];
                out.println(d > 0 ? ">" : (d < 0 ? "<" : "="));
            }
        }
        out.flush();
    }
    static int[] f(StringBuilder a, StringBuilder b) {
        int[] ans = new int[a.length()];
        for (int i = 0; i < a.length(); i++) {
            ans[i] = a.charAt(i) - b.charAt(i);
        }
        return ans;
    }
}