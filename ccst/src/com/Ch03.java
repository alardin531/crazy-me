package com;

import java.util.Scanner;

public class Ch03 {
/**
 * �����
 * 1�����������
 * + - * \ %
 * 2�����������  �Լ������
 * ++i �ȼ�  ���������
 * i++ �Ȳ������� �ڼ�
 * --i i--
 * 3����ϵ�����
 * > < >= <= == !=
 * 4���߼������
 * && ��  ����ȫ������
 * || ��  ������������
 * !  ��  ��������
 * 5����ֵ�����
 * =    int a =b 
 * 6����Ŀ�����
 *  isTrue? true:false
 * 7��λ�����
 *   a^b
 */
	public static void main(String[] args) {
		/**
		 * ����������   �߼�˼ά   ��   ��
		 */
		/**
		 * 1���������   if-else   ���  ����
		 */
//		Scanner sc = new Scanner(System.in);
//		System.out.println("��ӭ��¼ʳ������ϵͳ!");
//		System.out.println("�������û���:");
//		String username = sc.next();
//		System.out.println("����������:");
//		String password = sc.next();
//		
//		String sysname = "admin1";
//		String syspwd = "123456";
//		/**
//		 * �ж��Ƿ����             ==       equals
//		 * ==  �ж�����ֵ�Ƿ����      �����ж����������ĵ�ַ���Ƿ����    int a = 5; int b= 10;
//		 * == �жϻ����������͵�ֵ�Ƿ����   
//		 * equals �ж����������ֵ�Ƿ����   String ������������  ������������
//		 */
//		if(username.equals(sysname) && password.equals(syspwd))
//		{
//			System.out.println("��ӭ����¼!!!");
//		}
//		else
//		{
//			System.out.println("�ʺŻ����������������������!!");
//		}
		/**
		 *  else if  
		 */
		/**
		 * ��֧ѡ�����    switch ����  
//		 */
//		int a = 3;
//		char c='a';
//		switch (c) {
//		case 'a':
//			System.out.println("��һ���Ե�");
//			break;
//		case 'b':
//			System.out.println("�ڶ����Ե�");
//			break;
//			//default Ĭ��  �ɺ���
//		default:
//			System.out.println("ȫ���Ե�");
//			break;
//		}
//		
		/**
		 * ѭ��   
		 */
		/**
		 * for   
		 */
//		for (int i = 0; i < 10; i++) {
//			System.out.println(i);
//		}
		/**
		 * while   ��������   
		 * 
		 */
//		int life = 3;
//		while(life>0)
//		{
//			System.out.println("play");
//			life--;
//		}
//		System.out.println("game over");
//		/** 
//		 * do while  �궷��  ����������
//		 */
//		int life2 = 3;
//		do {
//			System.out.println("play");
//			life2--;
//		} while (life2>0);
//		System.out.println("game over");
		/**
		 *  break��ֹ��ǰѭ��     continue��ֹ����ѭ��  
		 */
		for (int i = 1; i <= 10; i++) {
			
			if(i%3==0)
			{
				System.out.println("����3�����");
				System.out.println("�����ؼң�");
				//break;
				continue;
			}
			System.out.println("�������"+i);
		}
	}
}
