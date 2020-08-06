/*package whatever //do not write package name here */

import java.io.*;
import java.math.*;
import java.util.*;

class Main {
	public static void main (String[] args) {
		Scanner in=new Scanner(System.in);
		int A, B, T;
		BigInteger t, a, b, ans;
		while (in.hasNextInt()) {
		    T=in.nextInt();
		    A=in.nextInt();
		    B=in.nextInt();
		    System.out.print("("+T+"^"+A+"-1)/("+T+"^"+B+"-1) ");
		    if (Math.log10(T)*(A-B)>=100 || (B>A) || (A%B!=0) || (T==1)) {
		        System.out.println("is not an integer with less than 100 digits.");
		    }
		    else if (A==B) System.out.println("1");
		    else {
		        t=BigInteger.valueOf(T);
		        a=t.pow(A);
		        b=t.pow(B);
		        a=a.subtract(BigInteger.ONE);
		        b=b.subtract(BigInteger.ONE);
		        ans=a.divide(b);
		        if (ans.toString().length()>=100)
		            System.out.println("is not an integer with less than 100 digits.");
		        else
		            System.out.println(ans);
		    }
		}
	}
}
