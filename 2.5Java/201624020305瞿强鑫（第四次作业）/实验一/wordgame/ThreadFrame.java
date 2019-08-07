/***********************************************************************
 * Module:  ThreadFrame.java
 ***********************************************************************/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ThreadFrame extends JFrame {

	//组件
	private JLabel wordLabel;
	private JButton startButton;
	private JTextField inputText, scoreText;
	
	//在ThreadFrame内部属性中声明WordThread的引用
	private WordThread giveWord;
	
	//计分
	private int score = 0;
	
	//初始化
	public ThreadFrame() {
		
		wordLabel = new JLabel(" ", JLabel.CENTER);
		wordLabel.setFont(new Font("", Font.BOLD,72));
		
		startButton = new JButton("开始");
		
		inputText = new JTextField(3);
		scoreText = new JTextField(5);
		scoreText.setEditable(false); 
		
		giveWord = new WordThread(wordLabel);
		
		//实现StartButtonActionListener匿名内部类
		startButton.addActionListener( new ActionListener() {            //ActionListener接口的实现
				public void actionPerformed(ActionEvent e) {
					if( !(giveWord.isAlive()) ) { 
						giveWord = new WordThread(wordLabel);
						giveWord.start();
					}
				}
		});		
		//实现InputTextActionListener匿名内部类
		inputText.addActionListener( new ActionListener(){
				public void actionPerformed(ActionEvent e) {
					if( inputText.getText().equals(wordLabel.getText()) ) {    //ActionListener接口的实现
						score++;
					}
					scoreText.setText("得分:" + score);
					inputText.setText(null);
				}
		} );
		
		add(startButton, BorderLayout.NORTH);
		add(wordLabel, BorderLayout.CENTER);
		
		JPanel southP = new JPanel();
		southP.add( new JLabel("输入汉字后回车:") );
		southP.add(inputText);
		southP.add(scoreText);
		add(southP, BorderLayout.SOUTH);
		
		//设置面框架大小、可视化
		setBounds(100,100,250,180);
		setVisible(true);
		validate();
		
		//添加WindowsLinster
		addWindowListener(
				new WindowAdapter() { 
					public void windowClosing(WindowEvent e) {
						giveWord.stopGame();
						
						setVisible(false);
						System.exit(0);
				}
				}
		);
	}
	/*
	class StartButtonActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			if( !(giveWord.isAlive()) ) { 
				giveWord = new WordThread(wordLabel);
				giveWord.start();
			}
		}
	}
	
	class InputTextActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			if( inputText.getText().equals(wordLabel.getText()) ) {
				score++;
			}
			scoreText.setText("得分:" + score);
			inputText.setText(null);
		}
	}
	*/
	
}
