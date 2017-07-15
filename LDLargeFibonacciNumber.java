import java.util.*;

public class LDLargeFibonacciNumber{
	static int[] fibonnaci(int n)
	{
		int F[] = new int[n];
		F[0] =0;
		F[1]=1;
		for(int i=2;i<n;i++){
			F[i]=(F[i-1]+F[i-2])%10;
		}
		return F;
	}
	public static void main(String[] args)
	{

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();
		
		if(n==0)
		{
			System.out.println("0");
		}
		else{
			int numbers[] = new int[n+1];
			numbers = fibonnaci(n+1);
			
		System.out.println(numbers[n]);
		}
	}
}



