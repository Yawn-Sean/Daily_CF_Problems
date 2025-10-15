import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        Arrays.fill(arr, 1);
        int sum = 1, max = 1;
        for (int ez = 1; ez < n; ez++) {
            if (b > 0) {
                arr[ez] = sum + 1;
                max = arr[ez];
                sum += arr[ez];
                b--;
            } else if (a > 0) {
                arr[ez] = arr[ez - 1] + 1;
                if (sum < arr[ez])
                    arr[ez] = arr[ez - 1];
                else
                    a--;
                sum += arr[ez];
                max = arr[ez];
            }
        }
        if (a + b > 0)
            pw.print("-1");
        else {
            for (int ez = 0; ez < n; ez++)
                pw.print(arr[ez] + " ");
        }
        pw.close();
    }

}
