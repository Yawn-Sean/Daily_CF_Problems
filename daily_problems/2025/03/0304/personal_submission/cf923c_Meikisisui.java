import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static final int maxN = 300001;
    private static int total = 1;
    private static long[] val = new long[maxN * 32];
    private static int[][] ch = new int[maxN * 32][2];
    private static long[] cnt = new long[maxN * 32];
    private static long[] a = new long[maxN];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++) {
            long s = Long.parseLong(st.nextToken());
            insert(s);
        }
        for (int ez = 1; ez <= n; ez++) {
            long res = query(a[ez]);
            pw.print((a[ez] ^ res) + " ");
        }
        pw.close();
        br.close();
    }

    private static void insert(long x) {
        int u = 0;
        for (int ez = 31; ez >= 0; ez--) {
            int v = (int) ((x >> ez) & 1);
            if (ch[u][v] == 0) {
                ch[total][0] = ch[total][1] = 0;
                ch[u][v] = total++;
            }
            u = ch[u][v];
            cnt[u]++;
        }
        val[u] = x;
    }

    private static long query(long x) {
        int u = 0;
        for (int ez = 31; ez >= 0; ez--) {
            int v = (int) ((x >> ez) & 1);
            if (ch[u][v] != 0 && cnt[ch[u][v]] > 0)
                u = ch[u][v];
            else
                u = ch[u][v ^ 1];
            cnt[u]--;
        }
        return val[u];
    }

}
