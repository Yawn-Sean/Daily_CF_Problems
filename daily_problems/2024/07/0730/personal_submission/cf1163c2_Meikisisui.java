import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] points = new int[n][2];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            points[ez][0] = Integer.parseInt(st.nextToken());
            points[ez][1] = Integer.parseInt(st.nextToken());
        }
        long res = transmission(n, points);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long transmission(int n, int[][] points) {
        long res = 0, total = 0;
        Map<Pair<Long, Long>, HashSet<Long>> cntMap = new HashMap<>();
        for (int ez = 0; ez < n - 1; ez++) {
            for (int vn = ez + 1; vn < n; vn++) {
                int x1 = points[ez][0], y1 = points[ez][1],
                        x2 = points[vn][0], y2 = points[vn][1];
                long a = (y2 - y1), b = (x2 - x1);
                long g = gcd(Math.abs(a), Math.abs(b));
                a = a / g;
                b = b / g;
                if (a < 0 || (a == 0 && b < 0)) {
                    a = -a;
                    b = -b;
                }
                long c = a * x1 - b * y1;
                Pair<Long, Long> s = new Pair<>(a, b);
                if (!cntMap.containsKey(s)) {
                    total++;
                    cntMap.put(s, new HashSet<>());
                    cntMap.get(s).add(c);
                    res += total - cntMap.get(s).size();
                } else if (cntMap.containsKey(s) && !cntMap.get(s).contains(c)) {
                    total++;
                    cntMap.get(s).add(c);
                    res += total - cntMap.get(s).size();
                }
            }
        }
        return res;
    }

    private static long gcd(long b, long a) {
        if (b == 0)
            return a;
        else
            return gcd(a % b, b);
    }

}
