import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int v[] = new int[n];
        int d[] = new int[n];
        int p[] = new int[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            v[ez] = Integer.parseInt(st.nextToken());
            d[ez] = Integer.parseInt(st.nextToken());
            p[ez] = Integer.parseInt(st.nextToken());
        }
        StringBuilder sb = new StringBuilder();
        int res = 0;
        for (int ez = 0; ez < n; ez++) {
            while (ez < n && p[ez] < 0)
                ++ez;
            if (ez == n)
                break;
            ++res;
            sb.append((ez + 1) + " ");
            Queue<Integer> q = new LinkedList<>();
            for (int vn = ez + 1; vn < n && v[ez] > 0; vn++) {
                if (p[vn] < 0)
                    continue;
                p[vn] -= v[ez];
                v[ez]--;
                if (p[vn] < 0)
                    q.add(vn);
            }
            while (!q.isEmpty()) {
                int node = q.remove();
                for (int vn = node + 1; vn < n; vn++) {
                    if (p[vn] < 0)
                        continue;
                    p[vn] -= d[node];
                    if (p[vn] < 0)
                        q.add(vn);
                }
            }
        }
        pw.println(res);
        pw.print(sb);
        pw.close();
    }

}
