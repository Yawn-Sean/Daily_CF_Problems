import java.util.*;
import java.io.*;

public class Main {
   
    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        List<long[]> list = new ArrayList<>();
        long m = 1;
        for (int i = 0; i < n; i++) {
            long[] tup = new long[4];
            tup[0] = m * k;
            tup[1] = (m + 2) * k;
            tup[2] = (m + 3) * k;
            tup[3] = (m + 4) * k;
            list.add(tup);
            m += 6;
        }
        out.println((m - 2) * k);
        list.forEach(tup -> out.println(tup[0] + " " + tup[1] + " " + tup[2] + " " + tup[3]));   
    }

}
