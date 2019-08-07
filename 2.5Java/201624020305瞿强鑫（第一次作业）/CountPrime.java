public class CountPrime{
	public static void main(String args[]){
		int n=1,m,j,i;
		boolean h;
		System.out.print(2+"\t");
		for(i=3;i<=100;i+=2)
		{
			m=(int)Math.sqrt(i);
			h=true;
			for(j=2;j<=m;j++)
			{
				if(i%j==0)
				{
					h=false;
					break;
				}
			}
			if(h){
				if(n%6==0){
				System.out.println("");
				}
				System.out.print(i+"\t");
				n++;
			}
		}
	}
}