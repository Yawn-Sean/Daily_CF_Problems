import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer in = new StreamTokenizer(br);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		in.nextToken();
		int k = (int)in.nval;
		in.nextToken();
		int n = (int)in.nval;
		long T = (long)k * (long)(k + 1) / 2;

		for(int i = 0; i < n; ++i){
			long r = ThreadLocalRandom.current().nextLong(T);

			long b = (long)((1 + Math.sqrt(1 + r * 8.0)) / 2);
			while(b * (b - 1) / 2 > r) b--;
			while(b * (b + 1) / 2 <= r) b++;

			long a = r - b * (b - 1) / 2 + 1;

			out.print(a + " " + b + "\n");
		}
		out.flush();
		out.close();
		br.close();
	}
}