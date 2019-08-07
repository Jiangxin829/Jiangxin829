/***********************************************************************
 * Module:  DBClient.java<br>
 * Purpose: 连接池的用户，用于测试ConnectionManager<br>
 * @author ***
 * @see Connection 
 * @see ConnectionManager 
 ***********************************************************************/
package Test3; 
 
public class DBClient {
	
	public static void main(String args[]) {
		Connection[] ca 
			= new Connection[ConnectionManager.MAX_CONNECTION_NUMBER+2];
	// 取出所有连接,并输出连接信息
	for(int i = 0; i < ca.length; i++) 
	{
		ca[i] = ConnectionManager.getConnection();
	}
	//加入连接的获取、放回、信息输出等测试代码
		ConnectionManager.checkIn(ca[1]);	
	}
} 

