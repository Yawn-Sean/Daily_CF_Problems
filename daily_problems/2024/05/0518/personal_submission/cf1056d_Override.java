//dfs遍历对应子树的节点个数  排序输出
import java.io.*;
import java.util.*;

public class d1056 {
    static ArrayList<Integer>[] g;
    static int[] sum;
    static int n, x;

    public static void dfs(int u) {
        if (g[u].size() == 0) {
            sum[u] = 1;
            return;
        }
        int siz = g[u].size();
        for (int i = 0; i < siz; i++) {
            dfs(g[u].get(i));
            sum[u] += sum[g[u].get(i)];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        g = new ArrayList[n + 1];
        sum = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 2; i <= n; i++) {
            x = sc.nextInt();
            g[x].add(i);
        }
        dfs(1);
        Arrays.sort(sum);
        for (int i = 1; i <= n; i++) {
            System.out.print(sum[i] + " ");
        }
    }
}
