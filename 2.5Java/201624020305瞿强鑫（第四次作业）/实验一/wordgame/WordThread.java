/***********************************************************************
 * Module:  WordThread.java
 ***********************************************************************/
import java.util.Random;
import java.awt.*;
import javax.swing.*;

public class WordThread extends Thread{
	//声明随机类的引用
	private Random rand = new Random();
	
	private char word;
	//Unicode编码中，19968～32320之间的汉字
	private static int startPosition = 19968;
	private static int endPosition = 32320;
	private static int sleepTime = 6000;//ms
	
	private JLabel com;
	
	private boolean endGame = false;
	
	//初始化
	public WordThread(JLabel com){
		this.com = com;
	}	
	
	//停止游戏方法
	public void stopGame() {
		endGame = true;
	}
	
	//开始游戏方法
	public void run() {
		int k = rand.nextInt(endPosition - startPosition) + startPosition;
		
		while( !endGame ) {
			word = (char)k;
			com.setText("" + word);
			
			try{
				sleep(sleepTime);
			}catch(InterruptedException e){}
			
			k = rand.nextInt(endPosition - startPosition) + startPosition;			
		}
	} 
}
