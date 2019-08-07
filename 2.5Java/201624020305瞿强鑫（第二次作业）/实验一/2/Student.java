package Second;

public class Student implements Sortable{
	private String name; 
    private int score;
	
	/** Point��Ĺ��췽��	*/
    Student(String name, int score) {  
		this.name = name;
		this.score = score;
	}	
	
	/** ʵ��Sortable�ӿ��е�Compare����
	*	  @return ����2����ıȽϽ����<br>
	*						-���2�������ԭ������򷵻�0��<br>
	*           -�����ǰ�����ԭ��������򷵻�һ��������<br>
	*           -���򷵻�һ��������
	*/	 
	public int compare(Sortable  s) { 
		Student S = (Student)s;  
		return name.compareTo(S.name);
	}
	
	/** ���Ǹ����toString����������ֱ�����Point����Ϣ
	*/
	@Override 
	public String  toString() {
		return "Student: [" + name + ",�ɼ��� " + score + "]";
	}

}
