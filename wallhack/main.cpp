#include <iostream>
#include <string>
#include <Windows.h>
#include <WinBase.h>
#include <TlHelp32.h>
#include "menu.h"
#include "ProcMem.h" // memory header
ProcMem tom; // memory obj

DWORD Lplayer = 0xCFAA3C;  // dwLocalPlayer
DWORD Elist = 0x4D0D0A4;  //EnityList
DWORD glowobj = 0x524D518;  //dwGlowObject
DWORD iattack = 0x313E7C0;
DWORD gIndex = 0xA40C;  //GlowIndex
DWORD oTeam = 0xF4;
DWORD oFlags = 0x104;
DWORD iJump = 0x51B0758;
DWORD CrossH = 0xB3AC;
DWORD iHealth = 0x100;
DWORD m_ifovs = 0x31E8;  //m_iFOVStart
DWORD flashmax = 0xA3F0;
DWORD dwbSendPackets = 0xD2FEA;  //dwbSendPackets
DWORD dwPRS = 0x313CAEC; //dwPlayerResource
DWORD m_iTeam = 0xF38; //m_iOriginalTeamNumber
DWORD iScore = 0x1980;
DWORD iRank = 0x1A84; //m_iCompetitiveRanking
DWORD m_iping = 0xB28;
DWORD m_iname = 0x154;
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
	float wCgFnjJOPq = 59782938491385.f; wCgFnjJOPq = 96326828402589.f; if (wCgFnjJOPq = 21991792974221.f) wCgFnjJOPq = 78299276116888.f; wCgFnjJOPq = 11963095527706.f; wCgFnjJOPq = 55277061196309.f;
	if (wCgFnjJOPq = 68420587829927.f)wCgFnjJOPq = 29742211180448.f; wCgFnjJOPq = 9565726858908.f;
	if (wCgFnjJOPq = 88049248865191.f)wCgFnjJOPq = 29742211180448.f; wCgFnjJOPq = 9565726858908.f;
	if (wCgFnjJOPq = 88049248865191.f)wCgFnjJOPq = 29742211180448.f; wCgFnjJOPq = 9565726858908.f;
	if (wCgFnjJOPq = 88049248865191.f)wCgFnjJOPq = 29742211180448.f; wCgFnjJOPq = 9565726858908.f;
	if (wCgFnjJOPq = 88049248865191.f)wCgFnjJOPq = 29742211180448.f; wCgFnjJOPq = 9565726858908.f; wCgFnjJOPq = 32999094113757.f;
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

const char* showranking[19] =
{
	"无段位",
	"白银1",
	"白银2",
	"白银3",
	"白银4",
	"白银5",
	"白银大师",
	"黄金1",
	"黄金2",
	"黄金3",
	"黄金4",
	"单AK",
	"麦穗AK",
	"双AK",
	"菊花",
	"小老鹰",
	"大老鹰",
	"小地球",
	"大地球"
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

		//cout << "welcome to TOM external!" << "\npress NUM1 to start!" << endl;
		cout << "欢 ";
		type_eff();
		cout << "迎 ";
		type_eff();
		cout << "使 ";
		type_eff();
		cout << "用 ";
		type_eff();
		cout << "T";
		type_eff();
		cout << "O";
		type_eff();
		cout << "M ";
		type_eff();
		cout << "外";
		type_eff();
		cout << "置";
		type_eff();
		cout << "辅";
		type_eff();
		cout << "助" << endl;
		type_eff();
		Sleep(300);
		cout << "\n" << endl;
		cout << "帅帅帅帅帅    帅帅帅  帅帅帅  帅帅帅" << endl;
		cout << "帅  帅  帅  帅      帅  帅帅  帅帅" << endl;
		cout << "    帅      帅      帅  帅帅  帅帅" << endl;
		cout << "    帅      帅      帅  帅帅  帅帅" << endl;
		cout << "    帅      帅      帅  帅  帅  帅" << endl;
		cout << "    帅      帅      帅  帅  帅  帅" << endl;
		cout << "  帅帅帅      帅帅帅  帅帅  帅  帅帅" << endl;
		//  cout << "" << endl;
		Sleep(250);
		cout << "\n";
		cout << "按下小键盘1 启动";
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
							else if (p_hp <= 25 && p_hp > 0)
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
						else if (p_hp <= 25 && p_hp > 0)
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

				if (GetAsyncKeyState(VK_INSERT))
				{
					DWORD PlayerResoure = tom.Read<DWORD>(bClient + dwPRS);
					int b_team = tom.Read<int>(LocalBase + oTeam);

					for (int i = 0; i < 12; i++)
					{
						int rank = tom.Read<int>(PlayerResoure + iRank + i * 4);
						int diTeam = tom.Read<int>(PlayerResoure + m_iTeam + i * 4);
						int diScore = tom.Read<int>(PlayerResoure + iScore + i * 4);
						int ping = tom.Read<int>(PlayerResoure + m_iping + i * 4);
						if (rank < 0 && rank > 19) return 0;
						if (diTeam > 1 && ping >= 5 && ping < 1000 && diTeam < 4)
						{
							if (diTeam != b_team)
							{
								cout << "\n [敌人] [分数:" << diScore << "]" << "[段位:" << showranking[rank] << "]" << endl;
							}
							else
							{
								cout << "\n [队友] [分数:" << diScore << "]" << "[段位:" << showranking[rank] << "]" << endl;
							}
						}
						Sleep(200);
					}
				}
			}
			return 0; 
		}
	}
