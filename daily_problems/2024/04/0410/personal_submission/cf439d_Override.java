import java.util.Scanner;
import java.util.Arrays;

//注意cf的java8  使用sort最坏可以到n方，所以使用java21
//使用Arrays 实现降序排序的时候  要把int 变成Integer  否则报错
//Arrays sort(int []) 最差n2
//Arrays sort(Object []) 最差nlogn
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            Integer[] a = new Integer[n];
            Integer[] b = new Integer[m];

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt();
            }

            Arrays.sort(a);
            Arrays.sort(b, (i1, i2) -> i2 - i1); // 使用lambda表达式实现降序排序

            int nMinM = Math.min(n, m);
            long ans = 0;

            for (int i = 0; i < nMinM; i++) {
                if (b[i] > a[i]) {
                    ans += (long) b[i] - a[i];
                }
            }

            System.out.println(ans);
        }

        scanner.close();
    }
}
