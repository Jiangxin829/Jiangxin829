/** ��ά���������
 *����һ�����ڲ�������Ĺ����ࡣ
 *������ɶ�ά����ÿ�г���
 *������ɶ�ά������ֵ
 *@author ����
 *@version V1.0
 */
import java.util.Random;
public class TestArray{
	/**
	��������
	*/
	public static int[][] initArray(int m,int nMax,int nMin,int max,int min)
	{
		int [][] arr=new int[m][];
		for(int i=0;i<m;i++)
		{
			int n=(int)Math.round(Math.random()*(nMax-nMin)+nMin);
			arr[i]=new int [n];
			for(int j=0;j<n;j++)
			{
				arr[i][j]=(int)(Math.random()*(max-min)+min);
			}
		}
		return arr;    //��������
	}
	/**
	*�������Ļ
	*/
	public static void printArray(int[][] a){
	for(int i=0;i<3;i++){
		for(int n=0;n<a[i].length;n++){
			System.out.print(a[i][n]);
			System.out.print('\t');
		}
		System.out.print('\n');
	}
	}
	
	public static void main(String args[]){
		printArray(initArray(3,1,5,1,9));
	}
}