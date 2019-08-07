/***********************************************************************
 * Module:  ConnectionManager.java<br>
 * Purpose: 定义管理连接的类 ConnectionManager<br>
 * @author ***
 * @see Connection
* @see NoConnectionException
 ***********************************************************************/
package Test3; 
 
public class ConnectionManager {
	
	/** 连接池中的连接数量 */
	public final static int MAX_CONNECTION_NUMBER = 10;
	
	/** 存放连接的数组 */
	private static Connection[] pool 
				= new Connection[MAX_CONNECTION_NUMBER];
	
	/** 静态代码段，这个类加载时执行的代码块，仅执行一次
	*   创建初始的空闲连接，数量为MAX_CONNECTION_NUMBER个
	*/
	static {
		for(int i = 0; i < pool.length; i++)
			pool[i] = new Connection();
	}
	
	/** 静态方法，用于返回可用连接，当某个连接被使用后，相应数组元素置为null
	*  @return 返回可用连接的引用，如果连接池内的连接已经用完，则抛
	*  出异常类NoConnectionException的对象
	*/
	public static Connection getConnection() {
		//此处应声明抛出异常
		Connection poolIn=null;	
		for(int i=0; i<pool.length; i++)
		{
			if(pool[i] != null)
			{
				poolIn = pool[i];
				pool[i] = null;
				System.out.println(poolIn+"被取出");
				break;
			}
		}
		return poolIn;

	}
	
	
	/** 将连接放回连接池，以供其他用户使用
	*   @param c 在数组中寻找为null的元素，并将对象c放入；如果c为null，则输出提示
	*   信息并直接返回。
	*/
	public static void checkIn(Connection c) {
		if (c == null) 
		{
			System.out.println("连接为空");
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
			System.out.println(c+"被放回");
		}
	}
}