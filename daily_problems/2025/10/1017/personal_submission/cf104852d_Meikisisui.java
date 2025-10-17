import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    private static Set<Long> fun = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        for (int ez = 1; ez < 10; ez++) {
            for (int vn = 0; vn < 10; vn++)
                dfs(ez, vn, ez);
        }
        fun.add(0L);
        int res = 0;
        for (long ez : fun) {
            if (fun.contains(n - ez))
                res++;
        }
        pw.println((res + 1) / 2);
        pw.close();
    }

    public static void dfs(int ez, int vn, long now) {
        if (now > 1000000000)
            return;
        fun.add(now);
        dfs(ez, vn, 10 * now + ez);
        dfs(ez, vn, 10 * now + vn);
    }

}
