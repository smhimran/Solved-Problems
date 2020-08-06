/*package whatever //do not write package name here */

import java.io.*;
import java.math.*;
import java.util.*;

class Main {
	public static void main (String[] args) {
		Scanner in=new Scanner(System.in);
		while (true) {
		    int b=in.nextInt();
		    if (b==0) break;
		    String p1, p2;
		    p1=in.next();
		    p2=in.next();
		    BigInteger p=new BigInteger(p1, b);
		    BigInteger m=new BigInteger(p2, b);
		    System.out.println(p.mod(m).toString(b));
		}

	}
}
