import java.io.*;
 
public class cf1028c {
    static final int INF = 1_000_000_010;
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
 
        int n = Integer.parseInt(reader.readLine());
        int[] x1 = new int[n], x2 = new int[n], y1 = new int[n], y2 = new int[n];
        for (int i = 0; i < n; i++) {
            String[] tokens = reader.readLine().split(" ");
            x1[i] = Integer.parseInt(tokens[0]);
            y1[i] = Integer.parseInt(tokens[1]);
            x2[i] = Integer.parseInt(tokens[2]);
            y2[i] = Integer.parseInt(tokens[3]);
        }
        int[] x1Max = new int[n], x2Min = new int[n], y1Max = new int[n], y2Min = new int[n];
        x1Max[0] = -INF; x2Min[0] = INF; y1Max[0] = -INF; y2Min[0] = INF;
        for (int i = 0; i < n - 1; i++) {
            x1Max[i + 1] = Math.max(x1Max[i], x1[i]);
            x2Min[i + 1] = Math.min(x2Min[i], x2[i]);
            y1Max[i + 1] = Math.max(y1Max[i], y1[i]);
            y2Min[i + 1] = Math.min(y2Min[i], y2[i]);
        }
        int x1MaxSuf = -INF, x2MinSuf = INF, y1MaxSuf = -INF, y2MinSuf = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (Math.max(x1MaxSuf, x1Max[i]) <= Math.min(x2MinSuf, x2Min[i]) &&
                Math.max(y1MaxSuf, y1Max[i]) <= Math.min(y2MinSuf, y2Min[i])) {
                writer.write(String.valueOf(Math.max(x1MaxSuf, x1Max[i])) + ' ' +
                        String.valueOf(Math.max(y1MaxSuf, y1Max[i])));
 
                reader.close();
                writer.close();
                return;
            }
            x1MaxSuf = Math.max(x1MaxSuf, x1[i]);
            x2MinSuf = Math.min(x2MinSuf, x2[i]);
            y1MaxSuf = Math.max(y1MaxSuf, y1[i]);
            y2MinSuf = Math.min(y2MinSuf, y2[i]);
        }
    }
}
