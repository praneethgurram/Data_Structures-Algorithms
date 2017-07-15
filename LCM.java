import java.util.Scanner;

public class LCM{
	static long lCM(long a, long b)
	{
		long lcm=0,temp=0;
		long a1=a,b1=b;
			while(b!=0)
			{
				a = a%b;
				temp = b;
				b =a;
				a = temp;
			}
			if(b==0)
				lcm=a;
			lcm = (a1*b1)/lcm;
		return lcm;
	}
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		long a = scanner.nextInt();
		long b = scanner.nextInt();
		scanner.close();
		long lcm = lCM(a,b);
		System.out.println(lcm);
	}
}