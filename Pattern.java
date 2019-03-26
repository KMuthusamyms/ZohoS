import java.io.*;
public class Pattern {
	
	private static void getPattern(char [][] array, int in, int jn, int m, int n) {
		for(int i=in; i<m; i++) {
			for(int j=jn; j<n; j++) {
				if(j == jn ||  i == in || j == n-1)
					array[i][j] = 'X';
				
				if(i == m-1)
					array[i][j] = 'X';
			}
		}
	}
	public static void main(String[] args)throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		System.out.println("Enter Range:");
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		
		char[][] array = new char[m][n];
		
		for(int i=0; i<array.length; i++) {
			for(int j=0; j<array[i].length; j++) {
				array[i][j] = '0';
			}
		}
		/*
			getPattern(array, 2, 2, m-2, n-2);
			getPattern(array, 4, 4, m-4, n-4);
		*/
		int in=0, jn=0, m1=m, n1 =n;
		for(; in<n/2; ) {
			getPattern(array, in, jn, m1, n1);
			in +=2;
			jn +=2;
			n1 -=2;
			m1 -=2;
		}
		for(int i=0; i<array.length; i++) {
			for(int j=0; j<array[i].length; j++) {
				System.out.print(array[i][j]+" ");
			}
			System.out.println();
		}
	}
}
