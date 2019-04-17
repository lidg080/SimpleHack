#include <iostream>
#include <string>
#include <Windows.h>
#include <WinBase.h>
#include <TlHelp32.h>
#include "menu.h"
#include "ProcMem.h" // memory header
ProcMem tom; // memory obj

DWORD Lplayer = 0xCD2764;  // dwLocalPlayer
DWORD Elist = 0x4CE34DC;  //EnityList
DWORD glowobj = 0x5223730;  //dwGlowObject
DWORD iattack = 0x3114BA4;
DWORD gIndex = 0xA3F8;  //GlowIndex
DWORD oTeam = 0xF4;
DWORD oFlags = 0x104;
DWORD iJump = 0x5186978;
DWORD CrossH = 0xB394;
DWORD iHealth = 0x100;
DWORD m_ifovs = 0x31E8;  //m_iFOVStart
DWORD flashmax = 0xA3DC;
DWORD dwbSendPackets = 0xD255A;
DWORD engine;
DWORD bClient;
DWORD LocalBase;

//junkcode start
void junkcodea() 
{
	float ExMAJeARHw = 65778119801962.f; ExMAJeARHw = 42403789684480.f; if (ExMAJeARHw = 91573391974007.f) ExMAJeARHw = 92296164419043.f; ExMAJeARHw = 27784933437405.f; ExMAJeARHw = 34374052778493.f;
	if (ExMAJeARHw = 35780519229616.f)ExMAJeARHw = 19740077849302.f; ExMAJeARHw = 83061137293997.f;
	if (ExMAJeARHw = 15309074593493.f)ExMAJeARHw = 19740077849302.f; ExMAJeARHw = 83061137293997.f;
	if (ExMAJeARHw = 15309074593493.f)ExMAJeARHw = 19740077849302.f; ExMAJeARHw = 83061137293997.f;
	if (ExMAJeARHw = 15309074593493.f)ExMAJeARHw = 19740077849302.f; ExMAJeARHw = 83061137293997.f;
	if (ExMAJeARHw = 15309074593493.f)ExMAJeARHw = 19740077849302.f; ExMAJeARHw = 83061137293997.f; ExMAJeARHw = 3382459897357.f;
}

void junkcodeb() 
{
	float ksxCXgKHPO = 31818556185413.f; ksxCXgKHPO = 96650618306175.f; if (ksxCXgKHPO = 96728408016938.f) ksxCXgKHPO = 85305666376900.f; ksxCXgKHPO = 4712070627397.f; ksxCXgKHPO = 6273974712070.f;
	if (ksxCXgKHPO = 1481268530566.f)ksxCXgKHPO = 80169382822716.f; ksxCXgKHPO = 4528564625743.f;
	if (ksxCXgKHPO = 7197525974711.f)ksxCXgKHPO = 80169382822716.f; ksxCXgKHPO = 4528564625743.f;
	if (ksxCXgKHPO = 7197525974711.f)ksxCXgKHPO = 80169382822716.f; ksxCXgKHPO = 4528564625743.f;
	if (ksxCXgKHPO = 7197525974711.f)ksxCXgKHPO = 80169382822716.f; ksxCXgKHPO = 4528564625743.f;
	if (ksxCXgKHPO = 7197525974711.f)ksxCXgKHPO = 80169382822716.f; ksxCXgKHPO = 4528564625743.f; ksxCXgKHPO = 80984668167791.f;
}

void junkcodec() 
{
	float OYspWvGHyN = 8083096059033.f; OYspWvGHyN = 6293757459711.f; if (OYspWvGHyN = 75125832289734.f) OYspWvGHyN = 56919085094643.f; OYspWvGHyN = 7585621146368.f; OYspWvGHyN = 1146368758562.f;
	if (OYspWvGHyN = 8362465691908.f)OYspWvGHyN = 22897344737767.f; OYspWvGHyN = 53751563595413.f;
	if (OYspWvGHyN = 88510237710047.f)OYspWvGHyN = 22897344737767.f; OYspWvGHyN = 53751563595413.f;
	if (OYspWvGHyN = 88510237710047.f)OYspWvGHyN = 22897344737767.f; OYspWvGHyN = 53751563595413.f;
	if (OYspWvGHyN = 88510237710047.f)OYspWvGHyN = 22897344737767.f; OYspWvGHyN = 53751563595413.f;
	if (OYspWvGHyN = 88510237710047.f)OYspWvGHyN = 22897344737767.f; OYspWvGHyN = 53751563595413.f; OYspWvGHyN = 33129114088178.f;
}

// variables
bool glow;
bool bhop;
bool trigger;
bool fov;
bool glow2;
bool noflash;
bool fakelag;

// player struct
struct player
{
	float r, g, b, a;
};

void Startup() // do startup things
{
	tom.Process("csgo.exe"); // not a good way to do this
	bClient = tom.Module("client_panorama.dll");
	engine = tom.Module("engine.dll");
	LocalBase = tom.Read<int>(bClient + Lplayer);
	SetConsoleTitle(TEXT("TomE")); // sets the window title
	system("color 0E");
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 450, 290, TRUE);
	junkcodea();
}

void type_eff() {
	Sleep(rand() % 250);
}

void makelight(int human, player man) // show player
{
	int GlowIndex = tom.Read<int>(human + gIndex);
	int GlowObject = tom.Read<int>(bClient + glowobj);
	int calculation = GlowIndex * 0x38 + 0x4;
	tom.Write<float>(GlowObject + calculation, man.r);
	calculation = GlowIndex * 0x38 + 0x8;
	tom.Write<float>(GlowObject + calculation, man.g);
	calculation = GlowIndex * 0x38 + 0xC;
	tom.Write<float>(GlowObject + calculation, man.b);
	calculation = GlowIndex * 0x38 + 0x10;
	tom.Write<float>(GlowObject + calculation, man.a);
	calculation = GlowIndex * 0x38 + 0x24;
	tom.Write<bool>(GlowObject + calculation, true);
	calculation = GlowIndex * 0x38 + 0x25;
	tom.Write<bool>(GlowObject + calculation, false);
}

	int main() // main function
	{
		junkcodeb();
		using namespace std;
		/* MENU */

		//cout << "welcome to TOM external!" << "\npress F1 to start!" << endl;
		cout << "�� ";
		type_eff();
		cout << "ӭ ";
		type_eff();
		cout << "ʹ ";
		type_eff();
		cout << "�� ";
		type_eff();
		cout << "T";
		type_eff();
		cout << "O";
		type_eff();
		cout << "M ";
		type_eff();
		cout << "��";
		type_eff();
		cout << "��";
		type_eff();
		cout << "��";
		type_eff();
		cout << "��" << endl;
		type_eff();
		Sleep(300);
		cout <<"\n"<< endl;
		cout << "˧˧˧˧˧    ˧˧˧  ˧˧˧  ˧˧˧" << endl;
		cout << "˧  ˧  ˧  ˧      ˧  ˧˧  ˧˧" << endl;
		cout << "    ˧      ˧      ˧  ˧˧  ˧˧" << endl;
		cout << "    ˧      ˧      ˧  ˧˧  ˧˧" << endl;
		cout << "    ˧      ˧      ˧  ˧  ˧  ˧" << endl;
		cout << "    ˧      ˧      ˧  ˧  ˧  ˧" << endl;
		cout << "  ˧˧˧      ˧˧˧  ˧˧  ˧  ˧˧" << endl;
		//  cout << "" << endl;
		Sleep(250);
		cout << "\n";
		cout << "���� С����1 ����ʹ��!";
		cout << "\n";
		while (true) {
			static bool init = false;
			Startup();
			while (true)
			{
				c_menu::main();

				if (glow) {
					for (int i = 0; i <= 64; ++i)
					{
						int b_play = tom.Read<int>(bClient + Elist + (i - 1) * 0x10);
						int m_team = tom.Read<int>(b_play + oTeam);
						int b_team = tom.Read<int>(LocalBase + oTeam);
						int p_hp = tom.Read<int>(b_play + iHealth);
						if (b_team !=m_team)
						{							
							if (p_hp <= 100 && p_hp > 75) 
							{
								makelight(b_play, player{ 0.0f,2.5f,0.0f,0.6f });
							}
							else if (p_hp <= 75 && p_hp > 50) 
							{
								makelight(b_play, player{ 2.5f,1.5f,0.5f,0.6f });
							}
							else if (p_hp <= 50 && p_hp > 25)
							{
								makelight(b_play, player{ 2.5f,0.0f,0.0f,0.6f });
							}
							else if (p_hp <= 25 && p_hp > 1)
							{
								makelight(b_play, player{ 2.5f,2.5f,2.5f,0.6f });
							}
						}

					}
				}
				Sleep(1);

				if (glow2) 
				{
					for (int i = 0; i <= 64; ++i)
					{
						int b_play = tom.Read<int>(bClient + Elist + (i - 1) * 0x10);
						int p_hp = tom.Read<int>(b_play + iHealth);
						if (p_hp <= 120 && p_hp > 75) 
						{
							makelight(b_play, player{ 0.0f,2.5f,0.0f,0.6f });
						}
						else if (p_hp <= 75 && p_hp > 50)
						{
							makelight(b_play, player{ 2.5f,1.5f,0.5f,0.6f });
						}
						else if (p_hp <= 50 && p_hp > 25) 
						{
							makelight(b_play, player{ 2.5f,0.0f,0.0f,0.6f });
						}
						else if (p_hp <= 25 && p_hp > 1)
						{
							makelight(b_play, player{ 2.5f,2.5f,2.5f,0.6f });
						}
					}					
					Sleep(1);
					junkcodeb();
				}

				if (bhop) {
					LocalBase = tom.Read<int>(bClient + Lplayer);
					int flags = tom.Read<int>(LocalBase + oFlags);
					if (GetAsyncKeyState(VK_SPACE) && flags == 257)
					{
						tom.Write<int>(bClient + iJump, 5);
					}
					else
					{
						tom.Write<int>(bClient + iJump, 4);
					}
					Sleep(10);
				}

				if (trigger) {
					LocalBase = tom.Read<int>(bClient + Lplayer);
					int m_cross = tom.Read<int>(LocalBase + CrossH);
					int m_data = tom.Read<int>(bClient + Elist + (m_cross - 1) * 0x10);
					int b_team = tom.Read<int>(LocalBase + oTeam);
					int c_HP = tom.Read<int>(m_data + iHealth);
					int c_team = tom.Read<int>(m_data + oTeam);
					if (GetAsyncKeyState(VK_MENU) & 0x8000) 
					{
						if (c_HP > 0) 
						{
							if (c_team != b_team) 
							{
								tom.Write<int>(bClient + iattack, 5);

								Sleep(7);

								tom.Write<int>(bClient + iattack, 4);
							}
						}
					}
					Sleep(1);
				}				

				if (fov)
				{
					LocalBase = tom.Read<int>(bClient + Lplayer);
					if (GetAsyncKeyState(VK_UP) & 0x8000)
					{
						tom.Write<int>(LocalBase + (m_ifovs - 4), 120);
					}
					if (GetKeyState(VK_DOWN) & 0x8000)
					{
						tom.Write<int>(LocalBase + (m_ifovs - 4), 90);
					}
					junkcodec();
				}

				if (noflash) 
				{
					LocalBase = tom.Read<int>(bClient + Lplayer);
					if (tom.Read<float>(LocalBase + flashmax) > 0.0f) 
					{
						tom.Write<float>(LocalBase + flashmax, 0.0f);
					}					
				}
				else if (tom.Read<float>(LocalBase + flashmax) == 0.0f)
				{
					tom.Write<float>(LocalBase + flashmax, 255.0f);
					junkcodea();
				}

				if (fakelag) 
				{
					tom.Write<byte>(engine + dwbSendPackets, 0);
					Sleep(15);
					tom.Write<byte>(engine + dwbSendPackets, 1);
					junkcodeb();
				}
			}
			return 0; 
		}
	}