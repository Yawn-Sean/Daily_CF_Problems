import java.util.*;
import java.io.*;

public class cf700b {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        int[] flg = new int[n];
        String[] nik = br.readLine().split(" ");
        for (int i = 0; i < k * 2; i++) {
            int x = Integer.parseInt(nik[i]);
            flg[x - 1] = 1;
        }

        List<List<Integer>> path = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            path.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            String[] uv = br.readLine().split(" ");
            int u = Integer.parseInt(uv[0]) - 1;
            int v = Integer.parseInt(uv[1]) - 1;
            path.get(u).add(v);
            path.get(v).add(u);
        }

        long[] ans = {0};
        dfs(0, -1, path, flg, k, ans);
        bw.write(Long.toString(ans[0]));
        bw.flush();
        bw.close();
        br.close();
    }

    private static int dfs(int u, int p, List<List<Integer>> path, int[] flg, int k, long[] ans) {
        int cnt = flg[u];
        for (int v : path.get(u)) {
            if (v != p) {
                cnt += dfs(v, u, path, flg, k, ans);
            }
        }
        ans[0] += Math.min(cnt, 2 * k - cnt);
        return cnt;
    }
}
