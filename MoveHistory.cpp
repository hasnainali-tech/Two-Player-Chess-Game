#include "MoveHistory.h"
#include <iostream>
using namespace std;

MoveHistory::MoveHistory()
{
  head = NULL;
  tail = NULL;
  totalMoves = 0;
}

void MoveHistory::addMove(
    int startRow, int startCol,
    int endRow, int endCol,
    char pieceSymbol, bool isWhite)
{
  MoveNode *newNode = new MoveNode;

  // Store move information
  newNode->startRow = startRow;
  newNode->startCol = startCol;
  newNode->endRow = endRow;
  newNode->endCol = endCol;
  newNode->peiceSymbol = pieceSymbol;
  newNode->isWhite = isWhite;

  newNode->next = nullptr;

  if (head == nullptr)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }

  totalMoves++;
}

void MoveHistory::displayHistory()
{
  if (head == nullptr)
  {
    cout << "No moves have been made yet.\n";
    return;
  }

  MoveNode *current = head;

  int moveNumber = 1;

  while (current != nullptr)
  {
    cout << "Move " << moveNumber << ": ";

    if (current->isWhite)
      cout << "White ";
    else
      cout << "Black ";

    cout << current->peiceSymbol << " ";

    cout << "(" << current->startRow
         << ", " << current->startCol << ")";

    cout << " -> ";

    cout << "(" << current->endRow
         << ", " << current->endCol << ")";

    cout << endl;

    current = current->next;

    moveNumber++;
  }
}

MoveHistory::~MoveHistory()
{
  MoveNode *current = head;

  while (current != NULL)
  {
    MoveNode *temp = current->next;

    delete current;

    current = temp;
  }

  head = NULL;
  tail = NULL;
}

void MoveHistory::cleanHistory()
{
  MoveNode *current = head;

  while (current != nullptr)
  {
    MoveNode *temp = current->next;

    delete current;

    current = temp;
  }

  head = nullptr;
  tail = nullptr;
  totalMoves = 0;
}