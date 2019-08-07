package Second;

public class Student implements Sortable{
	private String name; 
    private int score;
	
	/** Point类的构造方法	*/
    Student(String name, int score) {  
		this.name = name;
		this.score = score;
	}	
	
	/** 实现Sortable接口中的Compare方法
	*	  @return 返回2个点的比较结果。<br>
	*						-如果2个点距离原点相等则返回0；<br>
	*           -如果当前点距离原点更近，则返回一个负数；<br>
	*           -否则返回一个正数。
	*/	 
	public int compare(Sortable  s) { 
		Student S = (Student)s;  
		return name.compareTo(S.name);
	}
	
	/** 覆盖父类的toString方法，便于直接输出Point的信息
	*/
	@Override 
	public String  toString() {
		return "Student: [" + name + ",成绩： " + score + "]";
	}

}
