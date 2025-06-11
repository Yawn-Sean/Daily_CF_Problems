import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] pairs = new int[n + 1][2];
        for (int i = 1; i <= n; i++) {
            String[] s = br.readLine().split(" ");
            pairs[i][0] = Integer.parseInt(s[0]);
            pairs[i][1] = Integer.parseInt(s[1]);
        }

        for (int num : getAns(pairs)) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    private static List<Integer> getAns(int[][] pairs) {
        List<Integer> ans = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        set.add(1);
        ans.add(1);
        while (ans.size() != pairs.length - 1) {
            int[] cur = pairs[ans.get(ans.size() - 1)];
            int n1 = cur[0], n2 = cur[1];
            int[] next1 = pairs[n1], next2 = pairs[n2];
            if ((next1[0] == n2 || next1[1] == n2) && (next2[0] == n1 || next2[1] == n1)) {
                if (!set.contains(n1)) {
                    ans.add(n1);
                } else {
                    ans.add(n2);
                }
            } else if (next1[0] == n2 || next1[1] == n2) {
                ans.add(n1);
            } else {
                ans.add(n2);
            }
        }
        return ans;
    }

}
