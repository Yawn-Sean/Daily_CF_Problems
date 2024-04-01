import java.util.Scanner;

public class Main {
    public static final int MAXN = 200005;
    static int n, m;
    static int[] c = new int[MAXN];
    static int[] a = new int[MAXN];
    static int[] vis = new int[MAXN];
    static int ans;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        
        for (int i = 1; i <= n; i++) {
            c[i] = scanner.nextInt();
        }
        
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            int x = i;
            while (vis[x]==0) { 
                vis[x] = i;
                x = a[x];
            }
            if (vis[x] != i) {
                continue; 
            }
            int key = x, op = c[x];
            while (a[x] != key) { 
                x = a[x];
                op = Math.min(op, c[x]);
            }
            ans += op;
        }

        System.out.println(ans);
    }
}
