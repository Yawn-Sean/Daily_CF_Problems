import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        char[][] matrix = new char[m][n];
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            matrix[ez] = s.toCharArray();
        }
        for (int ez = 0; ez < m; ez++) {
            for (int vn = 0; vn < n; vn++) {
                if (matrix[ez][vn] == '.') {
                    matrix[ez][vn] = 'L';
                    for (int x = ez + 1; x < m; x++) {
                        if (matrix[x][vn] == '.')
                            matrix[x][vn] = '1';
                        if (matrix[x][vn] == '#')
                            break;
                    }
                    for (int y = vn + 1; y < n; y++) {
                        if (matrix[ez][y] == '.')
                            matrix[ez][y] = '1';
                        if (matrix[ez][y] == '#')
                            break;
                    }
                }
            }
        }
        for (int ez = 0; ez < m; ez++) {
            for (int vn = 0; vn < n; vn++) {
                if (matrix[ez][vn] == '1')
                    matrix[ez][vn] = '.';
                pw.print(matrix[ez][vn]);
            }
            pw.println();
        }
        pw.close();
    }

}
