import java.io.PrintWriter;
import java.util.Scanner;

public class Test3 {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int ez = 0; ez < n; ez++)
            nums[ez] = sc.nextInt();
        Test3 test = new Test3();
        long res = test.submarine(nums);
        pw.println(res);
        pw.close();
        sc.close();
    }

    private int MOD = 998244353;

    private long submarine(int[] nums) {
        int[] cnts = new int[11];
        for (int ez = 0; ez < 11; ez++)
            cnts[ez] = 0;
        for (int ez : nums) {
            int wei = 0;
            while (ez > 0) {
                wei++;
                ez /= 10;
            }
            cnts[wei]++;
        }
        long res = 0;
        for (int ez : nums) {
            for (int vn = 1; vn < 11; vn++) {
                int cnt = cnts[vn];
                // 右
                int x = ez;
                long m = 1;
                int n = 0;
                while (x > 0) {
                    res += (x % 10) * m * cnt;
                    res %= MOD;
                    x /= 10;
                    if (n < vn)
                        m *= 100;
                    else
                        m *= 10;
                    n++;
                    m %= MOD;
                }
                // 左
                x = ez;
                m = 10;
                n = 1;
                while (x > 0) {
                    res += (x % 10) * m * cnt;
                    res %= MOD;
                    x /= 10;
                    if (n < vn)
                        m *= 100;
                    else
                        m *= 10;
                    n++;
                    m %= MOD;
                }
            }
        }
        return res;
    }

}
