import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int s = 1000000;
        boolean[] b = new boolean[s + 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
            b[arr[ez]] = true;
        }
        List<Integer> res = new ArrayList<>();
        int cnt = 0;
        for (int ez = 0; ez < n; ez++) {
            int required = s - arr[ez] + 1;
            if (!b[required]) {
                res.add(required);
                b[required] = true;
            } else
                cnt++;
        }
        for (int ez = 1; ez <= s && cnt > 0; ez++) {
            // 题目保证有解，找一对儿对称数字放入答案
            if (!b[ez] && !b[s - ez + 1]) {
                res.add(ez);
                res.add(s - ez + 1);
                b[ez] = true;
                b[s - ez + 1] = true;
                cnt -= 2;
            }
        }
        pw.println(res.size());
        for (int ez = 0; ez < res.size(); ez++)
            pw.print(res.get(ez) + " ");
        pw.close();
        br.close();
    }

}
