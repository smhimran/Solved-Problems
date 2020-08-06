/*package whatever //do not write package name here */

import java.io.*;
import java.math.*;
import java.util.*;

class Main {
	public static void main (String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		char ch;
		while (n>0) {
		    BigInteger a, b, k;
		    a=in.nextBigInteger();
		    ch=in.next().charAt(0);
		    b=in.nextBigInteger();
		    k=a.gcd(b);
		    a=a.divide(k);
		    b=b.divide(k);
		    System.out.println(a+" / "+b);
		    n--;
		}
	}
}
