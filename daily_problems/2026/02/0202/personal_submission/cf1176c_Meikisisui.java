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
        Map<Integer, Integer> pair = new HashMap<>();
        // 4,8,15,16,23,42
        pair.put(4, 0);
        pair.put(8, 1);
        pair.put(15, 2);
        pair.put(16, 3);
        pair.put(23, 4);
        pair.put(42, 5);
        int[] res = new int[6];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            int now = Integer.parseInt(st.nextToken());
            if (0 == pair.get(now))
                res[0]++;
            else {
                int tmp = pair.get(now);
                if (res[tmp - 1] > 0) {
                    res[tmp]++;
                    res[tmp - 1]--;
                }
            }
        }
        pw.println(n - res[5] * 6);
        pw.close();
    }

}
