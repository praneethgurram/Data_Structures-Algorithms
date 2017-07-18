import java.util.*;

public class ChangingMoney{
	static int change(int ch)
	{
		int count =0;
		int denominationArray[] = {10,5,1};
		for(int i=0;i<denominationArray.length;i++)
		{
			if(denominationArray[i] <= ch)
			{
				ch = ch-denominationArray[i];
				count =count+1;
				if(ch >= denominationArray[i])
					i = i-1;
				
					
			}
			if(ch<=0)
				break;
			
		}
		
		return count;
	}
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		int ch = scanner.nextInt();
		scanner.close();
		System.out.println(change(ch));
	}
}