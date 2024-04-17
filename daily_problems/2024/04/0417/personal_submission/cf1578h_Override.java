
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Iterator;

public class Main14 {
	
	static BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer cin = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

	static int nextInt()throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
	static String str;
	static int od(int l,int r) {
		if(l+1==r) return 0;
		int cur = 0;
		for(int i=l;i<=r;i++) {
			if(str.charAt(i)=='(') cur++;
			if(str.charAt(i)==')') cur--;
			if(cur==0 && str.charAt(i)=='-'){
				return Math.max(od(l,i-1)+1,od(i+2,r));
			}
		}
		
		return od(l+1,r-1);
	}
	public static void main(String[] args)throws Exception{
		str = br.readLine();
		int l=0,r=str.length()-1;
		pw.print(od(l,r));
		pw.flush();
		
	}

}
