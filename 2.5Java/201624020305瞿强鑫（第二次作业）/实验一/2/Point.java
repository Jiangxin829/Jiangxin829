package Second;

public class Point implements Sortable{
	/** 坐标值	*/
	private int x; 
    private int y;
	
	/** Point类的构造方法	*/
	Point(int x, int y) {  
		this.x = x;
		this.y = y;
	}	
	
	/** 实现Sortable接口中的Compare方法
	*	  @return 返回2个点的比较结果。<br>
	*						-如果2个点距离原点相等则返回0；<br>
	*           -如果当前点距离原点更近，则返回一个负数；<br>
	*           -否则返回一个正数。
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
	
	/** 覆盖父类的toString方法，便于直接输出Point的信息
	*/
	@Override 
	public String  toString() {
		return "Point: [" + x + ", " + y + "]";
	}
}
