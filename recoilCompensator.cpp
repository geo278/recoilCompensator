// recoilCompensator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "Windows.h"
#include "WeaponSelector.h"
#include "chrono"

using namespace std;

WeaponSelector weaponSelector;
string a;
double sensitivityInGame = 0.6;
int screenWidth = 1920;
int screenHeight = 1080;

static void updateActiveWeapon(void) {
	while (1) {
		a = weaponSelector.activeWeapon; // new thread
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

void moveMouse(double x, double y, double multiplier) {
	mouse_event(MOUSEEVENTF_MOVE, (int)(x * sensitivityInGame * multiplier), (int)(y * sensitivityInGame * multiplier), 0, 0);
	cout << "x: " << (x * sensitivityInGame * multiplier) << endl;
}

void g7() { // 230 ms gap
	double multiplier = 1.6;
	int delay = 195;
	while (1) { // better solution: just make the g7 full auto using inserted clicks
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
			cout << a << endl;
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(0, 80, multiplier);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(-10, 80, multiplier);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(30);
			moveMouse(25, 90, multiplier);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Left click
			Sleep(delay);
		}
		if (a != "g7") {
			break;
		}
		Sleep(10);
	}
}
void alternator() {}
void r301() { // 69 ms
	double multiplier = 1.20;
	int delay = 75;
	while (1) {
		while ((GetKeyState(VK_LBUTTON) & 0x100) != 0) { // while lmb pressed, do 1 full mag loop
			cout << a << endl;
			moveMouse(-15, 70, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-9, 80, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 75, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 45, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 35, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 30, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-8, 30, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-22, 20, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 20, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-25, 15, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(-11, 10, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(13, 10, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(45, 12, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(42, 14, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 10, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(35, 5, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
			moveMouse(23, -5, multiplier);
			if ((GetKeyState(VK_LBUTTON) & 0x100) == 0) { break; }
			Sleep(delay);
		}
		if (a != "r301") {
			break;
		}
		Sleep(10);
	}
}

void r99() {
};

void spitfire() {}
void flatline() {}
void hemlock() {}
void prowler() {}
void longbow() {}
void wingman() {}
void none() {
	cout << a << endl;
	while (1) {
		if (a != "none") {
			break;
		}
		Sleep(100);
	}
}

int main() {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)updateActiveWeapon, 0, 0, 0);

	while (1) {
		if (a == "g7") {
			g7();
		}
		else if (a == "alternator") {
			alternator();
		}
		else if (a == "r301") {
			r301();
		}
		else if (a == "r99") {
			r99();
		}
		else if (a == "spitfire") {
			spitfire();
		}
		else if (a == "flatline") {
			flatline();
		}
		else if (a == "hemlock") {
			hemlock();
		}
		else if (a == "prowler") {
			prowler();
		}
		else if (a == "longbow") {
			longbow();
		}
		else if (a == "wingman") {
			wingman();
		}
		else if (a == "none") {
			none();
		}
		else {
			Sleep(20);
		}
		Sleep(10);
	}

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
