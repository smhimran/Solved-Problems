/*package whatever //do not write package name here */

import java.io.*;
import java.math.*;
import java.util.*;

class Main {
	public static void main (String[] args) {
	    Scanner in=new Scanner(System.in);
		BigInteger[] cat=new BigInteger[1001];
		cat[0]=cat[1]=BigInteger.ONE;
		for (int i=2; i<=1000; i++) {
		    cat[i]=BigInteger.ZERO;
		    for (int j=0; j<i; j++) {
		        cat[i]=cat[i].add(cat[j].multiply(cat[i-j-1]));
		    }
		}
	    int n;
	    while (in.hasNextInt()) {
	        n=in.nextInt();
	        System.out.println(cat[n]);
	    }
	}
}
