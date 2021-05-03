import java.io.*;
import java.util.*;

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
		
		Set<String> words = new TreeSet<String>();
		
		while (in.hasNext()) {
			String word = in.next();
			
			
			words.add(word);
	    }
	    
	   	for (String word: words) {
	   		int n = word.length();
	   		
	   		for (int i=0; i<n; i++) {
	   			String left = word.substring(0, i);
	   			String right = word.substring(i, n);
	   			
	   			if (words.contains(left) && words.contains(right)) {
	   				System.out.println(word);
	   				
	   				break;
	   			}
	   		}
	   	}
	}
}