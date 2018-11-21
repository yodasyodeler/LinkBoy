#pragma once
#include "mmu.h"
#include "common.h"

struct spriteData {
	int16_t y;
	int16_t x;
	uint16_t tileNum;
	uint8_t flags;
};

class PPU {
	static const int OAMCycles			= 80;
	static const int VRAMCycles			= 172;
	static const int HBlankCycles		= 204;
	static const int VBlankLineCycles	= 456;

	enum { PALETTE_NUM = (1 << 4), X_FLIP = (1 << 5), Y_FLIP = (1 << 6), PRIORITY = (1 << 7) };

	public:
		PPU(MMU* memory);
		~PPU();

		void				changeColor(const Color color[4]);

		void				advanceState(const int cycle);
		void				clearDisplay(); 
		void 				updateColor();

		const uint32_t*		getBuffer();
		bool				isVBlank();
		bool				isDisplayOn();
		
		void				toggleBackground();
		void				toggleWindow();
		void				toggleSprites();

	private:
		int					HBlank();
		int					readOAM();
		int					readVRAM();
		int					VBlank();

		bool	_VBlank						=		false;
		bool	_displayOn					=		false;

		int		(PPU::*_currentState)()	=		&PPU::readOAM;

		int		_stateTime					=		80;
		int		_cycle						=		0;
		
		int		_offDelay					=		0;

		MMU*	_memory						=		nullptr;

		bool	_enableBackground			=		true;
		bool	_enableWindow				=		true;
		bool	_enableSprites				=		true;


		//Display Buffer
		Color	_color[4];
		Color	_buffer[144][160];
		uint8_t _colorIndex[144][160];

		const Color WHITE		= {0xFFFFFFFF};
		const Color DARKGREY	= {0xFF909090};
		const Color LIGHTGREY	= {0xFF404040};
		const Color BLACK		= {0xFF000000};

		const Color DARKBLUE	= {0xFFC0A0A0};
		const Color LIGHTBLUE	= {0xFFC05050};
		const Color BLUE		= {0xFFFF0000};

		const Color DARKGREEN	= {0xFFA0C0A0};
		const Color LIGHTGREEN	= {0xFF50B050};
		const Color GREEN		= {0xFF00FF00};

		const Color DARKRED		= {0xFFA0A0C0};
		const Color LIGHTRED	= {0xFF5050C0};
		const Color RED			= {0xFF0000FF};

		const Color WHITEGB		= {0xFF29e5c2};
		const Color LIGHTGB		= {0xFF26837a};
		const Color DARKGB		= {0xFF406240};
		const Color BLACKGB		= {0xFF0f380f};
};