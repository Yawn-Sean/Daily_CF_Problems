import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] nums = new int[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());

        long gcdAll = 0;
        for (int ez = 0; ez < n; ez++)
            gcdAll = gcd(gcdAll, nums[ez]);
        long res = 0;
        if (gcdAll != 1) {
        } else {
            for (int ez = 0; ez < n - 1; ez++) {
                // 相邻奇数一次变相邻偶数
                if (nums[ez] % 2 == 1 && nums[ez + 1] % 2 == 1) {
                    nums[ez] = nums[ez + 1] = 2;
                    res++;
                }
            }
            for (int ez = 0; ez < n; ez++) {
                // 相邻奇数偶数两次变相邻偶数
                if (nums[ez] % 2 == 1)
                    res += 2;
            }
        }
        pw.println("YES");
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long gcd(long a, long b) {
        if (a < b) {
            long temp = a;
            a = b;
            b = temp;
        }
        return b == 0 ? a : gcd(b, a % b);
    }

}
