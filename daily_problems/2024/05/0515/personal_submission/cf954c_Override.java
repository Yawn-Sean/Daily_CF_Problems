import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.*;

public class c954 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StreamTokenizer cin = new StreamTokenizer(br);
	public static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	public static int nextInt() throws Exception{
		cin.nextToken();
		return (int) cin.nval;
		
	}
	static int[] a = new int[200010];
	static int c=1,t=1;
    public static void main(String[] args) throws Exception {
    	int n = nextInt();
    	for(int i=1;i<=n;i++) {
    		a[i] = nextInt();
    		if(i>1 && a[i]==a[i-1]) t=0;//第二条规则
    		if(i>1 && Math.abs(a[i]-a[i-1])!=1 && a[i]!=a[i-1]) c=Math.abs(a[i]-a[i-1]);//c设置为差值
    		
    	}
    	for(int i=2;i<=n;i++) {
    		if(Math.abs(a[i]-a[i-1])!=1 && Math.abs(a[i]-a[i-1])!=c) t=0;//第一条规则
    		else if(Math.abs(a[i]-a[i-1])==1 && c!=1 && (a[i]-1)/c!=(a[i-1]-1)/c) t=0;
    	}
    	if(t==0) pw.print("NO");
    	else pw.print("YES\n1000000000 "+c);
    	pw.flush();
    	
    }
}
