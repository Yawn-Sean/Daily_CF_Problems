import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String a = st.nextToken();
        st = new StringTokenizer(f.readLine());
        String b = st.nextToken();
        int a1 = count(a);
        int b1 = count(b);
        if (a1 + a1 % 2 >= b1)
            pw.println("YES");
        else
            pw.println("NO");
        pw.close();
        f.close();
    }

    private static int count(String a) {
        int n = a.length(), res = 0;
        for (int ez = 0; ez < n; ez++) {
            if (a.charAt(ez) == '1')
                res++;
        }
        return res;
    }

}
