import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.List;



public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	static int nextInt() throws Exception{
		in.nextToken();
		return (int) in.nval;
	}
	static int q,m,n;
	static int[] a;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		
		n = nextInt();
		q = nextInt();
		m = nextInt();
		a = new int[n+1];
		for(int i=1;i<=n;i++) {
			a[i] = nextInt();

		}
		List<int[]> ops = new ArrayList<>();
		for(int i=0;i<q;i++) {
			int[] op = new int[3];
			op[0] = nextInt();
			op[1] = nextInt();
			op[2] = nextInt();
			ops.add(op);
		}
		
		while(m-->0) {
			int pos = nextInt();
			for(int i=q-1;i>=0;i--) {
				int[] op = ops.get(i);
				if(pos < op[1] || pos> op[2]) continue;
				
				if(op[0] == 1) {
					if(pos == op[1]) pos = op[2];
					else {
						pos--;
					}
				}
				
				else pos = op[1]+op[2]-pos;
			}
			
			pw.print(a[pos] + " ");
		}
		pw.flush();
	}

}
