import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] s = new String[n];
        Map<Character, Long> weiMap = new HashMap<>();
        Map<Character, Boolean> zero = new HashMap<>();
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            s[ez] = st.nextToken();
            for (int vn = 0; vn < s[ez].length(); vn++)
                weiMap.put(s[ez].charAt(vn), weiMap.getOrDefault(s[ez].charAt(vn), 0L) + (long) Math.pow(10, s[ez].length() - vn - 1));
            zero.put(s[ez].charAt(0), true);
        }
        List<Map.Entry<Character, Long>> list = new ArrayList<>();
        for (char c = 'a'; c <= 'j'; c++) {
            if (weiMap.containsKey(c))
                list.add(new AbstractMap.SimpleEntry<>(c, weiMap.get(c)));
        }
        list.sort((x, y) -> Long.compare(y.getValue(), x.getValue()));
        Map<Character, Integer> repMap = new HashMap<>();
        boolean isOk = true;
        int num = 1;
        for (Map.Entry<Character, Long> entry : list) {
            char ch = entry.getKey();
            if (!zero.containsKey(ch) && isOk) {
                repMap.put(ch, 0);
                isOk = false;
                continue;
            }
            repMap.put(ch, num++);
        }
        long sum = 0;
        for (String str : s) {
            StringBuilder replaced = new StringBuilder();
            for (char ch : str.toCharArray())
                replaced.append(repMap.get(ch));
            sum += Long.parseLong(replaced.toString());
        }
        pw.println(sum);
        pw.close();
        br.close();
    }

}
