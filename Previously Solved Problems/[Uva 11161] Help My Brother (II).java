
package main;

import java.util.Scanner;
//import java.util.*;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger fib[]= new BigInteger[1505];
        fib[0]=BigInteger.ONE;
        fib[1]=BigInteger.ONE;
        int i;
        for (i=2; i<fib.length; i++) 
            fib[i]=fib[i-1].add(fib[i-2]);
        for (i=0; i<fib.length; i++)
            fib[i]=fib[i].subtract(BigInteger.ONE);
        String s;
        int ca=1;
        while ( !(s=in.nextLine()).equals("0") ) {
            System.out.println("Set "+(ca++)+":");
            i=Integer.parseInt(s);
            System.out.println(fib[i].shiftLeft(1).add(fib[i-1]).shiftRight(1));
        }
    }
}
