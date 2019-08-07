	//定义接口：
	interface Human
	{
		//public static string sex=new String("man");
		public abstract void eat();
		public abstract void sleep();
		public abstract void communicate();
	}
	//实现接口：
	class Chinese implements Human
	{
		public void eat(){ System.out.println("Chinese eat rice!");}
		public void sleep(){ System.out.println("Chinese sleep for 8 hours!");}
		public void communicate(){ System.out.println("Chinese communicate in Chinese!");}
	}
	//使用接口：
	public class Test
	{
		public static void main(String args[])
		{
			Human h=new Chinese();
			h.eat();
			h.sleep();
			h.communicate();
		}
	}
