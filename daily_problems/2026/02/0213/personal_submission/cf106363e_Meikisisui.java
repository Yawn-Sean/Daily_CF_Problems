import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        int[] pos = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            a[ez] = Integer.parseInt(st.nextToken());
            pos[a[ez]] = ez;
        }
        long[] k1 = new long[n + 1];
        long[] k0 = new long[n + 1];
        int l0 = pos[0], r0 = pos[0];
        for (int ez = 1; ez <= n; ez++) {
            long rightAll = n - r0;
            if (l0 - 1 >= 0) {
                add(k1, 0, l0 - 1, rightAll);
                add(k0, 0, l0 - 1, rightAll);
            }
            long midVal = (long) (l0 + 1) * rightAll;
            add(k0, l0, r0, midVal);
            if (r0 + 1 <= n - 1) {
                long A = -(l0 + 1);
                long B = (long) (l0 + 1) * n;
                add(k1, r0 + 1, n - 1, A);
                add(k0, r0 + 1, n - 1, B);
            }
            if (ez == n)
                break;
            int p = pos[ez];
            l0 = Math.min(l0, p);
            r0 = Math.max(r0, p);
        }
        for (int ez = 1; ez < n; ez++) {
            k1[ez] += k1[ez - 1];
            k0[ez] += k0[ez - 1];
        }
        for (int ez = 0; ez < n; ez++) {
            long res = k1[ez] * ez + k0[ez];
            pw.println(res);
        }
        pw.close();
    }

    private static void add(long[] arr, int left, int right, long ez) {
        if (left > right)
            return;
        arr[left] += ez;
        arr[right + 1] -= ez;
    }

}
