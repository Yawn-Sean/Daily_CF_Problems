import java.util.Scanner;

public class c960 {
    static int N=1000005;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long d = sc.nextLong();
        int n = 0, m = 0;
        long[] a = new long[2 * N];

        for (int i = 31; i >= 0; i--) {
            if ((x & (1L << i)) != 0) {
                a[m] = i;
                a[m + 1] = 1;
                n += i + 1;
                m += 2;
            }
        }

        System.out.println(n);
        for (int i = 0; i < m; i++) {
            while (a[i]-- > 0) {
                System.out.print((1 + d * i) + " ");
            }
        }
        System.out.println();
    }
}
