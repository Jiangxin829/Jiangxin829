/***********************************************************************
 * Module:  ThreadFrame.java
 ***********************************************************************/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ThreadFrame extends JFrame {

	//���
	private JLabel wordLabel;
	private JButton startButton;
	private JTextField inputText, scoreText;
	
	//��ThreadFrame�ڲ�����������WordThread������
	private WordThread giveWord;
	
	//�Ʒ�
	private int score = 0;
	
	//��ʼ��
	public ThreadFrame() {
		
		wordLabel = new JLabel(" ", JLabel.CENTER);
		wordLabel.setFont(new Font("", Font.BOLD,72));
		
		startButton = new JButton("��ʼ");
		
		inputText = new JTextField(3);
		scoreText = new JTextField(5);
		scoreText.setEditable(false); 
		
		giveWord = new WordThread(wordLabel);
		
		//ʵ��StartButtonActionListener�����ڲ���
		startButton.addActionListener( new ActionListener() {            //ActionListener�ӿڵ�ʵ��
				public void actionPerformed(ActionEvent e) {
					if( !(giveWord.isAlive()) ) { 
						giveWord = new WordThread(wordLabel);
						giveWord.start();
					}
				}
		});		
		//ʵ��InputTextActionListener�����ڲ���
		inputText.addActionListener( new ActionListener(){
				public void actionPerformed(ActionEvent e) {
					if( inputText.getText().equals(wordLabel.getText()) ) {    //ActionListener�ӿڵ�ʵ��
						score++;
					}
					scoreText.setText("�÷�:" + score);
					inputText.setText(null);
				}
		} );
		
		add(startButton, BorderLayout.NORTH);
		add(wordLabel, BorderLayout.CENTER);
		
		JPanel southP = new JPanel();
		southP.add( new JLabel("���뺺�ֺ�س�:") );
		southP.add(inputText);
		southP.add(scoreText);
		add(southP, BorderLayout.SOUTH);
		
		//�������ܴ�С�����ӻ�
		setBounds(100,100,250,180);
		setVisible(true);
		validate();
		
		//���WindowsLinster
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
			scoreText.setText("�÷�:" + score);
			inputText.setText(null);
		}
	}
	*/
	
}
