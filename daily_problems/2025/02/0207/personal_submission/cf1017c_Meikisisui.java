import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = (int) Math.sqrt(n);
        int nodeLen = n % k == 0 ? n / k : n / k + 1;
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i <= k; i++) {
            if (i != k) {
                for (int j = n - i * nodeLen + 1; j <= n - i * nodeLen + nodeLen; j++)
                    res.add(j);
            } else {
                int cnt = 1;
                while (res.size() < n)
                    res.add(cnt++);
            }
        }
        for (int i = 0; i < res.size(); i++) {
            pw.print(res.get(i));
            if (i != res.size() - 1)
                pw.print(" ");
        }
        pw.close();
        f.close();
    }

}
