import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            long[] a = new long[n + 1];
            Pair[] pairArr = new Pair[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++)
                a[ez] = Long.parseLong(st.nextToken());
            for (int ez = 2; ez <= n; ez++)
                pairArr[ez] = new Pair(ez * c - a[ez], ez);
            Arrays.sort(pairArr, 2, (int) n + 1, Comparator.comparingLong(pair -> pair.first));
            long sum = a[1];
            boolean isOk = true;
            for (int ez = 2; ez <= n; ez++) {
                long index = pairArr[ez].first;
                long value = pairArr[ez].second;
                if (sum < index) {
                    isOk = false;
                    break;
                } else
                    sum += a[(int) value];
            }
            if (!isOk)
                pw.println("No");
            else
                pw.println("Yes");
        }
        pw.close();
        br.close();
    }

    private static class Pair {
        long first;
        long second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

}
