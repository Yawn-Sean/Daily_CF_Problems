import java.util.Scanner;
public class a623 {

    static int[] head = new int[505];
    static int[] to = new int[250005];
    static int[] ne = new int[250005];
    static int idx = 1;
    static int n, m, d[];
    static char c[], mapp[] = {'d', 'a', 'c'};
    static int Color;

    static void add(int u, int v) {
        to[idx] = v;
        ne[idx] = head[u];
        head[u] = idx++;
    }

    static void search(int u, int color) {
        c[u] = mapp[color];
        for (int i = head[u]; i != 0; i = ne[i]) {
            int v = to[i];
            if (c[v] == '\u0000') search(v, color);
        }
    }

    static boolean check() { 
        int A = 0, B = 0, C = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] == '\u0000') return false;
            if (c[i] == 'a') A++;
            if (c[i] == 'b') B++;
            if (c[i] == 'c') C++;
        }
        for (int i = 1; i <= n; i++) {
            if (c[i] == 'a' && d[i] != B + A - 1) return false;
            if (c[i] == 'c' && d[i] != B + C - 1) return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        d = new int[n + 1];
        c = new char[n + 1];

        for (int i = 1; i <= m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            d[u]++;
            d[v]++;
            add(u, v);
            add(v, u);
        }

        for (int i = 1; i <= n; i++) {
            if (d[i] == n - 1) c[i] = 'b';
        }

        for (int i = 1; i <= n; i++) {
            if (c[i] == '\u0000') {
                if (++Color >= 3) break;
                search(i, Color);
            }
        }

        if (!check()) {
            System.out.println("No");
            return;
        }

        System.out.println("Yes");
        for (int i = 1; i <= n; i++) {
            System.out.print(c[i]);
        }
    }
}
