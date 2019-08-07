/***********************************************************************
 * Module:  Connection.java<br>
 * Purpose: 定义连接类Connection<br>
 * @author *** 
 * @see ConnectionManager
 ***********************************************************************/ 
package Test3; 
 
public class Connection {
	
	/** 连接的计数值 */
	private static int counter = 0;
	
	/** 连接的id号 */
	private int id = counter++;
	
	/** 构造方法 */
	Connection() {}
	
	/** 覆盖父类的toString方法，便于直接输出连接信息
	*/
	@Override 
	public String toString() {
		return "Connection " + id;
	}
	
	/** 通过本连接进行相关的操作 */
	public void doSomething() {}
	
	/** 将当前对象放回连接池中 */
	public void checkIn() {
		ConnectionManager.checkIn(this);
	}
} 





 

