import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n - 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n - 1; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        long[] sum = new long[n];
        sum[0] = 0;
        for (int ez = 1; ez < n; ez++)
            sum[ez] = sum[ez - 1] ^ a[ez - 1];
        int maxBit = 20;
        int[] countS = new int[maxBit + 1];
        for (int ez = 0; ez < n; ez++) {
            for (int k = 0; k <= maxBit; k++) {
                if ((ez & (1 << k)) != 0)
                    countS[k]++;
            }
        }
        int[] countD = new int[maxBit + 1];
        for (int ez = 0; ez < n; ez++) {
            for (int k = 0; k <= maxBit; k++) {
                if ((sum[ez] & (1L << k)) != 0)
                    countD[k]++;
            }
        }
        long x = 0;
        for (int k = 0; k <= maxBit; k++) {
            if (countD[k] == countS[k])
                continue;
            else if (n - countD[k] == countS[k])
                x |= (1L << k);
        }
        long[] b = new long[n];
        for (int ez = 0; ez < n; ez++)
            b[ez] = x ^ sum[ez];
        for (int ez = 0; ez < n; ez++)
            pw.print(b[ez] + " ");
        pw.close();
    }

}
