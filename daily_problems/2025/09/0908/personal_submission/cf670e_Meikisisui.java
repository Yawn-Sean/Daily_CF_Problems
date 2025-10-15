import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String s1 = st.nextToken();
        st = new StringTokenizer(br.readLine());
        String s2 = st.nextToken();
        int[] pair = new int[n + 1];
        Deque<Integer> stack = new ArrayDeque<>();
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        int[] fix = new int[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            if (ez == 1) {
                left[ez] = -1;
                right[ez] = ez + 1;
            } else if (ez == n) {
                left[ez] = ez - 1;
                right[ez] = -1;
            } else {
                left[ez] = ez - 1;
                right[ez] = ez + 1;
            }
            if (s1.charAt(ez - 1) == '(')
                stack.addLast(ez);
            else {
                int tmp = stack.pollLast();
                pair[tmp] = ez;
                pair[ez] = tmp;
            }
        }
        for (int ez = 0; ez < m; ez++) {
            char now = s2.charAt(ez);
            if (now == 'L')
                p = left[p];
            else if (now == 'R')
                p = right[p];
            else {
                fix[p] = 1;
                int l1 = p;
                int r1 = pair[p];
                if (l1 > r1) {
                    int tmp = l1;
                    l1 = r1;
                    r1 = tmp;
                }
                if (right[r1] == -1)
                    p = left[l1];
                else
                    p = right[r1];
                if (left[l1] != -1)
                    right[left[l1]] = right[r1];
                if (right[r1] != -1)
                    left[right[r1]] = left[l1];
            }
        }
        for (int ez = 1; ez <= n; ez++) {
            if (fix[ez] == 1)
                ez = pair[ez];
            else if (fix[pair[ez]] == 1)
                ez = pair[ez];
            else {
                char ch = s1.charAt(ez - 1);
                pw.print(ch);
            }
        }
        pw.close();
    }

}
