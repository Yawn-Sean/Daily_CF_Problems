import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int v = Integer.parseInt(br.readLine());
        while (v-- != 0) {
            int n = Integer.parseInt(br.readLine());
            char[] cs1 = br.readLine().toCharArray(), cs2 = br.readLine().toCharArray();

            getAns(cs1, cs2);
        }
    }
    private static void getAns(char[] cs1, char[] cs2) {
        int n = cs1.length, ans = Integer.MAX_VALUE;
        int aOverB = 0, bOverA = 0;
        int aEqualB1 = 0, aEqualB0 = 0;
        for (int i = 0; i < n; i++) {
            if (cs1[i] != cs2[i]) {
                if (cs1[i] == '1') aOverB++;
                else bOverA++;
            } else {
                if (cs1[i] == '1') aEqualB1++;
                else aEqualB0++;
            }
        }
        if (aOverB == bOverA) ans = Math.min(ans, aOverB * 2);
        if (aEqualB1 == aEqualB0 + 1) {
            ans = Math.min(ans, aEqualB0 * 2 + 1);
        }
        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }
}
