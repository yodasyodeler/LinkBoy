#pragma once
#include "gbz80.h"
#include "mmu.h"
#include "ppu.h"
#include "timer.h"
#include "linkboyClient.h"
#include "Display.h"

//#define DEBUG 1

class linkboy
{
	public:
		linkboy(const char* dirName, const char* filename = nullptr);
		linkboy(BaseLogger* log, const char* dirName, const char* filename = nullptr);
		~linkboy();

		void startEmulation();


	private:
		void saveState();
		void loadState();

		void checkDebug();

		void loadGame(const char* filename);

		void handleNetwork();
		void handleSettings();
		char*	m_saveState = nullptr;

		MMU		m_memory;
		gbz80	m_cpu;
		PPU		m_display;
		timer	m_timer;
		Client	m_client;
		bool	m_pause;

		emulatorSettings m_settings = {false, false, false, 1, 3, nullptr, 0.0, m_memory.JoyPad, NoOperation, {} };
};
