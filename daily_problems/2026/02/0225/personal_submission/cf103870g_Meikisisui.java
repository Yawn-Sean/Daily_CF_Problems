import java.io.*;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("dotak.in")));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            long A = Long.parseLong(st.nextToken());
            long B = Long.parseLong(st.nextToken());
            long M = Long.parseLong(st.nextToken());
            long need = M + 1;
            int k = 0;
            while ((1L << k) < need)
                k++;
            long tmp = 1L << (k - 1);
            long target = tmp - 1;
            long res = count(A, B, tmp, target);
            pw.println(res);
        }
        pw.close();
    }

    private static long count(long L, long R, long mod, long target) {
        if (R < target)
            return 0;
        long right = (R - target) / mod;
        long left = (L - 1 >= target) ? ((L - 1 - target) / mod) : -1;
        return right - left;
    }

}
