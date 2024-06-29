import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Test3 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(f.readLine());
        String str = f.readLine();
        int res = removeAdjacent(n, str);
        pw.println(res);
        pw.close();
    }

    private static int removeAdjacent(int n, String str) {
        int res = 0;
        for (char ch = 'z'; ch > 'a'; ch--) {
            for (int i = 0; i < str.length(); i++) {
                if (str.length() == 1)
                    break;
                if (str.charAt(i) != ch)
                    continue;
                if (i == 0) {
                    if (str.charAt(i + 1) == ch - 1) {
                        str = str.substring(i + 1);
                        i--;
                        res++;
                    }
                } else if (i == str.length() - 1) {
                    if (str.charAt(i - 1) == ch - 1) {
                        str = str.substring(0, i);
                        res++;
                    }
                } else {
                    if (str.charAt(i + 1) == ch - 1 || str.charAt(i - 1) == ch - 1) {
                        str = str.substring(0, i) + str.substring(i + 1);
                        i -= 2;
                        res++;
                    }
                }
            }
        }
        return res;
    }

}
