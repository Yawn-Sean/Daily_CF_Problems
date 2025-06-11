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
        String a = st.nextToken();
        st = new StringTokenizer(f.readLine());
        String b = st.nextToken();
        st = new StringTokenizer(f.readLine());
        String c = st.nextToken();
        Map<Character, Long> map1 = new HashMap<>();
        Map<Character, Long> map2 = new HashMap<>();
        Map<Character, Long> map3 = new HashMap<>();
        for (int ez = 0; ez < a.length(); ez++) {
            char ch = a.charAt(ez);
            map1.put(ch, map1.getOrDefault(ch, 0L) + 1);
        }
        for (int ez = 0; ez < b.length(); ez++) {
            char ch = b.charAt(ez);
            map2.put(ch, map2.getOrDefault(ch, 0L) + 1);
        }
        for (int ez = 0; ez < c.length(); ez++) {
            char ch = c.charAt(ez);
            map3.put(ch, map3.getOrDefault(ch, 0L) + 1);
        }

        long ans = Integer.MAX_VALUE;
        // a中最多的b次数
        for (Map.Entry<Character, Long> entry : map2.entrySet()) {
            char key = entry.getKey();
            long value = entry.getValue();
            ans = Math.min(ans, map1.getOrDefault(key, 0L) / value);
        }
        // b次数，c次数，总次数
        long sum1 = 0, sum2 = 0, total = 0;
        for (long ez = 0; ez <= ans; ez++) {
            Map<Character, Long> mapNow = new HashMap<>(map1);
            long res = Integer.MAX_VALUE;
            for (Map.Entry<Character, Long> entry : map2.entrySet()) {
                char key = entry.getKey();
                long value = entry.getValue();
                mapNow.put(key, mapNow.getOrDefault(key, 0L) - ez * value);
            }
            for (Map.Entry<Character, Long> entry : map3.entrySet()) {
                char key = entry.getKey();
                long value = entry.getValue();
                res = Math.min(res, mapNow.getOrDefault(key, 0L) / value);
            }
//            System.out.println(ez);
//            System.out.println(res);
//            System.out.println(total);
            if (res + ez > total) {
                sum1 = ez;
                sum2 = res;
                total = res + ez;
            }
        }
        for (long ez = 1; ez <= sum1; ez++)
            pw.print(b);
        for (long ez = 1; ez <= sum2; ez++)
            pw.print(c);
        for (Map.Entry<Character, Long> entry : map2.entrySet()) {
            char key = entry.getKey();
            map1.put(key, map1.getOrDefault(key, 0L) - sum1 * entry.getValue());
        }
        for (Map.Entry<Character, Long> entry : map3.entrySet()) {
            char key = entry.getKey();
            map1.put(key, map1.getOrDefault(key, 0L) - sum2 * entry.getValue());
        }
        for (Map.Entry<Character, Long> entry : map1.entrySet()) {
            char key = entry.getKey();
            long value = entry.getValue();
            for (long ez = 1; ez <= value; ez++)
                pw.print(key);
        }
        pw.close();
        f.close();
    }

}
