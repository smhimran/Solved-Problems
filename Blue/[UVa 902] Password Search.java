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
		
		while (in.hasNextInt()) {
		    Integer n = in.nextInt();
		    
		    String text = in.next();
		    
		    HashMap<String, Integer> times = new HashMap<String, Integer>();
		    
		    Integer maxTimes = 0;
		    
		    String answer = "";
		    
		    for (int i=0; i<text.length() - n + 1; i++) {
		    	String substring = text.substring(i, i + n);
		    	
		    	Integer now = 0;
		    	
		    	if (times.containsKey(substring))
		    		now = times.get(substring);
		    	
		    	now++;
		    	
		    	times.put(substring, now);
		    	
		    	
		    	if (now > maxTimes) {
		    		maxTimes = now;
		    		
		    		answer = substring;
		    	}
		    }
		    
		    System.out.println(answer);
		}
	}
}