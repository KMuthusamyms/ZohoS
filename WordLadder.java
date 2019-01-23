/*
	Approaches:
	We will BFS to implement this algorithm.
	1. Put all word in list, Base case when List will be empty.
	2. We will check one by one each word, if match found will return count;
	3. if first word, and the word top from list is identical, we replace the word from list to first.
		3.1 do continue, until match found or list become empty
	
	That's It. :) 
	Coder:
		SJ.
*/
import java.util.*;

class WordLadder{
	static boolean isIdentical(String first, String temp){
		int count = 0;
		for(int i=0; i<first.length(); i++){
			if(first.charAt(i) == temp.charAt(i))
				count++;
		}

		return (count == first.length()-1);
	}
	static int getValue(LinkedList<String> list, String first, String target, int count){
		if(list.isEmpty())
			return -1;

		if(first.equals(target))
			return count+1;

		int size = list.size();

		String flag = first;
		System.out.println(flag);
		while(size-- > 0){
			String temp = list.remove();						
			if(isIdentical(first, temp)){				
				first = temp;
				list.addFirst(first);
				break;
			}
			else
				list.addLast(temp);
		}

		list.remove();

		if(flag.equals(first))
			return -1;

		return getValue(list, first, target, count+1);
	}
	public static void main(String[] args) {
		LinkedList<String> list = new LinkedList<String>();
		String [] dictionary = {"POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"};

		for(int i=0; i<dictionary.length; i++){
			list.addLast(dictionary[i]);
		}
		String start = "TOON";
		String target = "PLEA";
		
		int count = getValue(list, start, target, 0);		
		System.out.println(count != -1 ? "We Need "+count+" Iteration, To Reach " + start + " to "+target+"." : "Can't Reach Ever!");
	}
}