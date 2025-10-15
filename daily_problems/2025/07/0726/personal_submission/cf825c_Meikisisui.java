import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int ez = 0; ez < n; ez++)
            arr[ez] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int res = 0;
        for (int ez = 0; ez < n; ez++) {
            if (arr[ez] > k && arr[ez] <= k * 2)
                k = arr[ez];
            while (k * 2 < arr[ez]) {
                res++;
                k *= 2;
            }
            k = Math.max(k, arr[ez]);
        }
        pw.println(res);
        pw.close();
    }

}
