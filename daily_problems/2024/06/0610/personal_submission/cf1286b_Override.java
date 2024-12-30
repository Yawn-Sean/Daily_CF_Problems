
import java.util.*;

public class b1286 {
    static int n;
    static int[] c, temp, ans, Size;
    static List<Integer>[] vec;
    static int root, flag;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        c = new int[n + 1];
        temp = new int[n + 1];
        ans = new int[n + 1];
        Size = new int[n + 1];
        vec = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            temp[i] = i;
            vec[i] = new ArrayList<>();
        }

        for (int i = 1; i <= n; i++) {
            int l = scanner.nextInt();
            c[i] = scanner.nextInt();
            vec[l].add(i);
            if (l == 0) {
                root = i;
            }
        }

        dfs(root);

        if (flag == -1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (int i = 1; i <= n; i++) {
                System.out.print(ans[i] + " ");
            }
        }
    }

    static int find(int x) {
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (temp[i] == 0) continue;
            t++;
            if (t == x) {
                temp[i] = 0;
                return i;
            }
        }
        return -1;
    }

    static void dfs(int now) {
        Size[now] = 1;
        ans[now] = find(c[now] + 1);
        if (ans[now] == -1) {
            flag = -1;
        }
        for (int i = 0; i < vec[now].size(); i++) {
            int x = vec[now].get(i);
            dfs(x);
            Size[now] += Size[x];
        }
        if (Size[now] - 1 < c[now]) {
            flag = -1;
        }
    }
}
