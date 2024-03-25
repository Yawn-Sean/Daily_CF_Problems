import java.io.*;
public class Main{
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	static double nextDouble()throws Exception{
		in.nextToken();
		return (double) in.nval;
	}
	static int nextInt()throws Exception{
		in.nextToken();
		return (int) in.nval;
	}
    public static void main(String[] args) throws Exception{

       int n = nextInt();
       double r = nextDouble();
       int[] x = new int[n];  
       double[] y = new double[n];
   
       for(int i = 0; i < n; ++i) 
           x[i] = nextInt();
           
       for(int i = 0; i < n; ++i) {
           y[i] = r;
           for(int j = 0; j < i; ++j) {
               if(Math.abs(x[i] - x[j]) <= 2*r)
                {
                    double delta = Math.sqrt(4*r*r - (x[i]-x[j])*(x[i]-x[j]));
                    y[i] = Math.max(y[i],delta + y[j]);
                }
           }
           pw.print(i==0 ? y[i] : " " + y[i]);
       }     
       pw.flush();
   }
}
