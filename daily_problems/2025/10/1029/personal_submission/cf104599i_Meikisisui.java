import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] nums = new int[n];
        int[] parent = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez < n; ez++)
            parent[ez] = Integer.parseInt(st.nextToken()) - 1;
        int res = 0;
        int[] dp1 = new int[n], dp2 = new int[n];
        for (int ez = n - 1; ez >= 0; ez--) {
            res = Math.max(res, dp1[ez] + dp2[ez]);
            res = Math.max(res, nums[ez] + dp1[ez]);
            if (ez > 0) {
                int tempMax = Math.max(nums[ez], dp1[ez]) + 1;
                int p = parent[ez];
                if (tempMax > dp1[p]) {
                    int temp = dp1[p];
                    dp1[p] = tempMax;
                    dp2[p] = Math.max(dp2[p], temp);
                } else if (tempMax > dp2[p])
                    dp2[p] = tempMax;
            }
        }
        pw.println(res);
        pw.close();
    }

}
