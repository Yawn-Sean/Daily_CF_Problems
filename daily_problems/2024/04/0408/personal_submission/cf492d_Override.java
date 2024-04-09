

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Main3 {
	
	static BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer cin = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	
	static long nextInt()throws Exception{
		cin.nextToken();
		return (long)cin.nval;
	}

    public static void main(String[] args)throws Exception {
    	long n, x, y;
        n = nextInt();
        x = nextInt();
        y = nextInt();
//        List<String> outs = new ArrayList<>();

        for (long i = 0; i < n; i++) {
        	long v = nextInt();
        	long l = 1, r = (long) Math.pow(10, 15);
            while (l <= r) {
            	long m = (l + r) / 2;
                if (m / x + m / y >= v) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            if (l % x == 0) {
                if (l % y == 0) {
                    pw.println("Both");
                } else {
                	pw.println("Vova");
                }
            } else {
            	pw.println("Vanya");
            }
        }

//        String output = String.join("\n", outs);
//        pw.println(output);
        pw.flush();
    }

    
}
