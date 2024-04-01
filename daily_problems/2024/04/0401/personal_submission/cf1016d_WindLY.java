public class cf1016d_WindLY {
    // 构造第一行和第一列，并检查所有数异或是否为0
    // https://codeforces.com/contest/1016/submission/254372311
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0], m = in[1];
        int[] row = na(), col = na();
        int[][] ans = new int[n][m];
        for (int i = 1; i < m; i++) {
            ans[0][i] = col[i];
            row[0] ^= col[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i][0] = row[i];
            col[0] ^= row[i];
        }
        if (col[0] != 0) out.println("NO");
        else {
            out.println("YES");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.print(ans[i][j] + " ");
                }
                out.println();
            }
        }
        out.flush();
    }
}
