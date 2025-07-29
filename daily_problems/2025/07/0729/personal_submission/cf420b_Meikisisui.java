import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] id = new int[m + 1];
        int[] ans = new int[n + 1];
        char[] op = new char[m + 1];
        Arrays.fill(ans, 1);
        int s = 0, t = 0;
        for (int ez = 1; ez <= m; ez++) {
            String line = br.readLine();
            op[ez] = line.charAt(0);
            id[ez] = Integer.parseInt(line.substring(1).trim());
            if (op[ez] == '-' && ans[id[ez]] == 1)
                t = id[ez];
            if (op[ez] == '+' && s == 0)
                s = id[ez];
            ans[id[ez]] = 0;
        }
        Set<Integer> set = new HashSet<>();
        int leader = (t != 0) ? t : s;
        set.add(leader);
        ans[leader] = 1;
        for (int ez = 1; ez <= m; ez++) {
            if (op[ez] == '+') {
                set.add(id[ez]);
                if (!set.contains(leader))
                    ans[leader] = 0;
            } else {
                set.remove(id[ez]);
                if (!set.isEmpty() && !set.contains(leader))
                    ans[leader] = 0;
            }
        }
        int res = 0;
        for (int ez = 1; ez <= n; ez++)
            res += ans[ez];
        pw.println(res);
        for (int ez = 1; ez <= n; ez++) {
            if (ans[ez] == 1)
                pw.print(ez + " ");
        }
        pw.close();
    }

}
