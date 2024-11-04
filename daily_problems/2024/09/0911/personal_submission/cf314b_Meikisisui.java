import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int b = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String a = st.nextToken();
        st = new StringTokenizer(f.readLine());
        String c = st.nextToken();
        int lenA = a.length();
        int lenC = c.length();
        int index = 0;
        // 以c的第i位置找，经过一个a后过去了几个c
        int[] cnt = new int[lenC];
        // 此时下一次匹配的位置
        int[] next = new int[lenC];
        for (int ez = 0; ez < lenC; ez++) {
            index = ez;
            for (int j = 0; j < lenA; j++) {
                if (a.charAt(j) == c.charAt(index)) {
                    index++;
                    if (index == lenC) {
                        cnt[ez]++;
                        index = 0;
                    }
                }
            }
            next[ez] = index;
        }
        index = 0;
        int res = 0;
        for (int ez = 1; ez <= b; ez++) {
            res += cnt[index];
            index = next[index];
        }
        pw.println(res / d);
        pw.close();
        f.close();
    }

}
