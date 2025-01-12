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
	const int SIZE = 5;  // �������� ������
	const char EMPTY = '-';
	const char PLAYER1 = 'X';
	const char PLAYER2 = 'O';

	vector<vector<char>> board; // ���ߺ��ͷ� ������ ������ ��� �ڷᱸ��
	char currentPlayer;  // ���� � �÷��̾� �������� ��Ÿ���� ����
	bool gameOver; // ������ ����Ǵ� ������ �����ϴ��� ���ϴ��� ��Ÿ���� ����

	void drawBoard();  //  �������� �׷��ִ� �Լ�
	bool isMoveValid(int row, int col); // ���콺 Ŭ���� ��ǥ�� ��ȿ���� üũ���ִ� �Լ�
	bool isBoardFull(); // �������� �� á���� Ȯ�����ִ� �Լ�
	bool hasPlayerWon(char player); // � �÷��̾ �̰���� Ȯ���ϴ� �Լ�

};
