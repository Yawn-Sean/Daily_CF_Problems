import java.util.Scanner;
 
public class Main {
    public static final int MAXN = 200; 
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            int l = scanner.nextInt();
            int[] val = new int[MAXN];
            for (int i = 1; i <= n; i++) {
                val[i] = scanner.nextInt();
            }
            for (int i = 2; i <= n; i++) {
                val[i] = Math.min(val[i], val[i - 1] * 2);
            }
            long ans = (long) 4e18;
            long sum = 0;
            for (int i = n; i >= 1; i--) {
                int v = 1 << (i - 1);
                int need = l / v;
                sum += (long) need * val[i];
                l %= v;
                ans = Math.min(ans, sum + ((l > 0) ? val[i] : 0));
            }
            System.out.println(ans);
        }
    }
}
