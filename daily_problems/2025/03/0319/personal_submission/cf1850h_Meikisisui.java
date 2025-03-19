import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int[] con = new int[200001];
    private static long[] pos = new long[200001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            boolean isOk = true;
            for (int ez = 1; ez <= n; ez++) {
                con[ez] = ez;
                pos[ez] = 0;
            }
            for (int ez = 0; ez < m; ez++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                long d = Long.parseLong(st.nextToken());
                if (!isOk)
                    continue;
                int fa = find(a);
                int fb = find(b);
                if (fa != fb) {
                    con[fa] = fb;
                    pos[fa] = d + pos[b] - pos[a];
                } else {
                    if (pos[a] - pos[b] != d)
                        isOk = false;
                }
            }
            if (isOk)
                pw.println("YES");
            else
                pw.println("NO");
        }
        pw.close();
        br.close();
    }

    private static int find(int x) {
        if (x != con[x]) {
            int t = con[x];
            con[x] = find(con[x]);
            pos[x] += pos[t];
        }
        return con[x];
    }

}
