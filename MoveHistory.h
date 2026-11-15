#ifndef MOVEHISTORY_H
#define MOVEHISTORY_H

class MoveHistory
{
private:
  struct MoveNode
  {
    int startRow;
    int startCol;

    int endRow;
    int endCol;

    char peiceSymbol;
    bool isWhite;

    MoveNode *next;
  };

  MoveNode *head;
  MoveNode *tail;

  int totalMoves;

public:
  MoveHistory();

  ~MoveHistory();

  void addMove(
      int startRow, int startCol,
      int endRow, int endCol,
      char peiceSymbol, bool isWhite);

  void displayHistory();

  void cleanHistory();
};

#endif