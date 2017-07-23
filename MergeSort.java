import java.util.*;
public class MergeSort {
	void merge(int[] a, int left, int mid, int right)
	{
		int n1= mid-left+1;
		int n2 = right-mid;
		int L[] = new int[n1];
		int R[] = new int[n2];
		for(int i =0;i < n1;++i)
		{
			L[i] = a[left+i];
		}
		for(int j=0;j < n2;++j)
		{
			R[j] = a[mid+1+j];
		}
		int i=0,j=0,k=1;
		while(i < n1 && j < n2)
		{
			if(L[i] <= R[j])
			{
				a[k] = L[i];
				i++;
				++k;
			}
			else
			{
				a[k] = R[j];
				j++;
				++k;
			}
			
		}
		while(i < n1)
		{
			a[k] = L[i];
			i++;
			k++;
		}
		while(j < n2)
		{
			a[k] = R[j];
			j++;
			k++;
		}
	}
	void mergesort(int a[], int left, int right)
	{
		if(left < right)
		{
			int mid = (left+right)/2;
			mergesort(a,left,mid);
			mergesort(a,mid+1,right);
			merge(a,left,mid,right);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int a[] = new int[n];
		for(int i=0;i<n;i++)
		{
			a[i] = scanner.nextInt();
		}
		scanner.close();
		MergeSort ms = new MergeSort();
		ms.mergesort(a, 0, a.length - 1);
		for(int i:a)
		{
			System.out.print(i+" ");
		}
	}

}
