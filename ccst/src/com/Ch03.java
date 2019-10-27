package com;

import java.util.Scanner;

public class Ch03 {
/**
 * 运算符
 * 1、算数运算符
 * + - * \ %
 * 2、自增运算符  自减运算符
 * ++i 先加  后参与运算
 * i++ 先参与运算 在加
 * --i i--
 * 3、关系运算符
 * > < >= <= == !=
 * 4、逻辑运算符
 * && 且  条件全部满足
 * || 或  满足任意条件
 * !  非  都不满足
 * 5、赋值运算符
 * =    int a =b 
 * 6、二目运算符
 *  isTrue? true:false
 * 7、位运算符
 *   a^b
 */
	public static void main(String[] args) {
		/**
		 * 程序控制语句   逻辑思维   因   果
		 */
		/**
		 * 1、条件语句   if-else   如果  否则
		 */
//		Scanner sc = new Scanner(System.in);
//		System.out.println("欢迎登录食堂外卖系统!");
//		System.out.println("请输入用户名:");
//		String username = sc.next();
//		System.out.println("请输入密码:");
//		String password = sc.next();
//		
//		String sysname = "admin1";
//		String syspwd = "123456";
//		/**
//		 * 判断是否相等             ==       equals
//		 * ==  判断两个值是否相等      附带判断两个变量的地址符是否相等    int a = 5; int b= 10;
//		 * == 判断基础数据类型的值是否相等   
//		 * equals 判断两个对象的值是否相等   String 对象数据类型  引用数据类型
//		 */
//		if(username.equals(sysname) && password.equals(syspwd))
//		{
//			System.out.println("欢迎您登录!!!");
//		}
//		else
//		{
//			System.out.println("帐号或密码输入错误！请重新输入!!");
//		}
		/**
		 *  else if  
		 */
		/**
		 * 分支选择语句    switch 开关  
//		 */
//		int a = 3;
//		char c='a';
//		switch (c) {
//		case 'a':
//			System.out.println("第一排卧倒");
//			break;
//		case 'b':
//			System.out.println("第二排卧倒");
//			break;
//			//default 默认  可忽略
//		default:
//			System.out.println("全体卧倒");
//			break;
//		}
//		
		/**
		 * 循环   
		 */
		/**
		 * for   
		 */
//		for (int i = 0; i < 10; i++) {
//			System.out.println(i);
//		}
		/**
		 * while   超级玛丽   
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
//		 * do while  魂斗罗  开心消消乐
//		 */
//		int life2 = 3;
//		do {
//			System.out.println("play");
//			life2--;
//		} while (life2>0);
//		System.out.println("game over");
		/**
		 *  break终止当前循环     continue终止本次循环  
		 */
		for (int i = 1; i <= 10; i++) {
			
			if(i%3==0)
			{
				System.out.println("钓到3斤大鱼");
				System.out.println("够本回家！");
				//break;
				continue;
			}
			System.out.println("钓鱼次数"+i);
		}
	}
}
