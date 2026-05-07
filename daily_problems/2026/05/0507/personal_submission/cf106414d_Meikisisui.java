import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            int mx = -1;
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                mx = Math.max(mx, arr[i]);
            }
            boolean[] mex = new boolean[mx + 2];
            for (int i = 0; i < n; i++) {
                if (i + 1 != k)
                    mex[arr[i]] = true;
            }
            int max = -1;
            for (int i = 0; i < mx + 2; i++) {
                if (!mex[i]) {
                    max = i;
                    break;
                }
            }
            if (max > arr[k - 1])
                pw.println(k + " " + n);
            else
                pw.println("-1 -1");
        }
        pw.close();
    }

}
