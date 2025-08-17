import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Map<Integer, Integer> mp = new HashMap<>();
        Map<Integer, Integer> mps = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            int x = Integer.parseInt(st.nextToken());
            mp.put(x, ez + 1);
            mps.put(ez + 1, x);
        }
        st = new StringTokenizer(br.readLine());
        long res = 0;
        for (int ez = 0; ez < m; ez++) {
            int now = Integer.parseInt(st.nextToken());
            int t = mp.get(now);
            res += (long) Math.ceil((double) t / k);
            if (t == 1)
                continue;
            mp.put(mps.get(t), t - 1);
            mp.put(mps.get(t - 1), t);
            mps.put(t, mps.get(t - 1));
            mps.put(t - 1, now);
        }
        pw.println(res);
        pw.close();
    }

}
