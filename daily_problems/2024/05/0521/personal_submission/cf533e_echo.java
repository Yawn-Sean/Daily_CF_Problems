import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s1 = br.readLine(), s2 = br.readLine();
        System.out.println(getAns(n, s1, s2));
    }

    private static int getAns(int n, String s1, String s2) {
        char[] cs1 = s1.toCharArray(), cs2 = s2.toCharArray();
        int idx1 = 0, idx2 = n - 1;
        while (idx1 < n) {
            if (cs1[idx1] == cs2[idx1]) {
                idx1++;
            } else {
                break;
            }
        }
        while (idx2 >= 0) {
            if (cs1[idx2] == cs2[idx2]) {
                idx2--;
            } else {
                break;
            }
        }

        if (idx2 - idx1 <= 0) return 2;
        String sub1 = s1.substring(idx1, idx2), sub2 = s2.substring(idx1 + 1, idx2 + 1);
        String sub3 = s2.substring(idx1, idx2), sub4 = s1.substring(idx1 + 1, idx2 + 1);
        if (sub1.equals(sub2) && sub3.equals(sub4)) {
            return 2;
        } else if (sub1.equals(sub2) || sub3.equals(sub4)) {
            return 1;
        }
        return 0;
    }

}
