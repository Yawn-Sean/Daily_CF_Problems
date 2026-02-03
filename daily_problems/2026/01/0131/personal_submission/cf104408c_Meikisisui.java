import java.io.*;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            int[][] nums = new int[n][m];
            for (int ez = 0; ez < n; ez++) {
                st = new StringTokenizer(br.readLine());
                String s = st.nextToken();
                for (int vn = 0; vn < m; vn++)
                    nums[ez][vn] = s.charAt(vn) - '0';
            }
            int[] res = new int[m];
            for (int ez = 0; ez < n; ez++) {
                if (nums[ez][m - 1] == 0)
                    res[m - 1]++;
                for (int vn = m - 2; vn >= 0; vn--) {
                    if (nums[ez][vn] != nums[ez][vn + 1])
                        res[vn]++;
                }
            }
            long ans = 0;
            for (int ez = 0; ez < m; ez++)
                ans += Math.min(res[ez], n - res[ez]);
            pw.println(ans);
        }
        pw.close();
    }

}
