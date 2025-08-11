import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] back = new int[n + 1], pos = new int[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            int now = Integer.parseInt(st.nextToken());
            back[ez] = n;
            pos[now] = ez;
        }
        for (int ez = 1; ez <= m; ez++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int left = Math.min(pos[x], pos[y]);
            int right = Math.max(pos[x], pos[y]);
            back[left] = Math.min(back[left], right - 1);
        }
        for (int ez = n - 1; ez >= 1; ez--)
            back[ez] = Math.min(back[ez], back[ez + 1]);
        long res = 0;
        for (int ez = 1; ez <= n; ez++)
            res += (long) back[ez] - ez + 1;
        pw.print(res);
        pw.close();
    }

}
