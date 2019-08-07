package Second;

public class Sort {

	/** 静态方法，利用选择排序算法对数组a[]进行排序
	*	  @param a[] 进行排序的对象数组
	*/
	public static void SelectSort(Sortable a[]){
		int i, j, k;
		Sortable temp;
				
		for(i=0; i<a.length-1; i++) {
			k=i;
			
			for(j=i+1; j<a.length; j++)
				if(a[k].compare(a[j])<0)
					k=j;
					
			temp=a[i];  a[i]=a[k];  a[k]=temp;
		}
	}
}
