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
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        if ((a != 1 && b != 1) || ((n == 2 || n == 3) && a == 1 && b == 1))
            pw.println("NO");
        else {
            int[][] mat = new int[n][n];
            fan(mat, b != 1 ? b : a);
            if (b != 1)
                change(mat);
            pw.println("YES");
            for (int ez = 0; ez < mat.length; ez++) {
                for (int vn = 0; vn < mat[ez].length; vn++)
                    pw.print(mat[ez][vn]);
                pw.println();
            }
        }
        pw.close();
        f.close();
    }

    public static void fan(int[][] mat, int comp) {
        int len = mat.length;
        int ez = 0, vn = 1;
        while (len > comp) {
            mat[ez][vn] = mat[vn][ez] = 1;
            len--;
            vn++;
        }
        if (comp == 1 && mat.length > 1) {
            mat[1][mat.length - 1] = mat[mat.length - 1][1] = 1;
            mat[0][mat.length - 1] = mat[mat.length - 1][0] = 0;
        }
    }

    public static void change(int[][] mat) {
        for (int ez = 0; ez < mat.length; ez++) {
            for (int vn = ez + 1; vn < mat[ez].length; vn++)
                mat[ez][vn] = mat[vn][ez] = mat[ez][vn] == 0 ? 1 : 0;
        }
    }

}
