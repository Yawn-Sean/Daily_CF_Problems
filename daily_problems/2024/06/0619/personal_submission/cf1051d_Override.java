import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;


public class d1051 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        List<List<Integer>> dp = new ArrayList<>();
        List<List<Integer>> ndp = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            dp.add(new ArrayList<>(2 * n + 1));
            ndp.add(new ArrayList<>(2 * n + 1));
            for (int j = 0; j <= 2 * n; j++) {
                dp.get(i).add(0);
                ndp.get(i).add(0);
            }
        }
        int mod = 998244353;

        dp.get(0).set(1, 1);
        dp.get(1).set(2, 1);
        dp.get(2).set(2, 1);
        dp.get(3).set(1, 1);

        int[][] grid = {
                {0, 1, 1, 1},
                {0, 0, 2, 0},
                {0, 2, 0, 0},
                {1, 1, 1, 0}
        };

        for (int i = 1; i < n; i++) {
            for (int msk = 0; msk < 4; msk++) {
                for (int j = 0; j <= k; j++) {
                    if (dp.get(msk).get(j) > 0) {
                        for (int nmsk = 0; nmsk < 4; nmsk++) {
                            int nj = j + grid[msk][nmsk];
                            ndp.get(nmsk).set(nj, (ndp.get(nmsk).get(nj) + dp.get(msk).get(j)) % mod);
                        }
                    }
                }
            }
            for (int msk = 0; msk < 4; msk++) {
                for (int j = 0; j <= k; j++) {
                    dp.get(msk).set(j, ndp.get(msk).get(j));
                    ndp.get(msk).set(j, 0);
                }
            }
        }

        int ans = 0;
        for (int msk = 0; msk < 4; msk++) {
            ans = (ans + dp.get(msk).get(k)) % mod;
        }
        System.out.println(ans);
    }
}
