
#include "PuzzleRow.h"
#include <iostream>

PuzzleRow::PuzzleRow(int size, int rowindexx) {
    maxSize = size;
    rowindex = rowindexx;
    pieceSize = 0;
    head = NULL;
    next = NULL;
    rowCount++;
}

PuzzleRow::~PuzzleRow() {

}

int PuzzleRow::getRowIndex() {
    return rowindex;
}

void PuzzleRow::setNext(PuzzleRow *next) {
    this->next = next;
}

PuzzleRow *PuzzleRow::getNext() {
    return next;
}

bool PuzzleRow::insert(int index, char shape) {
    PuzzlePiece* piece = head;
    PuzzlePiece* toBeInserted;
    int wanted;

    if (pieceSize == 0){
        this->head = new PuzzlePiece;
        this->head->rowindex = this->rowindex;
        this->head->colindex = index;
        this->head->next = NULL;
        this->head->shape = shape;
        pieceSize++;
        return true;
    }
    for (int i = 0; i < pieceSize; ++i) {
        if (piece->rowindex < index){
            wanted = piece->rowindex;
        }
        if (piece->rowindex == index){
            std::cout << "already occupied" << std::endl;
            return false;
        }
        if (piece->next != NULL){
            piece = piece->next;
        }
    }
    
    piece = head;

    for (int i = 0; i < pieceSize; ++i) {
        if (piece->rowindex == wanted){
            toBeInserted->colindex = index;
            toBeInserted->rowindex = this->rowindex;
            toBeInserted->shape = shape;
            toBeInserted->next = piece->next;
            piece->next = toBeInserted;
            pieceSize++;
            return true;
        }
        piece = piece->next;
    }

}

bool PuzzleRow::remove(int index) {

}

bool PuzzleRow::isEmpty() {

}

char PuzzleRow::getPiece(int index) {

    if (head != NULL ){
        PuzzlePiece* piece = head;
        for (int i = 0; i < pieceSize; ++i) {
            if (piece->colindex == index && piece != NULL){
                return piece->shape;
            }
            if (piece->next != NULL){
                piece = piece->next;
            }
        }
    }

    return ' ';
}

void PuzzleRow::printRow() {

}

void PuzzleRow::setHead(PuzzlePiece *piece) {
    head = piece;
}

int PuzzleRow::getRowCount() {
    return rowCount;
}