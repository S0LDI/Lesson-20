#include <iostream>
#include <array>

class Chessboard; 

class Player
{
public:
    Player(bool isWhite) : isWhite(isWhite) {}

    void displayBoard(const Chessboard& board);
    void setView(bool isWhite) { this->isWhite = isWhite; }

private:
    bool isWhite;
};

class Chessboard
{
public:
    Chessboard()
    {
        
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                board[i][j] = ' ';
    }

   
    friend void Player::displayBoard(const Chessboard& board);

    void setPiece(int x, int y, char piece) { board[x][y] = piece; }

private:
    char board[8][8];
};


void Player::displayBoard(const Chessboard& board)
{
    char playerPiece = isWhite ? 'P' : 'p';

    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 0)
                std::cout << i + 1 << " ";
            char piece = board.board[i][j];
            if (isWhite)
            {
                if (piece == playerPiece)
                {
                    std::cout << piece << " ";
                }
                else if (piece == ' ')
                {
                    std::cout << ". ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
            else
            {
                if (piece == tolower(playerPiece))
                {
                    std::cout << piece << " ";
                }
                else if (piece == ' ')
                {
                    std::cout << ". ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
        }
        std::cout << std::endl;
    }

    std::cout << "  a b c d e f g h" << std::endl;
}

int main()
{
    Chessboard board;
    Player whitePlayer(true);
    Player blackPlayer(false);

    
    board.setPiece(1, 3, 'P');
    board.setPiece(6, 3, 'p');
    board.setPiece(2, 2, 'R');
    board.setPiece(5, 6, 'r');

    
    whitePlayer.displayBoard(board);

   
    blackPlayer.setView(true);
    blackPlayer.displayBoard(board);

    return 0;
}
