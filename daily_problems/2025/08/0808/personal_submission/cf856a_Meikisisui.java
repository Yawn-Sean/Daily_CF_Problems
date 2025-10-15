import java.io.*;
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
            int[] a = new int[n + 1];
            boolean[] visited = new boolean[2000001];
            int[] res = new int[n + 1];
            int cnt = 0;
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++)
                a[ez] = Integer.parseInt(st.nextToken());
            for (int x = 1; x <= 1000000 && cnt < n; x++) {
                if (visited[x])
                    continue;
                res[++cnt] = x;
                for (int ez = 1; ez < n; ez++) {
                    for (int vn = ez + 1; vn <= n; vn++)
                        visited[Math.abs(a[vn] - a[ez]) + x] = true;
                }
            }
            if (cnt < n)
                pw.println("NO");
            else {
                pw.println("YES");
                for (int ez = 1; ez <= n; ez++)
                    pw.print(res[ez] + " ");
                pw.println();
            }
        }
        pw.close();
    }

}
