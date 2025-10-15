import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int[] nums = {1, 5, 13, 25, 41, 61, 85, 100};
        int[] res = {1, 3, 5, 7, 9, 11, 13, 15};
        if (3 == x)
            pw.println(5);
        else {
            for (int ez = 0; ez < nums.length; ez++) {
                if (nums[ez] >= x) {
                    pw.println(res[ez]);
                    break;
                }
            }
        }
        pw.close();
    }

}
