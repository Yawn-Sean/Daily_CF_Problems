import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
//        StringTokenizer st = new StringTokenizer(f.readLine());
        char[] str = f.readLine().toCharArray();
        int len = str.length;
        int ans = 0;
        int[] nums = new int[100];
        // 数的个数，等号位置，正数个数
        int cnt = 1, pos = 0, posNow = 1;
        // 第一个数是正数，并初始化所有正数默认是1，负数默认是-1
        nums[0] = 1;
        for (int ez = 0; ez < len; ez++) {
            if (str[ez] == '+') {
                nums[cnt++] = 1;
                posNow++;
            }
            if (str[ez] == '-') {
                nums[cnt++] = -1;
                posNow--;
            }
            if (str[ez] == '=') {
                pos = ez;
                break;
            }
        }
        for (int ez = pos + 1; ez < len; ez++) {
            if (Character.isDigit(str[ez]))
                ans = ans * 10 + (str[ez] - '0');
        }
        for (int ez = 0; ez < cnt; ez++) {
            while (posNow < ans && nums[ez] < ans && nums[ez] > 0) {
                posNow++;
                nums[ez]++;
            }
            while (posNow > ans && nums[ez] > -ans && nums[ez] < 0) {
                posNow--;
                nums[ez]--;
            }
        }
        if (posNow != ans)
            pw.println("Impossible");
        else {
            pw.println("Possible");
            int vn = 0;
            for (int ez = 0; ez < len; ez++) {
                if (str[ez] != '?')
                    pw.print(str[ez]);
                else
                    pw.print(Math.abs(nums[vn++]));
            }
        }
        pw.close();
        f.close();
    }

}
