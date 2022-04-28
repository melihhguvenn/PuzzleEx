//
// Created by emrem on 4/27/2022.
//

#ifndef PUZZLE_PUZZLEROW_H
#define PUZZLE_PUZZLEROW_H


class PuzzleRow{
private:
    struct PuzzlePiece{
        char shape;
        int rowindex;
        int colindex;
        PuzzlePiece* next;
    };
    PuzzlePiece* head;
    PuzzleRow* next;
    int rowindex;
    int pieceSize;
    int maxSize; //equals to puzzleContainer width
    int rowCount;
public:
    PuzzleRow( int size, int rowindex);
    ~PuzzleRow();
    int getRowIndex();
    void setNext( PuzzleRow* next );
    PuzzleRow* getNext();
    bool insert( int index, char shape );
    bool remove( int index );
    bool isEmpty();
    char getPiece(int index );
    void printRow();
    void setHead(PuzzlePiece* piece);
    int getRowCount();
    void setRowCount(int count);
};


#endif //PUZZLE_PUZZLEROW_H