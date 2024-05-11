//题目理解  符合前d个条件，前d个条件  已经连通的边可以作为自由边 增加连通块的数量  返回最大连通块数-1
//参考博客：https://blog.csdn.net/qq_50285142/article/details/122809066
import java.util.*;

public class d1069 {
    private static final int MAXN = 1000 + 5;
    private static int[] f = new int[MAXN];
    private static int[] sum = new int[MAXN];
    private static int n, d, cnt = 0;

    private static int find(int k) {
        return k == f[k] ? k : (f[k] = find(f[k]));
    }

    private static void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            cnt++;
            return;
        }
        f[x] = y;
        sum[y] += sum[x];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        d = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            f[i] = i;
            sum[i] = 1;
        }

        for (int i = 1; i <= d; i++) {
            List<Integer> v = new ArrayList<>();
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            merge(x, y);

            for (int j = 1; j <= n; j++) {
                if (j == find(j)) {
                    v.add(sum[j]);
                }
            }

            Collections.sort(v, Collections.reverseOrder());
            int ans = 0;
            for (int j = 0; j < v.size() && j <= cnt; j++) {
                ans += v.get(j);
            }
            ans--;

            System.out.println(ans);
        }

        scanner.close();
    }
}
