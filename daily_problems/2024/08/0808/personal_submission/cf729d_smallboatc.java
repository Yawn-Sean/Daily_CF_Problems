import java.util.*;

public class Main {
    static final int N = 200010;
    static int[] f = new int[N];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), a = sc.nextInt();
        int b = sc.nextInt(), k = sc.nextInt();
        char[] cs = sc.next().toCharArray();
        int tot = 0, cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (cs[i] == '1') {
                cnt = 0;
                continue;
            }
            cnt ++;
            if (cnt == b) {
                f[tot ++] = i + 1;
                cnt = 0;
            }
        }
        tot -= a - 1;
        System.out.println(tot);
        for (int i = 0; i < tot; i ++) {
            System.out.print(f[i] + " ");
        }
    }
}
