#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class WeaponSelector {
public:
	static string slot1;
	static string slot2;
	static bool slot1Active;
	static string activeWeapon;
public:
	WeaponSelector();
	static void trackSlot(void);
	static string selectWeapon(string weapon);
	static void trackWeapon(void);
};

