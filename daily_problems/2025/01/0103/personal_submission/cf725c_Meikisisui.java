import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String s = st.nextToken();
        boolean[] letters = new boolean[26];
        int n = 0;
        String repeat = "";
        int second = 0;
        for (int i = 0; i < s.length(); i++) {
            n = s.charAt(i);
            if (letters[n - 65]) {
                repeat = String.valueOf((char) (n));
                second = i;
                break;
            } else
                letters[n - 65] = true;
        }
        int first = s.indexOf(repeat);
        if ((first > 0 && s.charAt(first - 1) == n) || s.charAt(first + 1) == n
                || s.charAt(second - 1) == n || (second < s.length() - 1 && s.charAt(second + 1) == n)) {
            pw.println("Impossible");
        } else {
            String one = s.substring(0, (first + second + 1) / 2);
            String str = s.substring((first + second + 1) / 2, second)
                    + s.substring(second + 1);
            String two = "";
            for (int ez = str.length() - 1; ez >= 0; ez--)
                two += str.charAt(ez);
            while (one.length() != two.length()) {
                if (two.length() > one.length()) {
                    one = two.charAt(0) + one;
                    two = two.substring(1);
                } else {
                    two = one.charAt(0) + two;
                    one = one.substring(1);
                }
            }
            pw.println(one);
            pw.println(two);
        }
        pw.close();
        f.close();
    }

}
