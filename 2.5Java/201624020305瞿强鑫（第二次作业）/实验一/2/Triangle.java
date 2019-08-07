package Second;

public class Triangle implements Sortable{
	/** 坐标值	*/
	private Point x; 
    private Point y;
    private Point z;
	
	/** Point类的构造方法	*/
    Triangle(Point x, Point y,Point z) {  
		this.x = x;
		this.y = y;
		this.z = z;
	}	
	/** 实现Sortable接口中的Compare方法
	*	  @return 返回2个点的比较结果。<br>
	*						-如果2个点距离原点相等则返回0；<br>
	*           -如果当前点距离原点更近，则返回一个负数；<br>
	*           -否则返回一个正数。
	*/	 
	public int compare(Sortable  s) { 
		Triangle p = (Triangle)s;   
		double MJ1,MJ2;
		MJ1=Mianji();
		MJ2=p.Mianji();
		return (int)(MJ1 - MJ2); 
	}
	public double Mianji() {    
		double MJ1,ZC1;
		ZC1=x.KM(y)+y.KM(z)+z.KM(x);
		MJ1=Math.sqrt((ZC1-x.KM(y))*(ZC1-y.KM(z))*ZC1-z.KM(x));
		return MJ1; 
	}
	
	/** 覆盖父类的toString方法，便于直接输出Point的信息
	*/
	@Override 
	public String  toString() {
		return "Triangle: "+Mianji();
	}

}
