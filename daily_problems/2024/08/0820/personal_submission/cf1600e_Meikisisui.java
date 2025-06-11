import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] nums = new int[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ++ez)
            nums[ez] = Integer.parseInt(st.nextToken());
        int left = 0;
        while (left < n - 1 && nums[left + 1] > nums[left])
            left++;
        int right = n - 1;
        while (right > 0 && nums[right - 1] > nums[right])
            right--;
        if (left % 2 == 0 || (n - 1 - right) % 2 == 0)
            pw.print("Alice");
        else
            pw.print("Bob");
        pw.close();
        f.close();
    }

}
