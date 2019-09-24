// recoilCompensator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "Windows.h"
#include "WeaponSelector.h"
#include "chrono"

using namespace std;

WeaponSelector weaponSelector;
string activeWeapon;
double sensitivityInGame = 0.75;
// int screenWidth = 1920;
// int screenHeight = 1080;

static void updateActiveWeapon(void) {
	while (1) {
		activeWeapon = weaponSelector.activeWeapon; // new thread
		Sleep(1);
	}
}
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

void moveMouse(double time, double x, double y, double calibrationFactorX, double calibrationFactorY) {
	double dx = 3 * x / time;
	double dy = 3 * y / time;
	for (int i = 0; i < time / 3; i += 3) {
		mouse_event(MOUSEEVENTF_MOVE, (int)(dx * sensitivityInGame * calibrationFactorX), (int)(dy * sensitivityInGame * calibrationFactorY), 0, 0);
		sleep(3);
	}
}

void g7() {
	double calibrationFactorX = 1.6;
	double calibrationFactorY = 1.6;
	double delay = 225;
	while (1) { // consider using z key to break loop
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << activeWeapon << endl;
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouse(delay, 0, 80, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouse(delay, -10, 80, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			moveMouse(delay, 25, 90, calibrationFactorX, calibrationFactorY);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
		}
		if (activeWeapon != "g7") {
			break;
		}
		Sleep(1);
	}
}

void alternator() {
	double calibrationFactorX = 1.5;
	double calibrationFactorY = 4;
	double delay = 95; // try 93
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, 10, 24, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -10, 26, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 12, 27, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -13, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 8, 32, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -7, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 9, 28, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -10, 24, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -10, 22, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 22, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 0, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (activeWeapon != "alternator") {
			break;
		}
		Sleep(1);
	}
}

void r301() {
	double calibrationFactorX = 1.20;
	double calibrationFactorY = 1.20;
	double delay = 74;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, -15, 70, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -9, 80, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -25, 75, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -22, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -25, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -25, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -11, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 13, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 45, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 42, 14, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 35, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 35, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 23, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (activeWeapon != "r301") {
			break;
		}
		Sleep(1);
	}
}

void r99() {
	double calibrationFactorX = 1.70;
	double calibrationFactorY = 1.40;
	double delay = 45;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, 0, 25, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 49, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 35, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -12, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -12, 56, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -25, 68, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -35, 63, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 58, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -25, 41, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 5, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -25, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 32, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 70, 65, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 15, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, -1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -30, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -22, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (activeWeapon != "r99") {
			break;
		}
		Sleep(1);
	}
};

void spitfire() {
	double calibrationFactorX = 5.2;
	double calibrationFactorY = 4.6;
	double delay = 109;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, 4, 28, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 3, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 16, 19, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 8, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 11, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -1, 17, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -14, -1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -7, -2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -5, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -5, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 9, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 17, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 7, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 16, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 12, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 4, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 9, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 8, 8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 10, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 10, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 1, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -7, 4, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -15, 2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -13, 3, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -13, -8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -9, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -7, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -6, 3, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -6, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -7, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -5, 1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -4, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (activeWeapon != "spitfire") {
			break;
		}
		Sleep(1);
	}
}

void flatline() {
	double calibrationFactorX = 4.8;
	double calibrationFactorY = 4.8;
	double delay = 99;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, 3, 27, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 8, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 9, 23, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 6, 11, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 12, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 0, 14, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -8, 8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -12, 1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -6, -3, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -5, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, -4, 11, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 7, 7, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 14, 9, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 16, 2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 15, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 8, -2, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 7, 17, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 7, 17, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(delay, 8, 8, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
		}
		if (activeWeapon != "flatline") {
			break;
		}
		Sleep(1);
	}
}

void hemlock() {
	double calibrationFactorX = 10;
	double calibrationFactorY = 10;
	double delay = 66;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, 0, 11, calibrationFactorX, calibrationFactorY);
			moveMouse(delay, 0, 7, calibrationFactorX, calibrationFactorY);
			Sleep(2 * delay);
		}
		if (activeWeapon != "hemlock") {
			break;
		}
		Sleep(1);
	}
}

void prowler() { // remove conditional breaks, treat as 1 full auto loop per burst
	double calibrationFactorX = 10;
	double calibrationFactorY = 12.5;
	double delay = 50;
	while (1) {
		if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(delay, 0, 10, calibrationFactorX, calibrationFactorY);
			moveMouse(delay, 1, 10, calibrationFactorX, calibrationFactorY);
			moveMouse(delay, 1, 9, calibrationFactorX, calibrationFactorY);
			moveMouse(delay, 0, 9, calibrationFactorX, calibrationFactorY);
			Sleep(2 * delay);
		}
		if (activeWeapon != "prowler") {
			break;
		}
		Sleep(1);
	}
}

void insurgencyWeapon() { // F9
	cout << activeWeapon << endl;
	double calibrationFactorX = 0;
	double calibrationFactorY = 2.7;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			moveMouse(100, 0, 250, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(100, 0, 250, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			moveMouse(100, 0, 250, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			for (int i = 0, i < 20, i++) {
				moveMouse(100, 0, 150, calibrationFactorX, calibrationFactorY);
				if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			}
		}
		if (activeWeapon != "insurgencyWeapon") {
			break;
		}
		Sleep(1);
	}
}

void wingman() {
}

void none() {
	cout << activeWeapon << endl;
	while (1) {
		if (activeWeapon != "none") {
			break;
		}
		Sleep(1);
	}
}

int main() {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)updateActiveWeapon, 0, 0, 0);
	while (1) {
		if (activeWeapon == "g7") {
			g7();
		} else if (activeWeapon == "alternator") {
			alternator();
		} else if (activeWeapon == "r301") {
			r301();
		} else if (activeWeapon == "r99") {
			r99();
		} else if (activeWeapon == "spitfire") {
			spitfire();
		} else if (activeWeapon == "flatline") {
			flatline();
		} else if (activeWeapon == "hemlock") {
			hemlock();
		} else if (activeWeapon == "prowler") {
			prowler();
		} else if (activeWeapon == "insurgencyWeapon") {
			insurgencyWeapon();
		} else if (activeWeapon == "wingman") {
			wingman();
		} else if (activeWeapon == "none") {
			none();
		}
		Sleep(1);
	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
