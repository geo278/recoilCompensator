#include "WeaponSelector.h"

string WeaponSelector::slot1;
string WeaponSelector::slot2;
string WeaponSelector::activeSlot;
string WeaponSelector::activeWeapon;
bool WeaponSelector::useSlotSwitchKeybinds;
bool WeaponSelector::toggleActive;

WeaponSelector::WeaponSelector() {
	slot1 = "none";
	slot2 = "none";
	activeSlot = "none";
	activeWeapon = slot1;
	useSlotSwitchKeybinds = true;
	toggleActive = true;
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE) WeaponSelector::trackSlot, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE) WeaponSelector::trackWeapon, 0, 0, 0);
}

void WeaponSelector::trackSlot(void) {
	while (1) {
		if (GetAsyncKeyState('1') & 1) {
			activeSlot = "slot1";
			activeWeapon = slot1;
			cout << "slot1 selected: " << slot1 << endl;
		} 
		else if (GetAsyncKeyState('2') & 1)	{
			activeSlot = "slot2";
			activeWeapon = slot2;
			cout << "slot2 selected: " << slot2 << endl;
		}
		else if (useSlotSwitchKeybinds && (
				// (GetAsyncKeyState('3') & 1) || 
				// (GetAsyncKeyState('4') & 1) || 
				// (GetAsyncKeyState('E') & 1) || 
				(GetAsyncKeyState(VK_ESCAPE) & 1) 
				// (GetAsyncKeyState(VK_TAB) & 1)
			)) {
			activeSlot = "none";
			activeWeapon = "none";
			cout << "none selected" << endl;
		}
		if (!useSlotSwitchKeybinds && (GetAsyncKeyState(0xBD) & 1)) { // activate using - key
			toggleActive = !toggleActive;
			cout << "toggleActive: " << toggleActive << endl;
			Sleep(25);
		}
		Sleep(1);
	}
}
void WeaponSelector::selectWeapon(string weapon) {
	if (activeSlot == "slot1") {
		slot1 = weapon;
		activeWeapon = slot1;
	}
	else if (activeSlot == "slot2") {
		slot2 = weapon;
		activeWeapon = slot2;
	}
	else if (activeSlot == "none") {
		activeWeapon = "none";
	}
}
void WeaponSelector::trackWeapon(void) {
	while (1) {
		if (GetAsyncKeyState(VK_F1) & 1) {
			//selectWeapon("g7");
			selectWeapon("ps2ESF"); 
		}
		else if (GetAsyncKeyState(VK_F2) & 1) {
			selectWeapon("alternator");
		}
		else if (GetAsyncKeyState(VK_F3) & 1) {
			selectWeapon("r6SMG11");
			// selectWeapon("r301");
		}
		else if (GetAsyncKeyState(VK_F4) & 1) {
			selectWeapon("r6LMGControl");
			// selectWeapon("r99");
		}
		else if (GetAsyncKeyState(VK_F5) & 1) {
			selectWeapon("r6HighCapacitySniper");
			// selectWeapon("spitfire");
		}
		else if (GetAsyncKeyState(VK_F6) & 1) {
			selectWeapon("r6BurstDEF"); 
			// selectWeapon("flatline");
		}
		else if (GetAsyncKeyState(VK_F7) & 1) {
			selectWeapon("bumpStockBF4");
			// selectWeapon("hemlock");
		}
		else if (GetAsyncKeyState(VK_F8) & 1) {
			selectWeapon("insurgencyBumpStock");
			// selectWeapon("prowler");
		}
		else if (GetAsyncKeyState(VK_F9) & 1) {
			selectWeapon("insurgencySemiAuto");
			// selectWeapon("krunkerMarksman");
			// selectWeapon("m16a2");
		}
		else if (GetAsyncKeyState(VK_F10) & 1) {
			selectWeapon("insurgencyFullAuto");
			// selectWeapon("m16a4");
			// selectWeapon("gaussSAW");
		}
		else if (GetAsyncKeyState(VK_F12) & 1) {
			selectWeapon("none");
		}
		Sleep(1);
	}
}
