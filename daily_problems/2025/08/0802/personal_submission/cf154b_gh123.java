//https://codeforces.com/problemset/submission/154/332215313
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B154 {
    static int[]prime=new int[100001];
    static boolean[]taken=new boolean[100001];
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        Arrays.fill(prime, -1);
        while (m-->0) {
            char c=sc.next().charAt(0);
            int x=sc.nextInt();
            if(c=='+'){
                if(taken[x]){
                    System.out.println("Already on");
                    continue;
                }
                List<Integer>primefactor=getprime(x);
                int conflict=-1;
                for (int p : primefactor) {
                    if(prime[p]!=-1){
                        conflict=prime[p];
                        break;
                    }
                }
                if(conflict!=-1){
                    System.out.println("Conflict with "+conflict);
                }else{
                    for (int p : primefactor) {
                        prime[p]=x;
                    }
                    taken[x]=true;
                    System.out.println("Success");
                }
            }else if(c=='-'){
                if(!taken[x]){
                    System.out.println("Already off");
                    continue;
                }
                List<Integer>primefactors=getprime(x);
                for (int p : primefactors) {
                    if(prime[p]==x){
                        prime[p]=-1;
                    }
                }
                taken[x]=false;
                System.out.println("Success");
            }
        }
        sc.close();
    }
    public static List<Integer>getprime(int x){
        List<Integer>factor=new ArrayList<>();
        for (int i = 2; i*i <=x; i++) {
            if(x%i==0){
                factor.add(i);
                while (x%i==0) {
                    x/=i;
                }
            }
        }
        if(x>1) factor.add(x);
        return factor;
    }
}
