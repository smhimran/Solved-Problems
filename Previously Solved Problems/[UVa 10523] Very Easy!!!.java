import java.util.*;
import java.lang.Math;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
         Scanner in=new Scanner(System.in);
         int n, a;
         while (in.hasNextInt()) {
             n=in.nextInt();
             a=in.nextInt();
             BigInteger sum=BigInteger.ZERO;
             BigInteger A=BigInteger.valueOf(a);
             for (int i=1; i<=n; i++) {
                 sum=sum.add((A.pow(i)).multiply(BigInteger.valueOf(i)));
             }
             System.out.println(sum);
         }
    }
}
