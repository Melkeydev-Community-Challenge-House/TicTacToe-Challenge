#include <iostream>

char PiecePlace[10] = {'0','1','2','3','4','5','6','7','8','9'};
bool player;

using namespace std;

bool 
PutPieceOnBoard(bool &player, int choice)
{
  char mark = player ? 'X' : 'O'; int i;
  
  if(PiecePlace[choice] != 'O' && PiecePlace[choice] != 'X') 
  {
      PiecePlace[choice] = mark;
      return true;
  }
  
  return false;
}

void CheckWin()
{
  string PlayerWinningMessage = "\n\n\n      You Won the Game!\n\n\n";
  string ComputerWinningMessage = "\n\n\n      Computer Won the Game!\n\n\n";
      // TopLeft --> TopRight
      if(PiecePlace[1] == 'X' && PiecePlace[2] == 'X' && PiecePlace[3] == 'X')
      {
          std::cout << "\n\n\n "<< PlayerWinningMessage << endl;
          exit(0);
        }
      // TopLeft --> BottomLeft
      else if(PiecePlace[1] == 'X' && PiecePlace[4] == 'X' && PiecePlace[7] == 'X')
      {
          std::cout << "\n\n\n" << PlayerWinningMessage << endl; 
          exit(0);
      }
      // TopLeft --> BootomRight
      else if(PiecePlace[1] == 'X' && PiecePlace[5] == 'X' && PiecePlace[9] == 'X')
      {
          std::cout << PlayerWinningMessage << endl;
          exit(0);
      }
      // MiddleLeft --> MiddleRight
      else if(PiecePlace[4] == 'X' && PiecePlace[5] == 'X' && PiecePlace[6] == 'X')
      {
          std::cout << PlayerWinningMessage << endl;
          exit(0);
      // BottomLeft --> BottomRight
      }
      else if(PiecePlace[7] == 'X' && PiecePlace[8] == 'X' && PiecePlace[9] == 'X')
      {
          std::cout << PlayerWinningMessage << endl;
          exit(0);
      }
      // TopMiddle --> BottomMiddle a
      else if(PiecePlace[2] == 'X' && PiecePlace[5] == 'X' && PiecePlace[8] == 'X')
      {
          std::cout << PlayerWinningMessage << endl;
          exit(0);          
      // TopLeft --> BottomLeft 
      }
      else if(PiecePlace[3] == 'X' && PiecePlace[5] == 'X' && PiecePlace[7] == 'X')
      {
          std::cout << PlayerWinningMessage << endl;
          exit(0);          
      // TopLeft --> BottomLeft 
      }
      //computer decides
      else if(PiecePlace[1] == 'O' && PiecePlace[2] == 'O' && PiecePlace[3] == 'O')
      {
          std::cout << "\n\n\n "<< ComputerWinningMessage << endl;
          exit(0);
        }
      // TopLeft --> BottomLeft
      else if(PiecePlace[1] == 'O' && PiecePlace[4] == 'O' && PiecePlace[7] == 'O')
      {
          std::cout << "\n\n\n" << ComputerWinningMessage << endl; 
          exit(0);
      }
      // TopLeft --> BootomRight
      else if(PiecePlace[1] == 'O' && PiecePlace[5] == 'O' && PiecePlace[9] == 'O')
      {
          std::cout << ComputerWinningMessage << endl;
          exit(0);
      }
      // MiddleLeft --> MiddleRight
      else if(PiecePlace[4] == 'O' && PiecePlace[5] == 'O' && PiecePlace[6] == 'O')
      {
          std::cout << ComputerWinningMessage << endl;
          exit(0);
      // BottomLeft --> BottomRight
      }
      else if(PiecePlace[7] == 'O' && PiecePlace[8] == 'O' && PiecePlace[9] == 'O')
      {
          std::cout << ComputerWinningMessage << endl;
          exit(0);
      }
      // TopMiddle --> BottomMiddle a
      else if(PiecePlace[2] == 'O' && PiecePlace[5] == 'O' && PiecePlace[8] == 'O')
      {
          std::cout << ComputerWinningMessage << endl;
          exit(0);          
      // TopLeft --> BottomLeft 
      }
      else if(PiecePlace[3] == 'O' && PiecePlace[5] == 'O' && PiecePlace[7] == 'O')
      {
          std::cout << ComputerWinningMessage << endl;
          exit(0);          
      // TopLeft --> BottomLeft 
      }
     
      else if(PiecePlace[1] != '1' && PiecePlace[2] != '2' && PiecePlace[3] != '3' && PiecePlace[4] != '4' && PiecePlace[5] != '5' && PiecePlace[6] != '6' && PiecePlace[7] != '7' && PiecePlace[7] != '7' && PiecePlace[8] != '8' && PiecePlace[9] != '9' )
      {
        std::cout << "  Nobody won the match..." << endl;
        exit(0);
      }
};

void GameBoard(int &toss)
{
  system("clear");
  std::cout << "\n\n\n        Tic Tac Toe\n\n\n" << endl;
  if(toss > 5)
  {
  std::cout << "  Players Turns :: ";
  } else
  {
      std::cout << "  Computers Turn :: ";
  }

  std::cout << "  Player (X) - Computer 2 (O)" << endl;
  std::cout << endl << endl;
  std::cout << "             |     |    " << endl;
  std::cout << "          " << PiecePlace[1] << "  |  " << PiecePlace[2] << "  |  " << PiecePlace[3] << endl;
  std::cout << "         ____|_____|_____" << endl;
  std::cout << "             |     |    " << endl;
  std::cout << "          " << PiecePlace[4] << "  |  " << PiecePlace[5] << "  |  " << PiecePlace[6] << endl;
  std::cout << "         ____|_____|_____" << endl;
  std::cout << "             |     |    " << endl;
  std::cout << "          " << PiecePlace[7] << "  |  " << PiecePlace[8] << "  |  " << PiecePlace[9] << endl;
  std::cout << "  \n\n";
  return;
}


int
CoinToss()
{
    srand(time(0));
    int randomshit = rand() % 10 + 1;
    return randomshit;
}


void
PlayersChoice(bool &player)
{
    char marks[2] = {'O', 'X'}; int choice;
    std::cout << "  Please enter a spot to place you: "; std::cin >> choice; 
    bool res = PutPieceOnBoard(player, choice);
   
    while(!res)
    {
     std::cout << "\nRe-evaluate your life: " << endl; std::cin >> choice;
     res = PutPieceOnBoard(player, choice); 
    }
    player = false;
}

void
ComputersChoice(bool &player)
{   
    std::cout << "  Comp: Thinking..." << endl;
    bool res = PutPieceOnBoard(player, CoinToss());
    while(!res)
    {
       res = PutPieceOnBoard(player, CoinToss());     
    }
    std::cout << " " << endl;
    player = true;
}

	
int
main(void)
{
    int computer; int toss; int CurrentPlay = 0;
    
    toss = CoinToss();
    if(toss >= 5){
        player = true;
    } else {
        player = false;
    }

    while(1)
    {
        CheckWin(); 
        CurrentPlay += 1;
        GameBoard(toss);
        if(player)
        {
            PlayersChoice(player);
        } else {
            ComputersChoice(player);
        }
        CurrentPlay++;
    }
}
