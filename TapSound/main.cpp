#pragma comment(lib, "winmm.lib")
#include<windows.h>
#include<mmsystem.h>
#include<iostream>
#include<conio.h>
#include"resource.h"
#include <map>
using namespace std;
int main()
{
	map<int, bool> keymap;
	int keyvalues[]{ VK_XBUTTON1,VK_LEFT,VK_RIGHT };
	for (int i : keyvalues) {
		keymap.insert({ i,false });
	}
	while (true) {
		LASTINPUTINFO* info = new LASTINPUTINFO();
		info->cbSize = sizeof(LASTINPUTINFO);
		GetLastInputInfo(info);
		
		
		for (auto it = keymap.begin(); it != keymap.end()&& GetTickCount64() - info->dwTime <= 100;it++) {
			if (GetAsyncKeyState(it->first) && !it->second) {
				keymap[it->first] = true;
				switch (it->first)
				{
				case VK_LSHIFT:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				default:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				}
			}
			if (!GetAsyncKeyState(it->first) && it->second) {
				keymap[it->first] = false;
			}
		}
		Sleep(50);
	}
}

