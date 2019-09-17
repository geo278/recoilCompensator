// recoilCompensator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "Windows.h"
#include "WeaponSelector.h"
#include "chrono"

using namespace std;

WeaponSelector weaponSelector;
string activeWeapon;
double sensitivityInGame = 0.6;
int screenWidth = 1920;
int screenHeight = 1080;

static void updateActiveWeapon(void) {
	while (1) {
		activeWeapon = weaponSelector.activeWeapon; // new thread
		Sleep(10);
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

void moveMouse(double x, double y, double calibrationFactorX, double calibrationFactorY) {
	mouse_event(MOUSEEVENTF_MOVE, (int)(x * sensitivityInGame * calibrationFactorX), (int)(y * sensitivityInGame * calibrationFactorY), 0, 0);
}

void g7() {
	double calibrationFactorX = 1.6;
	double calibrationFactorY = 1.6;
	int delay = 195;
	while (1) { // consider using z key to break loop
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << activeWeapon << endl;
			Sleep(5);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(0, 80, calibrationFactorX, calibrationFactorY);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(-10, 80, calibrationFactorX, calibrationFactorY);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(25, 90, calibrationFactorX, calibrationFactorY);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(delay);
		}
		if (activeWeapon != "g7") {
			break;
		}
		Sleep(10);
	}
}

void alternator() {
	double calibrationFactorX = 1.5;
	double calibrationFactorY = 4;
	int delay = 96;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(10, 24, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(90);
			moveMouse(-10, 26, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(12, 27, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-13, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(8, 32, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-7, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(9, 28, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-10, 24, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-10, 22, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 22, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 18, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(0, 6, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
		}
		if (activeWeapon != "alternator") {
			break;
		}
		Sleep(10);
	}
}

void r301() {
	double calibrationFactorX = 1.20;
	double calibrationFactorY = 1.20;
	int delay = 75;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(-15, 70, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(75);
			moveMouse(-9, 80, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 75, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-22, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(13, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(45, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(42, 14, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 10, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(23, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
		}
		if (activeWeapon != "r301") {
			break;
		}
		Sleep(10);
	}
}

void r99() { // TESTING REQUIRED
	double calibrationFactorX = 1.70;
	double calibrationFactorY = 1.40;
	int delay = 45;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(0, 25, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 49, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-12, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-12, 56, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 68, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-35, 63, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 58, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 41, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(5, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(32, 55, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(70, 65, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(15, 12, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, -1, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-30, -5, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-22, 0, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
		}
		if (activeWeapon != "r99") {
			break;
		}
		Sleep(10);
	}
};

void spitfire() {
	double calibrationFactorX = 1.20;
	double calibrationFactorY = 1.20;
	int delay = 75;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(-11115, 70, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-9111, 80, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21115, 75, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8111, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21112, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-111125, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-211115, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11115, 70, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-9111, 80, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21115, 75, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8111, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21112, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-111125, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-211115, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11115, 70, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-9111, 80, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21115, 75, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 45, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 35, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8111, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21112, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-111125, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-211115, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-1118, 30, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21112, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-111125, 20, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-211115, 15, calibrationFactorX, calibrationFactorY);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
		}
		if (activeWeapon != "r301") {
			break;
		}
		Sleep(10);
	}
}

void flatline() {}

void hemlock() {}

void prowler() {}

void longbow() {}

void wingman() {}

void none() {
	cout << activeWeapon << endl;
	while (1) {
		if (activeWeapon != "none") {
			break;
		}
		Sleep(100);
	}
}

int main() {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)updateActiveWeapon, 0, 0, 0);
	while (1) {
		if (activeWeapon == "g7") {
			g7();
		}
		else if (activeWeapon == "alternator") {
			alternator();
		}
		else if (activeWeapon == "r301") {
			r301();
		}
		else if (activeWeapon == "r99") {
			r99();
		}
		else if (activeWeapon == "spitfire") {
			spitfire();
		}
		else if (activeWeapon == "flatline") {
			flatline();
		}
		else if (activeWeapon == "hemlock") {
			hemlock();
		}
		else if (activeWeapon == "prowler") {
			prowler();
		}
		else if (activeWeapon == "longbow") {
			longbow();
		}
		else if (activeWeapon == "wingman") {
			wingman();
		}
		else if (activeWeapon == "none") {
			none();
		}
		else {
			Sleep(20);
		}
		Sleep(10);
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
