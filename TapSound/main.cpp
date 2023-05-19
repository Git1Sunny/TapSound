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
	ShowWindow(GetForegroundWindow(), SW_HIDE);
	INPUT inputs[4] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = VK_LWIN;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = 0x44;

	inputs[2].type = INPUT_KEYBOARD;
	inputs[2].ki.wVk = 0x44;
	inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

	inputs[3].type = INPUT_KEYBOARD;
	inputs[3].ki.wVk = VK_LWIN;
	inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

	map<int, bool> keymap;
	for (int i = 8; i < 254; i++) {
		keymap.insert({ i,false });
	}
	while (true) {
		for (auto it = keymap.begin(); it != keymap.end(); it++) {
			if (GetAsyncKeyState(it->first) && !it->second) {
				keymap[it->first] = true;
				switch (it->first)
				{
				case VK_BACK:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE5), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_LSHIFT:
				case VK_RSHIFT:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE13), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_LCONTROL:
				case VK_RCONTROL:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE12), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 0x43:
					if (GetAsyncKeyState(VK_LCONTROL)) {
						PlaySound(MAKEINTRESOURCE(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
						break;
					}
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 0x56:
					if (GetAsyncKeyState(VK_LCONTROL)) {
						PlaySound(MAKEINTRESOURCE(IDR_WAVE4), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
						break;
					}
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 0x53:
					if (GetAsyncKeyState(VK_LCONTROL)) {
						PlaySound(MAKEINTRESOURCE(IDR_WAVE15), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
						break;
					}
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 0x5A:
					if (GetAsyncKeyState(VK_LCONTROL)) {
						PlaySound(MAKEINTRESOURCE(IDR_WAVE9), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
						break;
					}
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 0x46:
					if (GetAsyncKeyState(VK_LCONTROL)) {
						PlaySound(MAKEINTRESOURCE(IDR_WAVE13), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
						break;
					}
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 0x58:
					if (GetAsyncKeyState(VK_LCONTROL)) {
						PlaySound(MAKEINTRESOURCE(IDR_WAVE6), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
						break;
					}
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case 18:
				case 164:
				case VK_CAPITAL:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE16), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_RETURN:
				case VK_SPACE:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE10), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_TAB:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE11), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_LWIN:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE14), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_RWIN:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE14), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_UP:
				case VK_DOWN:
				case VK_LEFT:
				case VK_RIGHT:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE7), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				case VK_END:
					return 0;
				default:
					PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					break;
				}
			}
			if (!GetAsyncKeyState(it->first) && it->second) {
				keymap[it->first] = false;
			}
		}
		Sleep(80);
	}
}

