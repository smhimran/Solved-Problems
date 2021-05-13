import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		
		// File I/O
		try {
			
			System.setIn(new FileInputStream(new File("in.txt")));
			System.setOut(new PrintStream(new File("out.txt")));
		}
		catch (Exception e) {
			System.out.println(e);
		}
		
		Scanner in = new Scanner(System.in);
		
		int n, d;

		while (true) {
			n = in.nextInt();
			d = in.nextInt();

			if (n == 0 && d == 0)
				break;

			BigInteger[] dp = new BigInteger[22];
			dp[0] = BigInteger.ONE;

			for (int i=1; i<=d; i++) {
				dp[i] = BigInteger.ONE;

				for (int j=1; j<=n; j++)
					dp[i] = dp[i].multiply(dp[i - 1]);

				dp[i] = dp[i].add(BigInteger.ONE);
			}

			if (d == 0)
				System.out.println(n + " " + d + " " + 1);
			else 
				System.out.println(n + " " + d + " " + dp[d].subtract(dp[d - 1]));
		}
	}
}