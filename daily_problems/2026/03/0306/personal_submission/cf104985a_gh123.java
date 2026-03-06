import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class cf104985a {
     public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[][] data = new long[n][3];
        long totalV = 0;
        
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            data[i][0] = Long.parseLong(st.nextToken());
            data[i][1] = Long.parseLong(st.nextToken());
            data[i][2] = i;
            totalV += data[i][0];
        }
        
        Arrays.sort(data, (a, b) -> Long.compare(a[1], b[1]));
        
        long curV = totalV;
        long curT = 0;
        double[] ans = new double[n];
        double res = 0;
        
        for (int i = 0; i < n; i++) {
            long vs_val = data[i][0];
            long ts_val = data[i][1];
            int originalIdx = (int)data[i][2];
            
            res += (double)(ts_val - curT) * curV / totalV;
            ans[originalIdx] = res;
            curT = ts_val;
            curV -= vs_val;
        }
        
        StringBuilder sb = new StringBuilder();
        for (double x : ans) sb.append(String.format("%.15f\n", x));
        System.out.print(sb);
    }
}
