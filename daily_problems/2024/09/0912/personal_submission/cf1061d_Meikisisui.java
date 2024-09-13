import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        long x = Long.parseLong(st.nextToken());
        long y = Long.parseLong(st.nextToken());
        int[][] lessons = new int[n][2];
        long res = 0;
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            lessons[ez][0] = Integer.parseInt(st.nextToken());
            lessons[ez][1] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(lessons, (a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[0];
            return a[0] - b[0];
        });
        TreeMap<Integer, Integer> map = new TreeMap<>();  // 右，次数
        for (int ez = 0; ez < n; ez++) {
            if (map.isEmpty())
                res = (res + y * (lessons[ez][1] - lessons[ez][0]) + x) % MOD;
            else {
                Integer key = map.floorKey(lessons[ez][0] - 1);
                if (null == key || (y * (lessons[ez][0] - key) >= x))
                    res = (res + y * (lessons[ez][1] - lessons[ez][0]) + x) % MOD;
                else {
                    if (map.get(key) == 1)
                        map.remove(key);
                    else
                        map.put(key, map.get(key) - 1);
                    res = (res + y * (lessons[ez][1] - key)) % MOD;
                }
            }
            map.put(lessons[ez][1], map.getOrDefault(lessons[ez][1], 0) + 1);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
