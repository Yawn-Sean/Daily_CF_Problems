import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> p = new HashMap<>();
        for (int ez = 0; ez < n; ez++) {
            a[ez] = Integer.parseInt(st.nextToken());
            p.put(a[ez], p.getOrDefault(ez, 0) + 1);
        }
        Arrays.sort(a);
        long temp = k;
        int t = (k % n == 0) ? (int) (k / n - 1) : (int) (k / n);
        pw.print(a[t]);
        int num = 1;
        int index = t;
        for (int ez = t - 1; ez >= 0; ez--) {
            if (a[ez] == a[ez + 1])
                index = ez;
            else
                break;
        }
        k -= ((long) index * n);
        for (int ez = index + 1; ez < n; ez++) {
            if (a[ez] == a[ez - 1])
                num++;
            else
                break;
        }
        if (num == 1)
            pw.println(" " + a[(int) ((temp - 1 + n) % n)]);
        else
            pw.println(" " + a[k % num == 0 ? (int) (k / num - 1) : (int) (k / num)]);
        pw.close();
    }

}
