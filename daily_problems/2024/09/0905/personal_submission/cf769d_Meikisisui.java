import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int[] a = new int[n];
        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int ez = 0; ez < n; ez++) {
            a[ez] = Integer.parseInt(st.nextToken());
            cntMap.put(a[ez], cntMap.getOrDefault(a[ez], 0) + 1);
        }
        int cnt = cntMap.size();
        int[] quchong = new int[cnt];
        int index = 0;
        long res = 0;
        long res1 = 0;
        for (Map.Entry<Integer, Integer> entry : cntMap.entrySet()) {
            quchong[index++] = entry.getKey();
            int temp = entry.getValue() - 1;
            if (temp > 0)
                res1 += (long) (temp + 1) * temp / 2;
        }
        if (k == 0)
            pw.println(res1);
        else {
            // 暴力水了
            for (int ez = 0; ez < cnt - 1; ez++) {
                for (int vn = ez + 1; vn < cnt; vn++) {
                    int now = quchong[ez] ^ quchong[vn];
                    if (Integer.bitCount(now) == k)
                        res += (long) cntMap.get(quchong[ez]) * cntMap.get(quchong[vn]);
                }
            }
            pw.println(res);
        }
        pw.close();
        f.close();
    }

}
