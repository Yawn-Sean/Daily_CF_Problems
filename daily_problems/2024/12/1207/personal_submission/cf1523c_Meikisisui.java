import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            List<Integer> list = new ArrayList<>();
            for (int ez = 0; ez < n; ez++) {
                st = new StringTokenizer(f.readLine());
                int x = Integer.parseInt(st.nextToken());
                if (x == 1)
                    list.add(x);
                else {
                    while (list.get(list.size() - 1) != x - 1)
                        list.remove(list.size() - 1);
                    list.remove(list.size() - 1);
                    list.add(x);
                }
                StringBuilder sb = new StringBuilder();
                String dian = "";
                for (int now : list) {
                    sb.append(dian).append(now);
                    dian = ".";
                }
                pw.println(sb);
            }
        }
        pw.close();
        f.close();
    }

}
