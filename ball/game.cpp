// ball.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	Console c1;
	c1.set_title(_T("un jeu"));
	c1.set_dimensions(60, 40);
	string s1(7,205);
	string s2(9, '=');
	string s3(1, 79);
	string s4(16, '=');
	string s5(20, '=');
	string s6(20, '=');
	string s7(21, '=');
	string s9(15, '=');
	string s10(8, '=');
	string s11(15, '=');
	string s8="Press ENTER to start!";
	string Abyss(224,' ');
	string lborder(25, 186);
	string lborder2(24, 186);
	string lcoin(1, 201);
	string rcoin(1, 187);
	string uborder(56, 205);
	string uborder2(54, 205);
	BodyManager bm1(Box(100, 100), c1);
	Body abyss("abyss", Box(56, 4), Position(1, 26), Abyss);
	Border leftBorder("leftBorder", Box(1,25), Position(1, 1), lborder, green);
	Border leftBorder2("leftBorder", Box(1, 24), Position(2, 2), lborder2, green);
	Border rightBorder("rightBorder", Box(1,25), Position(58, 1), lborder, green);
	Border rightBorder2("rightBorder", Box(1, 24), Position(57, 2), lborder2, green);
	Border leftCoin("leftCoin", Box(1, 1), Position(1, 0), lcoin, green);
	Border rightCoin("rightCoin", Box(1, 1), Position(58, 0), rcoin, green);
	Border leftCoin2("leftCoin", Box(1, 1), Position(2, 1), lcoin, green);
	Border rightCoin2("rightCoin", Box(1, 1), Position(57, 1), rcoin, green);
	Border upsideBorder("upsideBorder", Box(56,1), Position(2, 0), uborder, green);
	Border upsideBorder2("upsideBorder", Box(54, 1), Position(3, 1), uborder2, green);
	Barre barre("barre", Box(7, 1), Position(24, 24), s1 , dark_green);
	Ball ball("ball", Box(1, 1), Position(30, 23), s3, static_cast<short>(0), static_cast<short>(1), dark_yellow);
	Brique b1("brique", Box(4, 4), Position(6, 7), s4, default_color);
	Brique b2("brique", Box(7, 3), Position(4, 15), s7, default_color);
	Brique b3("brique", Box(5, 3), Position(38,8), s9, yellow);
	Brique b4("brique", Box(8, 1), Position(16, 10), s10, default_color);
	Brique b5("brique", Box(5, 4), Position(42, 16), s6, default_color);
	Brique b6("brique", Box(3, 3), Position(28, 7), s2, blue);
	Mbrique b7("brique", Box(15, 1), Position(4, 5), s11, red);
	bm1.addBody(leftBorder);
	bm1.addBody(leftBorder2);
	bm1.addBody(rightBorder);
	bm1.addBody(rightBorder2);
	bm1.addBody(leftCoin);
	bm1.addBody(rightCoin);
	bm1.addBody(leftCoin2);
	bm1.addBody(rightCoin2);
	bm1.addBody(upsideBorder);
	bm1.addBody(upsideBorder2);
	bm1.addBody(barre);
	bm1.addBody(ball);
	bm1.addBody(b1);
	bm1.addBody(b2);
	bm1.addBody(b3);
	bm1.addBody(b4);
	bm1.addBody(b5);
	bm1.addBody(b6);
	bm1.addBody(b7);
	bm1.addBody(abyss);
	c1.put_string(s8, 20, 20);
	c1.set_hide_cursor();
	char b = getchar();
	c1.clear();
	bm1.run();
	c1.set_hide_cursor();
	char c = getchar();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
