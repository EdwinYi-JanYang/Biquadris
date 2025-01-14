#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>

#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "cell.h"
#include "window.h"

class Board {
		int player;
		int rows = 15;
		int cols = 11;
		int extra = 3;
		int currentLevel = 0;
		Block *currentBlock;
		std::vector<std::vector<Cell *>>board;
	public:
		Board(int player, Xwindow *w = nullptr);
		~Board();
		void AddBlock(char type);
		void Move(char direction);
		void Rotate(char direction);
		void Drop();
		std::vector<std::vector<Cell *>> GetBoard() const;
		char GetCellType(int row, int col) const;
		int GetRows() const;
		int GetCols() const;
		friend std::ostream &operator<<(std::ostream &out, const Board &b);		
};

#endif
