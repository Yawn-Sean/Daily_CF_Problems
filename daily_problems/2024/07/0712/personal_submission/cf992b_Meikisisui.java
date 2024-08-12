import java.io.PrintWriter;
import java.util.Scanner;

public class Test3 {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        long l = sc.nextInt();
        long r = sc.nextInt();
        long x = sc.nextInt();
        long y = sc.nextInt();
        Test3 test = new Test3();
        long res = test.nastyaStudies(l, r, x, y);
        pw.print(res);
        pw.close();
        sc.close();
    }

    private long nastyaStudies(long l, long r, long x, long y) {
        long res = 0;
        for (long ez = 1; ez * ez <= y; ez++) {
            // ez因子 
            if (y % ez == 0) {
                long j = x * (y / ez);
                if (ez >= l && ez <= r && j >= l && j <= r && gcd(ez, j) == x)
                    res++;
                // vn因子
                long vn = y / ez;
                if (ez != vn) {
                    long jj = x * (y / vn);
                    if (vn >= l && vn <= r && jj >= l && jj <= r && gcd(vn, jj) == x)
                        res++;
                }
            }
        }
        return res;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

}
