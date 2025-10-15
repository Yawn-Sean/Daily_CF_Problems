package luogu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;

public class a{
    public static void main(String[]args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        PrintWriter pr=new PrintWriter(System.out);
        while(t-->0){
            String a=br.readLine();
            String[]nums=a.split(" ");
            int n=Integer.parseInt(nums[0]);
            int m=Integer.parseInt(nums[1]);
            char[][] arr=new char[n+1][m+1];
            for(int i=1;i<=n;i++){
                String s=br.readLine();
                for(int j=1;j<=m;j++){
                    arr[i][j]=s.charAt(j-1);
                }
            }
            int[]xmin=new int[26];
            Arrays.fill(xmin,n+1);
            int[]xmax=new int[26];
            Arrays.fill(xmax, -1);
            int[]ymin=new int[26];
            Arrays.fill(ymin,m+1);
            int[]ymax=new int[26];
            Arrays.fill(ymax,-1);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(arr[i][j]!='.'){
                        int c=arr[i][j]-'a';
                        xmin[c]=Math.min(xmin[c],i);
                        xmax[c]=Math.max(xmax[c],i);
                        ymin[c]=Math.min(ymin[c],j);
                        ymax[c]=Math.max(ymax[c],j);
                    }
                }
            }
            ArrayList<int[]>ors=new ArrayList<>();
            int xl=n+1;
            int xr=-1;
            int yl=m+1;
            int yr=-1;
            boolean flag=false;
            for(int i=25;i>=0;i--){
                if(xmin[i]<=xmax[i]){
                    if(xmin[i]==xmax[i]||ymin[i]==ymax[i]){
                        xl=xmin[i];
                        xr=xmax[i];
                        yl=ymin[i];
                        yr=ymax[i];
                    }else{
                        flag=true;
                        break;
                    }
                }
                if(xl!=n+1) ors.add(new int[]{xl,xr,yl,yr});
            }
            if(flag){
                pr.println("NO");
                pr.flush();
                continue;
            }
            char[][]arr1=new char[n+1][m+1];
            for(int i=0;i<=n;i++){
                Arrays.fill(arr1[i],'.');
            }
            int os=ors.size();
            for(int i=os-1,j=0;i>=0;i--,j++){
                int []tmp=ors.get(i);
                for(int l=tmp[0];l<=tmp[1];l++){
                    for(int r=tmp[2];r<=tmp[3];r++){
                        arr1[l][r]=(char)('a'+j);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(arr[i][j]!=arr1[i][j]){
                        flag=true;
                    }
                }
            }
            if(flag){
                pr.println("NO");
                pr.flush();
            }else{
                pr.println("YES");
                pr.println(os);
                for(int i=os-1;i>=0;i--){
                    int []tmp=ors.get(i);
                    pr.print(tmp[0]+" "+tmp[2]+" "+tmp[1]+" "+tmp[3]+"\n");
                }
                pr.flush();
            }
        }
    }
}