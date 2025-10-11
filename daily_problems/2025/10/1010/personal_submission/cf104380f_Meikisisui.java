import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int left = Integer.parseInt(st.nextToken());
        int right = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int unReach = Math.min(left - 1, n - right);
        int reach = n - unReach, times = right - left + 1;
        long[] arr = new long[reach];
        for (int ez = 0; ez < reach; ez++)
            arr[ez] = Long.parseLong(st.nextToken());
        Arrays.sort(arr);
        long res = 0;
        while (times-- > 0)
            res += arr[--reach];
        pw.println(res);
        pw.close();
    }

}
