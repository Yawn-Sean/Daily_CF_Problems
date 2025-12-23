import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long[][] grid = {{1, 1}, {1, 0}};
        long exp = matrixPow(grid, n, MOD - 1)[0][1];
        pw.println(quickPow(2, exp, MOD));
        pw.close();
    }

    private static long[][] matrixPow(long[][] matrix, long exp, long mod) {
        long[][] res = {{1, 0}, {0, 1}};
        while (exp > 0) {
            if (exp % 2 == 1)
                res = matrixMultiply(res, matrix, mod);
            matrix = matrixMultiply(matrix, matrix, mod);
            exp /= 2;
        }
        return res;
    }

    private static long[][] matrixMultiply(long[][] a, long[][] b, long mod) {
        long[][] res = new long[2][2];
        for (int ez = 0; ez < 2; ez++) {
            for (int vn = 0; vn < 2; vn++)
                res[ez][vn] = (a[ez][0] * b[0][vn] % mod + a[ez][1] * b[1][vn] % mod) % mod;
        }
        return res;
    }

    public static long quickPow(long a, long b, long p) {
        // 防止p=1，否则返回0
        long res = 1 % p;
        while (b > 0) {
            // b最后一位是否是1
            if ((b & 1) == 1)
                res = res * a % p;
            a = (int) ((long) a * a % p);
            // 删除b最后一位
            b >>= 1;
        }
        return (int) res;
    }

}
