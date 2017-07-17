import java.util.*;

public class Reachability{
	private static boolean[] marked;
	private static ArrayList<Integer>[] adj2;
	static int reach(ArrayList<Integer>[] adj,int x, int y)
	{
		int path=0;
		adj2 = adj;
		int n = adj.length;
		marked = new boolean[n];
		for(int i=0;i<n;i++)
		{
			marked[i] = false;
		}
		
		Iterator<Integer> i;
		i = adj[x].listIterator();
		dfs(i,x);
		if(reachable(y))
		{
			path=1;
		}
		
		return path;
	}
	static void dfs(Iterator<Integer> i, int y)
	{
		
		marked[y]=true;
		i = adj2[y].listIterator();
		int n;
		while(i.hasNext())
		{
			n= i.next();
			if(!marked[n])
			{
				dfs(i,n);
			}
		}
		
		
	}
	static boolean reachable(int y)
	{
		return marked[y];
	}
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
            adj[y - 1].add(x - 1);
        }
        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        scanner.close();
       
        System.out.println(reach(adj, x, y));
    }

	
}