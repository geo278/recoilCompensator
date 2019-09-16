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

void moveMouse(double x, double y, double calibrationFactor) {
	mouse_event(MOUSEEVENTF_MOVE, (int)(x * sensitivityInGame * calibrationFactor), (int)(y * sensitivityInGame * calibrationFactor), 0, 0);
	cout << "x: " << (x * sensitivityInGame * calibrationFactor) << endl;
}

void g7() {
	double calibrationFactor = 1.6;
	int delay = 195;
	while (1) { // consider using z key to break loop
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << activeWeapon << endl;
			Sleep(5);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(0, 80, calibrationFactor);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(-10, 80, calibrationFactor);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(25, 90, calibrationFactor);
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

void alternator() { // TESTING REQUIRED
	double calibrationFactor = 1.40;
	int delay = 94;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(14, 24, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11, 28, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(15, 22, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-13, 20, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(15, 23, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-18, 26, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(14, 26, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21, 22, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(8, 30, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 16, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(19, 17, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-21, 9, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(12, 14, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-15, 12, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(20, 30, calibrationFactor);
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
	double calibrationFactor = 1.20;
	int delay = 75;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(-15, 70, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-9, 80, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 75, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 45, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 35, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 30, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 30, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-22, 20, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 20, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 15, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11, 10, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(13, 10, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(45, 12, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(42, 14, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 10, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 5, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(23, -5, calibrationFactor);
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
	double calibrationFactor = 1.50;
	int delay = 45;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << activeWeapon << endl;
			Sleep(5);
			moveMouse(0, 25, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-13, 54, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(30, 39, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-20, 64, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11, 56, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-33, 71, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-27, 63, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 58, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(5, 41, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(14, 55, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(29, 45, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(13, 59, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(8, 33, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(4, 28, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-35, 9, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-23, 0, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-16, 16, calibrationFactor);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
		}
		if (activeWeapon != "r99") {
			break;
		}
		Sleep(10);
	}
};

void spitfire() {}

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
		switch(activeWeapon) {
			case "g7" : g7();
			case "alternator" : alternator();
			case "r301" : r301();
			case "r99" : r99();
			case "spitfire" : spitfire();
			case "flatline" : flatline();
			case "hemlock" : hemlock();
			case "prowler" : prowler();
			case "longbow" : longbow();
			case "wingman" : wingman();
			case "none" : none();
		}
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
