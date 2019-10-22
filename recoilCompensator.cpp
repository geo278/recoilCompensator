// recoilCompensator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "iostream"
#include "Windows.h"
#include "WeaponSelector.h"
#include "chrono"

using namespace std;

WeaponSelector weaponSelector;
double sensitivityInGame = 0.75;
// int screenWidth = 1920;
// int screenHeight = 1080;

void timerTool() {
	bool timed = false;
	auto start = chrono::steady_clock::now();
	while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
		Sleep(1);
		timed = true;
	}
	auto end = chrono::steady_clock::now();
	if (timed == true) {
		cout << "elapsed time in ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
	}
}

void moveMouse(double x, double y, double calibrationFactorX, double calibrationFactorY) {
	mouse_event(MOUSEEVENTF_MOVE, (int)(x * sensitivityInGame * calibrationFactorX), (int)(y * sensitivityInGame * calibrationFactorY), 0, 0);
}
void moveMouseSmoothly(double time, double x, double y, double calibrationFactorX, double calibrationFactorY) {
	double dx = 20 * x / time;
	double dy = 20 * y / time;
	double remainingTime = time;
	for (int i = 0; i < time / 20; i++) {
		mouse_event(MOUSEEVENTF_MOVE, (int)(dx * sensitivityInGame * calibrationFactorX), (int)(dy * sensitivityInGame * calibrationFactorY), 0, 0);
		Sleep(20);
		remainingTime -= 20;
	}
	if (remainingTime > 0) {
		Sleep((int)remainingTime);
	}
}

void ps2ESF() {
	weaponSelector.useSlotSwitchKeybinds = false;
	double calibrationFactorX = 0;
	double calibrationFactorY = 0.025;
	while (1) {
		if (((GetKeyState(VK_SHIFT) & 0x100) != 0) && (((GetKeyState(VK_SPACE) & 0x100) != 0))) { //
			mouse_event(MOUSEEVENTF_MOVE, 0, 2, 0, 0);
		} else { //
			mouse_event(MOUSEEVENTF_MOVE, 0, 1, 0, 0);
		}
		Sleep(30);
	}
}

void g7() {
	double calibrationFactorX = 1.65;
	double calibrationFactorY = 1.50;
	int delay = 195;
	while (1) { // consider using key to break loop
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << weaponSelector.activeWeapon << endl;
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouseSmoothly(delay, 0, 80, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouseSmoothly(delay, -10, 80, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouseSmoothly(delay, 25, 90, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
		}
		if (weaponSelector.activeWeapon != "g7") {
			break;
		}
		Sleep(1);
	}
}

void alternator() {
	double calibrationFactorX = 1.5;
	double calibrationFactorY = 3.6;
	int delay = 95; //
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 10, 24, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -10, 26, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 12, 27, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -13, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, 32, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -7, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 9, 28, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -10, 24, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -10, 22, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -15, 22, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -15, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -15, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -15, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -15, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 0, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (weaponSelector.activeWeapon != "alternator") {
			break;
		}
		Sleep(1);
	}
}

void r301() {
	double calibrationFactorX = 1.40;
	double calibrationFactorY = 1.00;
	int delay = 74;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, -15, 70, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -9, 80, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -25, 75, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -22, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -25, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -25, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -9, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 15, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 45, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 42, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 37, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 37, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 23, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (weaponSelector.activeWeapon != "r301") {
			break;
		}
		Sleep(1);
	}
}

void r99() {
	double calibrationFactorX = 1.70;
	double calibrationFactorY = 0.95;
	int delay = 45;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 0, 25, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 49, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 35, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -12, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -12, 56, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -25, 68, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -25, 63, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -5, 58, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 0, 41, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 0, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 0, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 12, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 15, 65, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -18, -1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -30, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -22, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (weaponSelector.activeWeapon != "r99") {
			break;
		}
		Sleep(1);
	}
};

void spitfire() {
	double calibrationFactorX = 5.2;
	double calibrationFactorY = 4.3;
	int delay = 109;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 4, 28, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 3, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 16, 19, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 11, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -1, 17, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -14, -1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -7, -2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -5, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -5, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 9, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 17, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 7, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 16, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 12, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 4, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 9, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, 8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 10, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 10, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 1, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -7, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -15, 2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -13, 3, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -13, -8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -9, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -7, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -6, 3, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -6, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -7, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -5, 1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -4, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (weaponSelector.activeWeapon != "spitfire") {
			break;
		}
		Sleep(1);
	}
}

void flatline() {
	double calibrationFactorX = 4.8;
	double calibrationFactorY = 4.5;
	int delay = 99;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 3, 27, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 9, 23, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 6, 11, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 12, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 0, 14, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -8, 8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -12, 1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -6, -3, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -5, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, -4, 11, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 7, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 14, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 16, 2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 15, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, -2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 7, 17, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 7, 17, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(delay, 8, 8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (weaponSelector.activeWeapon != "flatline") {
			break;
		}
		Sleep(1);
	}
}

void hemlock() {
	double calibrationFactorX = 10;
	double calibrationFactorY = 8.8;
	int delay = 66;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 0, 11, calibrationFactorX, calibrationFactorY);
			moveMouseSmoothly(delay, 0, 7, calibrationFactorX, calibrationFactorY);
			Sleep(2 * delay);
		}
		if (weaponSelector.activeWeapon != "hemlock") {
			break;
		}
		Sleep(1);
	}
}

void prowler() { //
	double calibrationFactorX = 10;
	double calibrationFactorY = 9;
	int delay = 50;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 0, 10, calibrationFactorX, calibrationFactorY);
			moveMouseSmoothly(delay, 1, 10, calibrationFactorX, calibrationFactorY);
			moveMouseSmoothly(delay, 1, 9, calibrationFactorX, calibrationFactorY);
			moveMouseSmoothly(delay, 0, 9, calibrationFactorX, calibrationFactorY);
			Sleep(2 * delay);
		}
		if (weaponSelector.activeWeapon != "prowler") {
			break;
		}
		Sleep(1);
	}
}

void m16a2() {
	double calibrationFactorX = 5;
	double calibrationFactorY = 13.7;
	int delay = 155;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 0, 60, calibrationFactorX, calibrationFactorY);
			moveMouseSmoothly(delay, -2, 50, calibrationFactorX, calibrationFactorY);
		}
		if (weaponSelector.activeWeapon != "m16a2") {
			break;
		}
		Sleep(1);
	}
}
void m16a4() {
	double calibrationFactorX = 5;
	double calibrationFactorY = 12.5;
	int delay = 130;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << weaponSelector.activeWeapon << endl;
			Sleep(5);
			moveMouseSmoothly(delay, 0, 60, calibrationFactorX, calibrationFactorY);
			moveMouseSmoothly(delay, 0, 50, calibrationFactorX, calibrationFactorY);
		}
		if (weaponSelector.activeWeapon != "m16a4") {
			break;
		}
		Sleep(1);
	}
}

void gaussSAW() {
	double calibrationFactorX = 1;
	double calibrationFactorY = 3;
	int delay = 115;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { //
			cout << weaponSelector.activeWeapon << endl;
			Sleep(1);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(10);
			moveMouseSmoothly(delay, 0, 70, calibrationFactorX, calibrationFactorY);

			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(10);
			moveMouseSmoothly(delay, 0, 50, calibrationFactorX, calibrationFactorY);

			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(10);
			moveMouseSmoothly(delay, 0, 50, calibrationFactorX, calibrationFactorY);

			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(10);

		}
		if (weaponSelector.activeWeapon != "gaussSAW") {
			break;
		}
		Sleep(1);
	}
}

void krunkerMarksman() {
	double calibrationFactorX = 1;
	double calibrationFactorY = 2;
	int delay = 110;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // if lmb pressed, do 4 round burst
			cout << weaponSelector.activeWeapon << endl;
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouseSmoothly(delay, 0, 70, calibrationFactorX, calibrationFactorY);

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //
			Sleep(5);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouseSmoothly(delay, 0, 70, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //
			Sleep(5);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouseSmoothly(delay, 0, 70, calibrationFactorX, calibrationFactorY);

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //
			Sleep(5);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouseSmoothly(delay, 0, -210, calibrationFactorX, calibrationFactorY);
		}
		if (weaponSelector.activeWeapon != "krunkerMarksman") {
			break;
		}
		Sleep(1);
	}
}

static void performLayeredRecoilCompensation1(void) {
	double calibrationFactorX = 0;
	double calibrationFactorY = 6;
	moveMouseSmoothly(40, 0, 40, calibrationFactorX, calibrationFactorY);
	moveMouseSmoothly(55, 0, 15, calibrationFactorX, calibrationFactorY);
	moveMouseSmoothly(125, 0, -28, calibrationFactorX, calibrationFactorY);
}
void insurgencySemiAuto() { // F9
	weaponSelector.useSlotSwitchKeybinds = false;
	cout << weaponSelector.activeWeapon << endl;
	while (1) {
		if (((GetKeyState(VK_LBUTTON) & 0x100) != 0) && ((GetKeyState(VK_SHIFT) & 0x100) == 0)) { //
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)performLayeredRecoilCompensation1, 0, 0, 0);
			while (((GetKeyState(VK_LBUTTON) & 0x100) != 0)) {
				Sleep(5);
			}
		}
		Sleep(1);
	}
}

void insurgencyFullAuto() { // F10
	weaponSelector.useSlotSwitchKeybinds = false;
	cout << weaponSelector.activeWeapon << endl;
	double calibrationFactorX = 0;
	double calibrationFactorY = 4;
	bool firstShots = true;
	while (1) {
		while (((GetKeyState(VK_LBUTTON) & 0x100) != 0) && ((GetKeyState(VK_SHIFT) & 0x100) == 0)) { //
			Sleep(10);
			while (firstShots) {
				moveMouseSmoothly(200, 0, 185, calibrationFactorX, calibrationFactorY);
				if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
				moveMouseSmoothly(200, 0, 180, calibrationFactorX, calibrationFactorY);
				firstShots = false;
			}
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouseSmoothly(200, 0, 135, calibrationFactorX, calibrationFactorY);
		}
		firstShots = true;
		Sleep(1);
	}
}

static void performLayeredRecoilCompensation2x762(void) {
	double calibrationFactorX = 0;
	double calibrationFactorY = 15;
	int delay = 16;
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(7.3 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(3.7 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(2.8 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(2.6 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(2.6 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(1.4 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(0.4 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(-1.1 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(-2 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(-2 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(-2 * calibrationFactorY), 0, 0);
	Sleep(delay);
	mouse_event(MOUSEEVENTF_MOVE, 0, (int)(-2.8 * calibrationFactorY), 0, 0);
	Sleep(delay);
}
void insurgencyBumpStock() { // F8
	weaponSelector.useSlotSwitchKeybinds = false;
	cout << weaponSelector.activeWeapon << endl;
	INPUT _0_keyDown;
	_0_keyDown.type = INPUT_KEYBOARD;
	_0_keyDown.ki.wScan = 0; // hardware scan code
	_0_keyDown.ki.time = 0;
	_0_keyDown.ki.dwExtraInfo = GetMessageExtraInfo();
	_0_keyDown.ki.wVk = 0x30; // virtual-key code
	_0_keyDown.ki.dwFlags = 0; // 0 for key down
	INPUT _0_keyUp = _0_keyDown;
	_0_keyUp.ki.dwFlags = KEYEVENTF_KEYUP;
	while (1) {
		if (((GetKeyState(VK_LBUTTON) & 0x100) != 0) && ((GetKeyState(VK_SHIFT) & 0x100) == 0)) { //
			SendInput(1, &_0_keyDown, sizeof(INPUT));
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)performLayeredRecoilCompensation2x762, 0, 0, 0);
			Sleep(90);
			SendInput(1, &_0_keyUp, sizeof(INPUT));
			Sleep(89);
		}
		Sleep(1);
	}
}

void none() {
	cout << weaponSelector.activeWeapon << endl;
	while (1) {
		if (weaponSelector.activeWeapon != "none") {
			break;
		}
		Sleep(1);
	}
}

int main() {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)updateActiveWeapon, 0, 0, 0);
	while (1) {
		if (weaponSelector.activeWeapon == "g7") {
			g7();
		} else if (weaponSelector.activeWeapon == "alternator") {
			alternator();
		} else if (weaponSelector.activeWeapon == "r301") {
			r301();
		} else if (weaponSelector.activeWeapon == "r99") {
			r99();
		} else if (weaponSelector.activeWeapon == "spitfire") {
			spitfire();
		} else if (weaponSelector.activeWeapon == "flatline") {
			flatline();
		} else if (weaponSelector.activeWeapon == "hemlock") {
			hemlock();
		} else if (weaponSelector.activeWeapon == "prowler") {
			prowler();
		} else if (weaponSelector.activeWeapon == "insurgencySemiAuto") {
			insurgencySemiAuto();
		} else if (weaponSelector.activeWeapon == "insurgencyFullAuto") {
			insurgencyFullAuto(); 
		} else if (weaponSelector.activeWeapon == "insurgencyBumpStock") {
			insurgencyBumpStock();
		} else if (weaponSelector.activeWeapon == "m16a2") {
			m16a2();
		} else if (weaponSelector.activeWeapon == "m16a4") {
			m16a4();
		} else if (weaponSelector.activeWeapon == "gaussSAW") {
			gaussSAW();
		} else if (weaponSelector.activeWeapon == "krunkerMarksman") {
			krunkerMarksman();
		} else if (weaponSelector.activeWeapon == "ps2ESF") {
			ps2ESF();
		} else if (weaponSelector.activeWeapon == "none") {
			none();
		}
		Sleep(1);
	}
	return 0;
}
