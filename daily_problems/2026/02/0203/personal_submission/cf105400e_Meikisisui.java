import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int[] nums = new int[n];
            int maxV = 0, minV = 11;
            for (int ez = 0; ez < n; ez++) {
                nums[ez] = Integer.parseInt(st.nextToken());
                maxV = Math.max(maxV, nums[ez]);
                minV = Math.min(minV, nums[ez]);
            }
            if (maxV == minV)
                pw.println((long) Math.pow(10, n));
            else {
                long res = 1;
                for (int ez = 0; ez < n; ez++) {
                    if (maxV == nums[ez])
                        res *= 11 - nums[ez];
                    else if (minV == nums[ez])
                        res *= nums[ez];
                }
                pw.println(res);
            }
        }
        pw.close();
    }

}
