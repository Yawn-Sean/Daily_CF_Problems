import java.io.*;
import java.util.*;
public class Main {
    static Scanner sc = new Scanner(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = sc.nextInt();
        int a[] = new int[2 * n + 1];
        for(int i = 1; i <= n - 1; i ++){
            if(i % 2 == 1) a[i / 2 + 1] = a[i / 2 + 1 + n - i] = i;
            else a[i / 2 + n] = a[i / 2 + n + n - i] = i;
        }
        for(int i = 1; i <= 2 * n; i ++) pw.print((a[i] == 0 ? n : a[i]) + " ");
        pw.flush();
    }   
}
