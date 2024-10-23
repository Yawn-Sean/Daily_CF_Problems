import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        boolean maxTimes = false;
        int MAXN = 1000001;
        int[] cnta = new int[MAXN];
        int[] cntb = new int[MAXN];
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++) {
            int x = Integer.parseInt(st.nextToken());
            if (x != A) {
                if (!maxTimes || set2.contains(x)) {
                    set1.add(x);
                    cnta[x]++;
                }
            } else {
                maxTimes = true;
                int cnt = 0;
                for (int it : set2) {
                    cnta[it]--;
                    if (cnta[it] == 0)
                        cntb[cnt++] = it;
                }
                for (int vn = 0; vn < cnt; vn++)
                    set2.remove(cntb[vn]);
                set2.addAll(set1);
                set1.clear();
            }
        }
        if (maxTimes) {
            if (set2.isEmpty())
                pw.println("-1");
            else
                pw.println(set2.iterator().next());
        } else
            pw.println(A == 1 ? 2 : A - 1);
        pw.close();
        f.close();
    }

}
