/***********************************************************************
 * Module:  Connection.java<br>
 * Purpose: ����������Connection<br>
 * @author *** 
 * @see ConnectionManager
 ***********************************************************************/ 
package Test3; 
 
public class Connection {
	
	/** ���ӵļ���ֵ */
	private static int counter = 0;
	
	/** ���ӵ�id�� */
	private int id = counter++;
	
	/** ���췽�� */
	Connection() {}
	
	/** ���Ǹ����toString����������ֱ�����������Ϣ
	*/
	@Override 
	public String toString() {
		return "Connection " + id;
	}
	
	/** ͨ�������ӽ�����صĲ��� */
	public void doSomething() {}
	
	/** ����ǰ����Ż����ӳ��� */
	public void checkIn() {
		ConnectionManager.checkIn(this);
	}
} 





 

