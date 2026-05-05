import java.io.*;
import java.util.HashMap;
import java.util.Map;
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
            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++)
                arr[i] = Integer.parseInt(st.nextToken());
            int[][] pre = new int[n][4];
            updateTop2(arr, pre, true, n);
            int[][] back = new int[n][4];
            updateTop2(arr, back, false, n);
            int res = 0;
            for (int i = 0; i < n - 1; i++) {
                int p1 = pre[i][0], c1 = pre[i][1], c2 = pre[i][3];
                int s1 = back[i + 1][0], sc1 = back[i + 1][1], sc2 = back[i + 1][3];
                if (p1 != s1)
                    res = Math.max(res, c1 + sc1);
                else {
                    if (c2 > 0)
                        res = Math.max(res, c2 + sc1);
                    if (sc2 > 0)
                        res = Math.max(res, c1 + sc2);
                }
            }
            pw.println(res);
        }
        pw.close();
    }

    private static void updateTop2(int[] arr, int[][] ans, boolean forward, int n) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int v1 = -1, c1 = 0, v2 = -1, c2 = 0;
        int start = forward ? 0 : n - 1;
        int end = forward ? n : -1;
        int step = forward ? 1 : -1;
        for (int i = start; i != end; i += step) {
            int now = arr[i];
            int f = cntMap.getOrDefault(now, 0) + 1;
            cntMap.put(now, f);
            if (now == v1) {
                c1 = f;
            } else if (f > c1) {
                v2 = v1;
                c2 = c1;
                v1 = now;
                c1 = f;
            } else if (now == v2) {
                c2 = f;
            } else if (f > c2) {
                v2 = now;
                c2 = f;
            }
            ans[i] = new int[]{v1, c1, v2, c2};
        }
    }
}
