#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "board.h"
#include "window.h"

using namespace std;

void drawScreen(Xwindow *w) {
	int player2offset = 200;

	w->drawString(50,50,"Level:    0");
	w->drawString(50 + player2offset,50,"Level:    0");
	
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 1) {
			w->fillRectangle(50, 100 + 10 * i, 10, 10, Xwindow::Black);
			w->fillRectangle(170, 100 + 10 * i, 10, 10, Xwindow::Black);
		} else {
			w->fillRectangle(50, 100 + 10 * i, 10, 10, Xwindow::Blue);
			w->fillRectangle(170, 100 + 10 * i, 10, 10, Xwindow::Blue);
		}
	}
	for (int i = 0; i < 13; i++) {
		if (i % 2 == 1) {
			w->fillRectangle(50 + 10 * i, 100 + 10 * 16, 10, 10, Xwindow::Black);
		}
		if (i % 2 == 0) {
			w->fillRectangle(50 + 10 * i, 100 + 10 * 16, 10, 10, Xwindow::Blue);
		}
	}
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 1) {
			w->fillRectangle(50 + player2offset, 100 + 10 * i, 10, 10, Xwindow::Black);
			w->fillRectangle(170 + player2offset, 100 + 10 * i, 10, 10, Xwindow::Black);
		} else {
			w->fillRectangle(50 + player2offset, 100 + 10 * i, 10, 10, Xwindow::Blue);
			w->fillRectangle(170 + player2offset, 100 + 10 * i, 10, 10, Xwindow::Blue);
		}
	}
	for (int i = 0; i < 13; i++) {
		if (i % 2 == 1) {
			w->fillRectangle(50 + 10 * i + player2offset, 100 + 10 * 16, 10, 10, Xwindow::Black);
		}
		if (i % 2 == 0) {
			w->fillRectangle(50 + 10 * i + player2offset, 100 + 10 * 16, 10, 10, Xwindow::Blue);
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " sequence1 sequence2" << endl;
		return 1;
	}
	Xwindow w;
	w.SetCellSize(10, 10);
	w.SetPlayerOffset(1, 50, 50);
	w.SetPlayerOffset(2, 250, 50);
	w.drawBoard(18, 11);
	//drawScreen(&w);

	Board b1{1, &w}, b2{2, &w};
	string input1 = argv[1], input2 = argv[2];
	ifstream infile1{input1}, infile2{input2};
	vector<char> sequence1, sequence2;
	char block1, block2;
	int level1 = 0, level2 = 0;
	size_t blockIndex1 = 1, blockIndex2 = 1;


	while(infile1 >> block1) {
		sequence1.push_back(block1);
	}
	while(infile2 >> block2) {
		sequence2.push_back(block2);
	}
	string command;
	int player = 1;
	while(true) {
		block1 = sequence1[0];
		block2 = sequence2[0];
		b1.AddBlock(block1);
		b2.AddBlock(block2);
		while(true) {
			if (!(cin >> command)) {
				return 0;
			}
			if (command == "left") {
				b1.Move('l');
			} else if (command == "right") {
				b1.Move('r');	
			} else if (command == "down") {
				b1.Move('d');
			} else if (command == "clockwise") {
				b1.Rotate('r');
			} else if (command == "counterclockwise") {
				b1.Rotate('l');
			} else if (command == "drop") {
				b1.Drop();
				if (player == 1) {
					if (blockIndex1 == sequence1.size()) {
						blockIndex1 = 0;
					}
					block1 = sequence1[blockIndex1];
					b1.AddBlock(block1);
					//b1.AddBlock('J');
					blockIndex1++;
				}
				if (player == 2) {
					if (blockIndex2 == sequence2.size()) {
						blockIndex2 = 0;
					}
					block2 = sequence2[blockIndex2];
					b2.AddBlock(block2);
					blockIndex2++;
				}
			} else if (command == "levelup") {
			
			} else if (command == "leveldown") {
			
			} else if (command == "norandom") {
			
			} else if (command == "random") {
			
			} else if (command == "sequence") {
			
			} else if (command == "restart") {
			
			} else if (command == "p") {
				cout << b1 << endl << b2 << endl;
				//w.updateBoard(b1, 50, 50);
			}
		}
		blockIndex1++;
		blockIndex2++;
		if (player == 1) {
			player == 2;
		} else {
			player == 1;
		}
	}
	cout << b1 << endl;
}
