package Second;

public class Sort {

	/** ��̬����������ѡ�������㷨������a[]��������
	*	  @param a[] ��������Ķ�������
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
