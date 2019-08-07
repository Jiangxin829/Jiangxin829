/***********************************************************************
 * Module:  ConnectionManager.java<br>
 * Purpose: ����������ӵ��� ConnectionManager<br>
 * @author ***
 * @see Connection
* @see NoConnectionException
 ***********************************************************************/
package Test3; 
 
public class ConnectionManager {
	
	/** ���ӳ��е��������� */
	public final static int MAX_CONNECTION_NUMBER = 10;
	
	/** ������ӵ����� */
	private static Connection[] pool 
				= new Connection[MAX_CONNECTION_NUMBER];
	
	/** ��̬����Σ���������ʱִ�еĴ���飬��ִ��һ��
	*   ������ʼ�Ŀ������ӣ�����ΪMAX_CONNECTION_NUMBER��
	*/
	static {
		for(int i = 0; i < pool.length; i++)
			pool[i] = new Connection();
	}
	
	/** ��̬���������ڷ��ؿ������ӣ���ĳ�����ӱ�ʹ�ú���Ӧ����Ԫ����Ϊnull
	*  @return ���ؿ������ӵ����ã�������ӳ��ڵ������Ѿ����꣬����
	*  ���쳣��NoConnectionException�Ķ���
	*/
	public static Connection getConnection() {
		//�˴�Ӧ�����׳��쳣
		Connection poolIn=null;	
		for(int i=0; i<pool.length; i++)
		{
			if(pool[i] != null)
			{
				poolIn = pool[i];
				pool[i] = null;
				System.out.println(poolIn+"��ȡ��");
				break;
			}
		}
		return poolIn;

	}
	
	
	/** �����ӷŻ����ӳأ��Թ������û�ʹ��
	*   @param c ��������Ѱ��Ϊnull��Ԫ�أ���������c���룻���cΪnull���������ʾ
	*   ��Ϣ��ֱ�ӷ��ء�
	*/
	public static void checkIn(Connection c) {
		if (c == null) 
		{
			System.out.println("����Ϊ��");
		}
		else
		{
			for(int i=0; i<pool.length; i++)
			{
				if(pool[i] == null)
				{
					pool[i] = c;
					break; 
				}
			}
			System.out.println(c+"���Ż�");
		}
	}
}