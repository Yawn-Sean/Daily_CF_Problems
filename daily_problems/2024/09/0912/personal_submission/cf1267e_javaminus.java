public class Main{
    private static void solve() throws IOException {
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            ss = sc.nextLine().split(" ");
            for (int j = 0; j < n; j++) {
                grid[i][j] = Integer.parseInt(ss[j]);
            }
        }
        int ans = Integer.MAX_VALUE;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) { // 枚举前n个人
            int[][] diff = new int[m][2];
            int sum = 0;
            for (int j = 0; j < m; j++) {
                diff[j][0] = grid[j][i] - grid[j][n - 1];
                diff[j][1] = j;
                sum += diff[j][0];
            }
            Arrays.sort(diff, (a, b) -> a[0] - b[0]);
            for (int j = 0; j < m; j++) {
                if (sum >= 0) {
                    if (j < ans) {
                        ans = j;
                        list.clear();
                        for (int k = 0; k < j; k++) {
                            list.add(diff[k][1]);
                        }
                    }
                }
                sum -= diff[j][0];
            }
        }
        if (ans == Integer.MAX_VALUE) {
            sc.println(m);
            for (int i = 1; i <= m; i++) {
                sc.print(i + " ");
            }
        }else{
            sc.println(ans);
            for (int x : list) {
                sc.print((x + 1) + " ");
            }
        }
    }
}
