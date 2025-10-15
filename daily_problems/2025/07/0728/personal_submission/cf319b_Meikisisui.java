import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int ez = 0; ez < n; ez++)
            arr[ez] = Integer.parseInt(st.nextToken());
        int res = 0;
        Deque<int[]> stack = new ArrayDeque<>();
        for (int now : arr) {
            int max = 0;
            while (!stack.isEmpty() && stack.peek()[0] <= now)
                max = Math.max(max, stack.pop()[1]);
            max = stack.isEmpty() ? 0 : max + 1;
            res = Math.max(res, max);
            stack.push(new int[]{now, max});
        }
        pw.println(res);
        pw.close();
    }
}
