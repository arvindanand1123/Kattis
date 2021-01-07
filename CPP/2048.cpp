using namespace std;
#include <string>
#include <iostream>
#include <vector>


void print_board(vector<vector<int>> board){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void move_left(vector<vector<int>> board){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 0){
                int tmp = j;
                while(tmp < 4 && board[i][tmp] == 0){
                    tmp++;
                }
                board[i][j] = board[i][tmp];
                board[i][tmp] = 0;
                j=j-2;
            } else if(board[i][j] == board[i][j+1]){
                board[i][j] = board[i][j] + board[i][j+1];
                board[i][j+1] = 0;
            }
        }
    }
    print_board(board);
}

void move_up(vector< vector<int>> board){
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 3;){
            if(board[i][j] == 0){
                int tmp = i;
                while(i < 4 && board[i][j] == 0){
                    i++;
                }
                board[tmp][j] = board[i][j];
                board[i][j] = 0;
            } else {
                i++;
            }
        }
    }
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 3; i++){
            if(board[i][j] == board[i+1][j]){
                board[i][j] = board[i][j] + board[i+1][j];
                board[i+1][j] = 0;
            }
            if(board[i][j] == 0){
                board[i][j] = board[i+1][j];
                board[i+1][j] = 0;
            }
        }
    }
    print_board(board);
}

void move_right(vector<vector<int>> board){
    for(int i = 0; i < 4; i++){
        for(int j = 3; j > 0;){
            if(board[i][j] == 0){
                int tmp = j;
                while(j >= 0 && board[i][j] == 0){
                    j--;
                }
                board[i][tmp] = board[i][j];
                board[i][j] = 0;
            } else {
                j--;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 3; j > 0; j--){
            if(board[i][j] == board[i][j-1]){
                board[i][j] = board[i][j] + board[i][j-1];
                board[i][j-1] = 0;
            }
            if(board[i][j] == 0){
                board[i][j] = board[i][j-1];
                board[i][j-1] = 0;
            }
        }
    }
    print_board(board);
}

void move_down(vector<vector<int>> board){
    for(int j = 0; j < 4; j++){
        for(int i = 3; i > 0;){
            if(board[i][j] == 0){
                int tmp = i;
                while(i < 4 && board[i][j] == 0){
                    i--;
                }
                board[tmp][j] = board[i][j];
                board[i][j] = 0;
            } else {
                i--;
            }
        }
    }
    for(int j = 0; j < 4; j++){
        for(int i = 3; i > 0; i--){
            if(board[i][j] == board[i-1][j]){
                board[i][j] = board[i][j] + board[i-1][j];
                board[i-1][j] = 0;
            }
            if(board[i][j] == 0){
                board[i][j] = board[i-1][j];
                board[i-1][j] = 0;
            }
        }
    }
    print_board(board);
}

int main(){
    vector<vector<int>> board;
    board.resize(4);
    board[0].resize(4);
    board[1].resize(4);
    board[2].resize(4);
    board[3].resize(4);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> board[i][j];
        }
    }

    int move;
    cin >> move;

    if(move == 0){
        move_left(board);
    } else if(move == 1){
        move_up(board);
    } else if(move == 2){
        move_right(board);
    } else if(move == 3){
        move_down(board);
    } 
}