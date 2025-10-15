import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            int[] arr = new int[n];
            int[] cnt = new int[m + 1];
            st = new StringTokenizer(br.readLine());
            for (int ez = 0; ez < n; ez++) {
                arr[ez] = Integer.parseInt(st.nextToken());
                cnt[arr[ez]] ^= 1;
            }
            int[] cntMin = new int[m + 1];
            Arrays.fill(cntMin, Integer.MAX_VALUE / 10);
            for (int ez = 0; ez <= m; ez++) {
                if (cnt[ez] != 0)
                    cntMin[ez] = 0;
            }
            for (int ez = m; ez > 0; ez--)
                cntMin[ez - 1] = Math.min(cntMin[ez - 1], cntMin[ez] + 1);
            cntMin[m] = Math.min(cntMin[m], cntMin[0]);
            for (int ez = m; ez > 0; ez--)
                cntMin[ez - 1] = Math.min(cntMin[ez - 1], cntMin[ez] + 1);
            int times = 0;
            while (q-- > 0) {
                st = new StringTokenizer(br.readLine());
                int type = Integer.parseInt(st.nextToken());
                if (type == 1)
                    times++;
                else {
                    int index = Integer.parseInt(st.nextToken());
                    int tmp = arr[index - 1];
                    int offset = Math.min(times, cntMin[tmp]);
                    pw.println((tmp + offset - 1) % m + 1);
                }
            }
        }
        pw.close();
    }

}
