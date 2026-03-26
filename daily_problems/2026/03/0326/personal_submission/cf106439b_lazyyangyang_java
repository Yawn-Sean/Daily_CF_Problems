import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
//打表
        StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(System.out);
        int[] saved = {1, 3, 5, 2, 4};
        st.nextToken();
        int t = (int) st.nval;
        while (t-- > 0) {
            st.nextToken();
            int n = (int) st.nval;
            if (n == 2 || n == 3) {
                pw.println(-1);
                continue;
            }
            List<Integer> ans = new ArrayList<>();
            int groups = n / 5;
            for (int x = 0; x < groups; x++) {
                for (int i = 0; i < 5; i++) {
                    ans.add(x * 5 + saved[i]);
                }
            }
            int rem = n % 5;
            if (rem == 1) {
                ans.add(n);
            } else if (rem == 2) {
                ans.set(ans.size() - 1, n);
                ans.add(n - 3);
                ans.add(n - 1);
            } else if (rem == 3) {
                ans.set(ans.size() - 1, n - 1);
                ans.add(n - 4);
                ans.add(n - 2);
                ans.add(n);
            } else if (rem == 4) {
                ans.add(n - 2);
                ans.add(n);
                ans.add(n - 3);
                ans.add(n - 1);
            }
            for (int i = 0; i < ans.size(); i++) {
                pw.print(ans.get(i));
                if (i < ans.size() - 1) pw.print(" ");
            }
            pw.println();
        }
        pw.flush();
        pw.close();
    }
}
