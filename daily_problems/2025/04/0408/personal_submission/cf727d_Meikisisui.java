import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static final String[] zuhe = {"S", "M", "L", "XL", "XXL", "XXXL", "S,M", "M,L", "L,XL", "XL,XXL", "XXL,XXXL"};
    private static int[] tmp = new int[6];
    private static int[] res;
    private static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < 6; ez++)
            tmp[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        res = new int[n];
        int[] visited = new int[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            visited[ez] = find(s);
        }
        // 只选一种的
        for (int ez = 0; ez < n; ez++) {
            if (visited[ez] <= 5) {
                if (tmp[visited[ez]] > 0) {
                    tmp[visited[ez]]--;
                    res[ez] = visited[ez];
                } else {
                    pw.println("NO");
                    pw.close();
                    br.close();
                    return;
                }
            }
        }
        // 选两种小到大匹配
        for (int ez = 6; ez < 11; ez++) {
            int pos = zuhe[ez].indexOf(',');
            int p1 = find(zuhe[ez].substring(0, pos));
            int p2 = find(zuhe[ez].substring(pos + 1));
            for (int vn = 0; vn < n; vn++) {
                if (visited[vn] == ez) {
                    if (tmp[p1] > 0) {
                        tmp[p1]--;
                        res[vn] = p1;
                    } else if (tmp[p2] > 0) {
                        tmp[p2]--;
                        res[vn] = p2;
                    } else {
                        pw.println("NO");
                        pw.close();
                        br.close();
                        return;
                    }
                }
            }
        }
        pw.println("YES");
        for (int ez = 0; ez < n; ez++)
            pw.println(zuhe[res[ez]]);
        pw.close();
        br.close();
    }

    private static int find(String str) {
        for (int ez = 0; ez < zuhe.length; ez++) {
            if (zuhe[ez].equals(str))
                return ez;
        }
        return -1;
    }

}
