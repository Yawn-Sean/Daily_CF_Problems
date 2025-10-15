import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long b = Long.valueOf(st.nextToken());
        long q = Long.valueOf(st.nextToken());
        long l = Long.valueOf(st.nextToken());
        long m = Long.valueOf(st.nextToken());
        st = new StringTokenizer(f.readLine());
        Set<Long> notExist = new HashSet<>();
        for (int ez = 0; ez < m; ez++) {
            long x = Long.valueOf(st.nextToken());
            notExist.add(x);
        }
        long flag = 0, cnt = 0;
        long tmp = Math.abs(b);
        if (b == 0 || q == 1) {
            // b是0，数列是无限个0，只要0不在m个数中就是inf，否则就是0
            // q是1，数列是无限个b，只要b不在m个数中就是inf，否则就是0。
            if (tmp <= l && !notExist.contains(b))
                flag = 2;
            else
                flag = 1;
        } else if (q == -1) {
            // q是-1数列是无限个b和-b，b和-b出现在m个数中，如果都有就是0，否则就是inf
            if (tmp <= l && (!notExist.contains(b) || !notExist.contains(-b)))
                flag = 2;
            else
                flag = 1;
        } else if (q == 0) {
            // q=0。此时的序列就是b +无限个0。
            if (tmp > l)
                // b的绝对值大于l 或 m个数包含b，就是0
                flag = 1;
            else if (0 <= l && !notExist.contains(0L))
                // l大于等于0且0没出现在m个数中，就是inf
                flag = 2;
            else if (!notExist.contains(b)) {
                // b没在m个数中，就是1，
                flag = 3;
                cnt++;
            } else
                // b在m个数中，就是0
                flag = 3;
        }
        // 没有无限个出现
        // b不断乘q或-q判断有没有出现在m个数中然后累加
        else if (q < 0) {
            flag = 3;
            while (true) {
                if (tmp > l)
                    break;
                if (tmp <= l && !notExist.contains(b))
                    cnt++;
                tmp *= (-q);
                b *= q;
            }
        } else if (q > 0) {
            flag = 3;
            while (true) {
                if (tmp > l)
                    break;
                if (tmp <= l && !notExist.contains(b))
                    cnt++;
                tmp *= q;
                b *= q;
            }
        }
        if (flag == 1)
            pw.println("0");
        else if (flag == 2)
            pw.println("inf");
        else if (flag == 3)
            pw.println(cnt);
        pw.close();
        f.close();
    }

}
