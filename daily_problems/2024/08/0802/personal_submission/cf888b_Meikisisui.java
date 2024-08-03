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
        int k = Integer.parseInt(st.nextToken());
        long res = 1;
        if (k > 1)
            res += combine(n, 2);
        if (k > 2)
            res += 2 * combine(n, 3);
        if (k == 4)
            res += 9 * combine(n, 4);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static Map<String, Long> tempMap = new HashMap<>();

    private static long combine(int n, int k) {
        if (k > n)
            return 0;
        if (k == n || k == 0)
            return 1;
        String temp = n + "," + k;
        if (tempMap.containsKey(temp))
            return tempMap.get(temp);
        long res = combine(n - 1, k) + combine(n - 1, k - 1);
        tempMap.put(temp, res);
        return res;
    }

}
