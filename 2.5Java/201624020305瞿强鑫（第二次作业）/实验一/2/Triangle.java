package Second;

public class Triangle implements Sortable{
	/** ����ֵ	*/
	private Point x; 
    private Point y;
    private Point z;
	
	/** Point��Ĺ��췽��	*/
    Triangle(Point x, Point y,Point z) {  
		this.x = x;
		this.y = y;
		this.z = z;
	}	
	/** ʵ��Sortable�ӿ��е�Compare����
	*	  @return ����2����ıȽϽ����<br>
	*						-���2�������ԭ������򷵻�0��<br>
	*           -�����ǰ�����ԭ��������򷵻�һ��������<br>
	*           -���򷵻�һ��������
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
	
	/** ���Ǹ����toString����������ֱ�����Point����Ϣ
	*/
	@Override 
	public String  toString() {
		return "Triangle: "+Mianji();
	}

}
