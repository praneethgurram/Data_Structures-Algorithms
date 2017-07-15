import java.util.*;

public class GCD{
	static long gCD(long a, long b)
	{
		long gcd=0,temp=0;
		
			while(b!=0)
			{
				a = a%b;
				temp = b;
				b =a;
				a = temp;
			}
			if(b==0)
				gcd=a;
		return gcd;
	}
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		long a = scanner.nextInt();
		long b = scanner.nextInt();
		scanner.close();
		long gcd = gCD(a,b);
		System.out.println(gcd);
	}
}