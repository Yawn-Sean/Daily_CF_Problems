import java.io.*;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] nums = new int[n], pre = new int[n], back = new int[n];
        for (int ez = 0; ez < n; ez++) {
            nums[ez] = Integer.parseInt(st.nextToken());
            if (ez > 0)
                pre[ez] = Math.max(pre[ez - 1], nums[ez]);
            else
                pre[ez] = nums[ez];
        }
        for (int ez = n - 1; ez >= 0; ez--) {
            if (ez == n - 1)
                back[ez] = nums[ez];
            else
                back[ez] = Math.max(back[ez + 1], nums[ez]);
        }
        long res = 0, cnt = 0;
        for (int ez = 1; ez < n - 1; ez++) {
            int now = Math.min(back[ez], pre[ez]) - nums[ez];
            if (now == 0)
                cnt = 0;
            else
                cnt += now;
            res = Math.max(res, cnt);
        }
        pw.println(res);
        pw.close();
    }

}
