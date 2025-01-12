#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
	const int SIZE = 5;  // 보드판의 사이즈
	const char EMPTY = '-';
	const char PLAYER1 = 'X';
	const char PLAYER2 = 'O';

	vector<vector<char>> board; // 이중벡터로 보드의 정보를 담는 자료구조
	char currentPlayer;  // 현재 어떤 플레이어 순서인지 나타내는 변수
	bool gameOver; // 게임이 종료되는 조건을 만족하는지 안하는지 나타내는 변수

	void drawBoard();  //  보드판을 그려주는 함수
	bool isMoveValid(int row, int col); // 마우스 클릭의 좌표가 유효한지 체크해주는 함수
	bool isBoardFull(); // 보드판이 다 찼는지 확인해주는 함수
	bool hasPlayerWon(char player); // 어떤 플레이어가 이겼는지 확인하는 함수

};
