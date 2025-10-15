import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    private static Map<Character, Character> charMap = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String s1 = st.nextToken();
        st = new StringTokenizer(br.readLine());
        String s2 = st.nextToken();
        char[] a = s1.toCharArray(), b = s2.toCharArray();
        int cnt = 0;
        for (char ez = 'a'; ez <= 'z'; ez++)
            charMap.put(ez, ez);
        char[][] res = new char[n][2];
        for (int ez = 0; ez < n; ez++) {
            if (merge(a[ez], b[ez])) {
                res[cnt][0] = b[ez];
                res[cnt][1] = a[ez];
                cnt++;
            }
        }
        pw.println(cnt);
        for (int ez = 0; ez < cnt; ez++)
            pw.println(res[ez][1] + " " + res[ez][0]);
        pw.close();
        br.close();
    }

    private static char find(char x) {
        if (charMap.get(x) != x)
            charMap.put(x, find(charMap.get(x)));
        return charMap.get(x);
    }

    private static boolean merge(char x, char y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            charMap.put(x, y);
            return true;
        }
        return false;
    }

}
