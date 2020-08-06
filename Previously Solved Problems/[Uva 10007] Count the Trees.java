/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	public static void main (String[] args) {
		Scanner in=new Scanner(System.in);
		while (true) {
		    int n;
		    n=in.nextInt();
		    if (n==0) break;
		    BigInteger k= new BigInteger("1");
		    for (int i=2*n; i>n+1; i--)
		        k=k.multiply(BigInteger.valueOf(i));
		    System.out.println(k);
		}
	}
}
