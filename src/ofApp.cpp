#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Tick-Tack-Toe");
    ofSetFrameRate(60);

    board.resize(SIZE, vector<char>(SIZE, EMPTY));
    currentPlayer = PLAYER1;
    gameOver = false;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(100, 185, 178);
    drawBoard();
}

/////////////////////////////////////////////////////////////////
void ofApp::drawBoard() {
    // ����� �� ũ�� ����
    float margin = 50;
    float cellSize = (ofGetWidth() - 2 * margin) / SIZE; // ���� ���� ������
    float cellSize_y = (ofGetHeight() - 2 * margin) / SIZE; // ���� ���� ������

    // �׸��� �� ���� ����
    ofSetColor(0);

    // ���� �׸��� �� �׸���
    for (int i = 1; i < SIZE; i++) {
        float y = margin + i * cellSize_y;
        ofDrawLine(margin, y, ofGetWidth() - margin, y);
    }

    // ���� �׸��� �� �׸���
    for (int j = 1; j < SIZE; j++) {
        float x = margin + j * cellSize;
        ofDrawLine(x, margin, x, ofGetHeight() - margin);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            float x = margin + j * cellSize;
            float y = margin + i * cellSize_y;

            // �÷��̾� ��ũ �׸���
            if (board[i][j] == PLAYER1) {
                // 'X' �׸���
                float offsetX = cellSize * 0.3;
                float offsetY = cellSize_y * 0.3;
                ofDrawLine(x + offsetX, y + offsetY, x + cellSize - offsetX, y + cellSize_y - offsetY);
                ofDrawLine(x + offsetX, y + cellSize_y - offsetY, x + cellSize - offsetX, y + offsetY);
            }
            else if (board[i][j] == PLAYER2) {
                // 'O' �׸���
                float radius = cellSize * 0.35;
                float radiusY = cellSize_y * 0.35;
                ofDrawEllipse(x + cellSize * 0.5, y + cellSize_y * 0.5, radius, radiusY);
            }
        }
    }
}


bool ofApp::isMoveValid(int row, int col) { // ���콺Ŭ���� ��ǥ�� ��ȿ���� üũ���ִ� �Լ�
    return row >= 0 && row < SIZE&& col >= 0 && col < SIZE&& board[row][col] == EMPTY;
}

bool ofApp::isBoardFull() { // �������� �� á���� üũ���ִ� �Լ�
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool ofApp::hasPlayerWon(char player) {

    /*���Ʈ���� �˰��� : ��� ��츦 üũ�ϴ� �˰���
    �� �� ���� �ִ��� ��� ���� ���鼭 üũ�Ѵ�*/

    // ������ �� á���� üũ
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player && board[i][4] == player) {
            return true;
        }
    }

    // ������ �� á���� üũ
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player && board[4][i] == player) {
            return true;
        }
    }

    // �밢������ �� á���� üũ
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player) {
        return true;
    }

    if (board[0][4] == player && board[1][3] == player && board[2][2] == player && board[3][1] == player && board[4][0] == player) {
        return true;
    }

    return false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'r') { // game restart�ϱ�
        board.assign(SIZE, vector<char>(SIZE, EMPTY));
        currentPlayer = PLAYER1;
        gameOver = false;
    }
    if (key == 'q') { // ���� ������
        cout << "Game Quit!!" << endl;
        _Exit(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    if (!gameOver) {
        // ���콺 ��ǥ�� �� �ε����� ��ȯ
        float margin = 50;
        float cellSize = (ofGetWidth() - 2 * margin) / SIZE;
        float cellSize_y = (ofGetHeight() - 2 * margin) / SIZE;
        int row = floor((y - margin) / cellSize_y);
        int col = floor((x - margin) / cellSize);

        if (isMoveValid(row, col)) { // ��ȿ�� ��ǥ���� üũ
            board[row][col] = currentPlayer;
            if (hasPlayerWon(currentPlayer)) { // �ش� �÷��̾ �̰���� üũ
                gameOver = true;
                cout << "Player " << currentPlayer << " wins!" << endl;
            }
            else if (isBoardFull()) { // �������� �� ���� ������ üũ
                gameOver = true;
                cout << "It's a draw!" << endl;
            }
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}