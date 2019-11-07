#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class WeaponSelector {
public:
	static string slot1;
	static string slot2;
	static string activeSlot;
	static string activeWeapon;
	static bool useSlotSwitchKeybinds;
	static bool toggleActive;
	WeaponSelector();
private:
	static void trackSlot(void);
	static void selectWeapon(string weapon);
	static void trackWeapon(void);
};

