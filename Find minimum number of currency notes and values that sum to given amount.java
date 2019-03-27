//url: https://www.geeksforgeeks.org/find-number-currency-notes-sum-upto-given-amount/
package products.prep.on;

import java.util.Collections;
import java.util.Map;
import java.util.TreeMap;

public class CountCurrency {
	static int [] currency = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	
	private static void getList(int money, TreeMap<Integer, Integer>  cache) {
		if(money <= 0) return;
		int flag1 = money;
		for(int i=0; i<currency.length; i++) {
			if(currency[i] == Integer.MAX_VALUE)
				continue;
			if(currency[i] > money)
				currency[i] = Integer.MAX_VALUE;
			else if(currency[i] < money) {
				Integer flag = cache.get(currency[i]);
				if(flag == null)
					cache.put(currency[i], 1);
				else
					cache.put(currency[i], flag+1);
				money -= currency[i];
				break;
			}else if(currency[i] == money) {
				Integer flag = cache.get(currency[i]);
				if(flag == null)
					cache.put(currency[i], 1);
				else
					cache.put(currency[i], flag+1);				
				return;
			}
		}
		if(money == flag1) return;
		getList(money, cache);
	}
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		int money = new java.util.Scanner(System.in).nextInt();
		
		TreeMap<Integer, Integer> cache = new TreeMap<Integer, Integer>(Collections.reverseOrder());
		System.out.println("Currency Count:");
		getList(money, cache);
		for(Map.Entry<Integer, Integer> m: cache.entrySet()) {
			System.out.println(m.getKey() +" : " + m.getValue());
		}
		
	}
}
