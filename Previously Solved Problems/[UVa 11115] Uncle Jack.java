import java.util.*;
import java.lang.Math;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
         Scanner in=new Scanner(System.in);
         BigInteger N;
         while (true) {
             int d, n;
             n=in.nextInt();
             d=in.nextInt();
             if (d==0 && n==0) break;
             N=BigInteger.valueOf(n);
             N=N.pow(d);
             System.out.println(N);
         }
    }
}
