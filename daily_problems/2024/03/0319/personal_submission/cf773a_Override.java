import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
 
public class Main {
 
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	static long nextLong()throws Exception{
		in.nextToken();
		return (long) in.nval;
	}
	static int nextInt()throws Exception{
		in.nextToken();
		return (int) in.nval;
	}
	static long x,y,p,q;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		
		int T = nextInt();
		while(T-- != 0) {
			x = nextLong();
			y = nextLong();
			p = nextLong();
			q = nextLong();
			if(p == q) {
				int k = x==y?0:-1;
				pw.println(k);
				pw.flush();
				
				continue;
			}
			if(p == 0) {
				pw.println(x==0?0:-1);
				pw.flush();
				continue;
			}
			long n = (long) Math.max(Math.ceil(x*1.0/p),Math.ceil((y-x)*1.0/(q-p)));
			pw.println(n*q-y);
			pw.flush();
		}
	}
 
}
