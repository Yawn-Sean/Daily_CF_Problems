import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int[] visited = new int[256];
        Arrays.fill(visited, -1);
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
            if (visited[arr[ez]] == -1) {
                int left = arr[ez] - k + 1;
                if (left < 0)
                    left = 0;
                while (visited[left] != -1 && visited[left] != left)
                    left++;
                for (int vn = left; vn <= arr[ez]; vn++)
                    visited[vn] = left;
            }
        }
        for (int ez = 0; ez < n; ez++) {
            pw.print(visited[arr[ez]]);
            if (ez != n - 1)
                pw.print(" ");
        }
        pw.close();
        br.close();
    }

}
