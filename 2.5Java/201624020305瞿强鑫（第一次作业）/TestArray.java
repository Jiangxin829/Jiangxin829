/** 二维数组测试类
 *定义一个用于测试数组的工具类。
 *随机生成二维数组每行长度
 *随机生成二维数组数值
 *@author 张三
 *@version V1.0
 */
import java.util.Random;
public class TestArray{
	/**
	生成数组
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
		return arr;    //返回引用
	}
	/**
	*输出至屏幕
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