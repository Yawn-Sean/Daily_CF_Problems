import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
 
public class Main7 {
	
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StreamTokenizer cin = new StreamTokenizer(br);
	public static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	public static int nextInt() throws Exception{
		cin.nextToken();
		return (int) cin.nval;
		
	}
	
	static int[] a = new int[20];
	static int[] tmp = {1869,1968,1689,6198,1698,1986,1896};
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		// cin读不了纯数字串  br小心换行 用read有时候读一下
		String s = br.readLine();
		int len = s.length();
		for(int i=0;i<len;i++) {
			a[s.charAt(i)-'0']++;
		}
		
		a[1]--;a[6]--;a[8]--;a[9]--;
		int r = 0;//余数
		
		for(int i=1;i<10;i++) {
			while(a[i]>0) {
				r = r*10%7+i%7;
				pw.print(i);
				a[i]--;
			}
		}
		
		r = r*10000%7;
		pw.print(tmp[(7-r)%7]);
		
		while(a[0]>0) {
			pw.print('0');
			a[0]--;
		}
		pw.flush();
	}
 
}
