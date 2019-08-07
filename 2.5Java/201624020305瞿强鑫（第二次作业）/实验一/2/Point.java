package Second;

public class Point implements Sortable{
	/** ����ֵ	*/
	private int x; 
    private int y;
	
	/** Point��Ĺ��췽��	*/
	Point(int x, int y) {  
		this.x = x;
		this.y = y;
	}	
	
	/** ʵ��Sortable�ӿ��е�Compare����
	*	  @return ����2����ıȽϽ����<br>
	*						-���2�������ԭ������򷵻�0��<br>
	*           -�����ǰ�����ԭ��������򷵻�һ��������<br>
	*           -���򷵻�һ��������
	*/	 
	public int compare(Sortable  s) { 
		Point p = (Point)s;   
		long n1, n2;
		
		n1 = x*x + y*y;
		n2 = p.x*p.x + p.y*p.y;

		return (int)(n1 - n2); 
	}
	public double KM(Sortable  s) { 
		Point p = (Point)s;   
		double n1;
		n1=Math.sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
		return n1; 
	}
	
	/** ���Ǹ����toString����������ֱ�����Point����Ϣ
	*/
	@Override 
	public String  toString() {
		return "Point: [" + x + ", " + y + "]";
	}
}
