#include "WeaponSelector.h"

		string WeaponSelector::slot1;
		string WeaponSelector::slot2;
		bool WeaponSelector::slot1Active;
		string WeaponSelector::activeWeapon;

		WeaponSelector::WeaponSelector() {
			slot1 = "g7";
			slot2 = "r301";
			slot1Active = true;
			activeWeapon = slot1;
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE) WeaponSelector::trackSlot, 0, 0, 0);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE) WeaponSelector::trackWeapon, 0, 0, 0);
		}

		void WeaponSelector::trackSlot(void) {
			while (1) {
				if (GetAsyncKeyState('1') & 1)
				{
					slot1Active = true;
					activeWeapon = slot1;
					cout << "slot1 selected" << endl;
				} 
				else if (GetAsyncKeyState('2') & 1)
				{
					slot1Active = false;
					activeWeapon = slot2;
					cout << "slot2 selected" << endl;
				}
				Sleep(10);
			}
		}
		string WeaponSelector::selectWeapon(string weapon) {
			if (slot1Active) {
				slot1 = weapon;
				activeWeapon = slot1;
			}
			else {
				slot2 = weapon;
				activeWeapon = slot2;
			}
			return activeWeapon;
		}
		void WeaponSelector::trackWeapon(void) {
			while (1) {
				if (GetAsyncKeyState(VK_F1) & 1) {
					selectWeapon("g7");
				}
				else if (GetAsyncKeyState(VK_F2) & 1) {
					selectWeapon("alternator");
				}
				else if (GetAsyncKeyState(VK_F3) & 1) {
					selectWeapon("r301");
				}
				else if (GetAsyncKeyState(VK_F4) & 1) {
					selectWeapon("r99");
				}
				else if (GetAsyncKeyState(VK_F5) & 1) {
					selectWeapon("spitfire");
				}
				else if (GetAsyncKeyState(VK_F6) & 1) {
					selectWeapon("flatline");
				}
				else if (GetAsyncKeyState(VK_F7) & 1) {
					selectWeapon("hemlock");
				}
				else if (GetAsyncKeyState(VK_F8) & 1) {
					selectWeapon("prowler");
				}
				else if (GetAsyncKeyState(VK_F9) & 1) {
					selectWeapon("longbow");
				}
				else if (GetAsyncKeyState(VK_F10) & 1) {
					selectWeapon("wingman");
				}
				else if (GetAsyncKeyState(VK_F12) & 1) {
					selectWeapon("none");
				}
				Sleep(10);
			}
		}



