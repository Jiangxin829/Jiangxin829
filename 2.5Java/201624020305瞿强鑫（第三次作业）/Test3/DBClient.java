/***********************************************************************
 * Module:  DBClient.java<br>
 * Purpose: ���ӳص��û������ڲ���ConnectionManager<br>
 * @author ***
 * @see Connection 
 * @see ConnectionManager 
 ***********************************************************************/
package Test3; 
 
public class DBClient {
	
	public static void main(String args[]) {
		Connection[] ca 
			= new Connection[ConnectionManager.MAX_CONNECTION_NUMBER+2];
	// ȡ����������,�����������Ϣ
	for(int i = 0; i < ca.length; i++) 
	{
		ca[i] = ConnectionManager.getConnection();
	}
	//�������ӵĻ�ȡ���Żء���Ϣ����Ȳ��Դ���
		ConnectionManager.checkIn(ca[1]);	
	}
} 

