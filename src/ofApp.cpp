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
    // 여백과 셀 크기 설정
    float margin = 50;
    float cellSize = (ofGetWidth() - 2 * margin) / SIZE; // 셀의 가로 사이즈
    float cellSize_y = (ofGetHeight() - 2 * margin) / SIZE; // 셀의 세로 사이즈

    // 그리드 선 색상 설정
    ofSetColor(0);

    // 가로 그리드 선 그리기
    for (int i = 1; i < SIZE; i++) {
        float y = margin + i * cellSize_y;
        ofDrawLine(margin, y, ofGetWidth() - margin, y);
    }

    // 세로 그리드 선 그리기
    for (int j = 1; j < SIZE; j++) {
        float x = margin + j * cellSize;
        ofDrawLine(x, margin, x, ofGetHeight() - margin);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            float x = margin + j * cellSize;
            float y = margin + i * cellSize_y;

            // 플레이어 마크 그리기
            if (board[i][j] == PLAYER1) {
                // 'X' 그리기
                float offsetX = cellSize * 0.3;
                float offsetY = cellSize_y * 0.3;
                ofDrawLine(x + offsetX, y + offsetY, x + cellSize - offsetX, y + cellSize_y - offsetY);
                ofDrawLine(x + offsetX, y + cellSize_y - offsetY, x + cellSize - offsetX, y + offsetY);
            }
            else if (board[i][j] == PLAYER2) {
                // 'O' 그리기
                float radius = cellSize * 0.35;
                float radiusY = cellSize_y * 0.35;
                ofDrawEllipse(x + cellSize * 0.5, y + cellSize_y * 0.5, radius, radiusY);
            }
        }
    }
}


bool ofApp::isMoveValid(int row, int col) { // 마우스클릭의 좌표가 유효한지 체크해주는 함수
    return row >= 0 && row < SIZE&& col >= 0 && col < SIZE&& board[row][col] == EMPTY;
}

bool ofApp::isBoardFull() { // 보드판이 다 찼는지 체크해주는 함수
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

    /*브루트포스 알고리즘 : 모든 경우를 체크하는 알고리즘
    다 찬 줄이 있는지 모든 줄을 돌면서 체크한다*/

    // 가로줄 다 찼는지 체크
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player && board[i][4] == player) {
            return true;
        }
    }

    // 세로줄 다 찼는지 체크
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player && board[4][i] == player) {
            return true;
        }
    }

    // 대각선으로 다 찼는지 체크
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
    if (key == 'r') { // game restart하기
        board.assign(SIZE, vector<char>(SIZE, EMPTY));
        currentPlayer = PLAYER1;
        gameOver = false;
    }
    if (key == 'q') { // 게임 끝내기
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
        // 마우스 좌표를 셀 인덱스로 변환
        float margin = 50;
        float cellSize = (ofGetWidth() - 2 * margin) / SIZE;
        float cellSize_y = (ofGetHeight() - 2 * margin) / SIZE;
        int row = floor((y - margin) / cellSize_y);
        int col = floor((x - margin) / cellSize);

        if (isMoveValid(row, col)) { // 유효한 좌표인지 체크
            board[row][col] = currentPlayer;
            if (hasPlayerWon(currentPlayer)) { // 해당 플레이어가 이겼는지 체크
                gameOver = true;
                cout << "Player " << currentPlayer << " wins!" << endl;
            }
            else if (isBoardFull()) { // 보드판이 다 차고 비겼는지 체크
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