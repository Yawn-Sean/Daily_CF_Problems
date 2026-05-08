import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            boolean[] cnt = new boolean[3];
            for (int i = 0; i < n; i++)
                cnt[s.charAt(i) - 'a'] = true;
            int total = 0;
            for (int i = 0; i < 3; i++) {
                if (cnt[i])
                    total++;
            }
            if (total == 1)
                pw.println("NO");
            else if (n == 3 && total == 3)
                pw.println("NO");
            else
                pw.println("YES");
        }
        pw.close();
    }

}
