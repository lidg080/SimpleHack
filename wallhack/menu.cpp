#include <iostream>
#include <string>
#include <Windows.h>
#include <WinBase.h>
#include <TlHelp32.h>
#include <vector>
#include "menu.h"

void c_menu::printMenu() { //prints menu stuff
	using namespace std;

	system("cls"); // clears all lines
	cout << "TOM external!" << "\n ----- " << endl;
	cout << "小键盘1 透视(仅敌人) / ";
	if (glow == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n小键盘2 连跳 / ";
	if (bhop == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n小键盘3 自动扳机 / ";
	if (trigger == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n小键盘4 宽视野 / ";
	if (fov == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n小键盘5 透视(吃鸡专用) / ";
	if (glow2 == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n小键盘6 无视闪光 / ";
	if (noflash == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n小键盘7 假延迟 / ";
	if (fakelag == true) {
		cout << " 开启!\n";
	}
	else {
		cout << " 关闭!\n";
	}

	cout << "\n辅助处于测试版本阶段,有些功能不够完善.";
}

void c_menu::main() { // main menu func
	using namespace std;


	if (GetAsyncKeyState(VK_NUMPAD1)) { // toggles glow w/ f1
		glow = !glow; // reverses current state
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}

	if (GetAsyncKeyState(VK_NUMPAD2)) { // toggles bhop w/ f2
		bhop = !bhop; // reverses current state
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}

	if (GetAsyncKeyState(VK_NUMPAD3)) {
		trigger = !trigger;
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}

	if (GetAsyncKeyState(VK_NUMPAD4)) {
		fov = !fov;
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}

	if (GetAsyncKeyState(VK_NUMPAD5)) {
		glow2 = !glow2;
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}

	if (GetAsyncKeyState(VK_NUMPAD6)) {
		noflash = !noflash;
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}

	if (GetAsyncKeyState(VK_NUMPAD7)) {
		fakelag = !fakelag;
		printMenu();
		Beep(1000, 200);
		Sleep(100);
	}
}

