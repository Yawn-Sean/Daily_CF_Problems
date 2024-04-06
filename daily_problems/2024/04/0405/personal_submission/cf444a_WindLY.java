public class cf444a_WindLY {
    // https://codeforces.com/contest/444/submission/255115715
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0], m = in[1];
        int[] v = na();
        double max = 0;
        while (m-- > 0) {
            in = na();
            int a = in[0] - 1, b = in[1] - 1, c = in[2];
            max = Math.max(max, (double) (v[a] + v[b]) / c);
        }
        out.println(max);
        out.flush();
    }
}