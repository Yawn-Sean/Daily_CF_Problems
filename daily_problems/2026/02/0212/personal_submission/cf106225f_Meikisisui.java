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
            int[] arr = new int[n];
            for (int ez = 0; ez < n; ez++)
                arr[ez] = Integer.parseInt(st.nextToken());
            int res = 0;
            for (int ez = n - 2; ez >= 0; ez--) {
                if (arr[ez] >= arr[ez + 1]) {
                    int hang = arr[ez + 1];
                    if (hang != 1)
                        res = arr[ez] / (hang - 1);
                    break;
                }
            }
            if (res == 0) {
                int hang = arr[n - 1] - arr[n - 2];
                int lie = arr[n - 1] / hang;
                res = Math.max(hang, lie);
            }
            pw.println(res);
        }
        pw.close();
    }

}
