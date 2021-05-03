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
			System.out.println("Error!");
		}
		
		Scanner in = new Scanner(System.in);
		
		while (true) {
		    int n = in.nextInt();
		    if (n == 0) 
		    	break;
		    
		    String[] keys = new String[n+1];
		    String[] correct = new String[n+1];
		    
		    in.nextLine();
		    
		    for (int i=0; i<n; i++) {
		    	String word = in.nextLine();
		    	
		    	String replaced = in.nextLine();
		    	
		    	keys[i] = word;
		    	
		    	correct[i] = replaced;
		    }
		    
		    String text = in.nextLine();
		    
		    boolean ok = false;

	    	for (int i=0; i<n; i++) {
	    		while (text.contains(keys[i])) {
		    		
		    		text = text.replaceFirst(keys[i], correct[i]);
	    		}
	    	}

		    System.out.println(text);
		}
	}
}