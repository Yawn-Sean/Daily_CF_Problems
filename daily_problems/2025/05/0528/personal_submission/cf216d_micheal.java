package luogu;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class a{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        ArrayList<int []> arr=new ArrayList<>();
        for(int i=0;i<n;i++){
            int k=sc.nextInt();
            int []tmp=new int[k];
            for(int j=0;j<k;j++){
                tmp[j]=sc.nextInt();
            }
            arr.add(tmp);
            Arrays.sort(arr.get(i));
        }
        sc.close();
        int res=0;
        for(int i=0;i<n;i++){
            int k=i-1;
            if(k<0) k=n-1;
            res+=check(arr.get(i),arr.get((i+1)%n),arr.get(k));
        }
        System.out.println(res);
        
    }
    private static int check(int []arr1,int []arr2,int []arr3){
        int ans=0;
        for(int i=0;i<arr1.length-1;i++){
            int l1=upper_bound(arr1[i],arr2);
            int r1=upper_bound(arr1[i+1], arr2);
            int l2=upper_bound(arr1[i], arr3);
            int r2=upper_bound(arr1[i+1], arr3);
            if(r1-l1!=r2-l2) ans++;
        }
        return ans;
    }
    private static int upper_bound(int k,int []arr){
        int l=0;
        int r=arr.length-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>=k){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    } 
}