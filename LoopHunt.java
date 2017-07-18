import java.util.*;
public class LoopHunt{
	static double optimaLoopHunt(int capacity, int[] v, int[] w)
	{
		double loot=0;
		double cal=0;
		TreeMap<Double,Integer> tm = new TreeMap<Double,Integer>(Collections.reverseOrder());
		for(int i=0;i<v.length;i++)
		{
			tm.put((double)v[i]/w[i],w[i]);
		}
		Set<Map.Entry<Double, Integer>> set = tm.entrySet();
		for(Map.Entry<Double, Integer>i:set)
		{
			
			if(i.getValue()<=capacity&&capacity!=0)
			{
				cal =i.getKey()*i.getValue();
				loot = loot+ cal;
				capacity-=i.getValue();
				
				
			}
			else if(i.getValue()>capacity&&capacity!=0)
			{
				double k = i.getKey()*capacity;
				loot+=k;
				capacity=0;
				
			}
			if(capacity==0)
			{
				break;
			}
		}
		return loot;
	}
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int capacity = scanner.nextInt();
        int[] values = new int[n];
        int[] weights = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
            weights[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(optimaLoopHunt(capacity, values, weights));

	}
}