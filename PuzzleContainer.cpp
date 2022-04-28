
#include "PuzzleContainer.h"
#include <iostream>

void shapeConverter(unsigned char shape, int& down, int& up, int& right, int& left){
    down = shape%4;
    up = (shape/4)%4;
    right= (shape/16)%4;
    left= shape/64;
}

PuzzleContainer::PuzzleContainer(int h, int w) {
    height = h;
    width = w;
    rowLists = NULL;
    rowListSize = 0;
}

PuzzleContainer::PuzzleContainer() {
    height = 0;
    width = 0;
    rowLists = NULL;
    rowListSize = 0;
}

PuzzleContainer::~PuzzleContainer() {

}

PuzzleRow *PuzzleContainer::getRow(int index) {
    PuzzleRow *temp = rowLists;
    for (int i = 0; i < rowListSize; ++i) {
        if (temp->getRowIndex() == index){
            return temp;
        }
        if (temp->getNext() != NULL){
            temp = temp->getNext();
        }
        else{
            return NULL;
        }
    }
}

bool PuzzleContainer::insertRow(int index) {
    PuzzleRow* temp = rowLists;
    PuzzleRow* row1 = new PuzzleRow(width, index);
    int wanted;
    if (rowListSize == 0){
        rowLists = new PuzzleRow(width, index);
        rowListSize++;
        return true;
    }
    for (int i = 0; i < rowListSize; ++i) {
        if (temp->getRowIndex() == index){
            std::cout << "Already exists" << std::endl;
        }
        if (temp->getRowIndex() < index){
            wanted = temp->getRowIndex();
        }
        if (temp->getNext() != NULL){
            temp = temp->getNext();
        }
    }

    temp = rowLists;
    for (int i = 0; i < rowListSize; ++i) {
        if (temp->getRowIndex() == wanted && wanted != height){
            row1->setNext( temp );
            temp->setNext( row1 );
        }
    }
}

bool PuzzleContainer::removeRow(int index) {

}

bool PuzzleContainer::addPiece(int row, int col, char shape) {
    int down, up, right, left;
    PuzzleRow* temp = rowLists;
    int nextRow, nextColumn;

    shapeConverter(shape, down, up, right, left);

    if (row > height || row < 1 || col > width || col < 1 ){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }

    insertRow(row);

    if (row == height && down == 2){
        if (col == width && right == 2){
            if (getRow(row - 1) == NULL){
                insertRow(row - 1);
            }
            if ((((getRow(row)->getPiece(col - 1)/16) % 4 ) + left == 1 || getRow(row)->getPiece(col - 1) == ' ')&& (( (getRow( row - 1)->getPiece(col) % 4) + up == 1) ||
                    getRow(row - 1)->getPiece(col == ' '))){
                getRow(row)->insert(col, shape);
                std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
                return true;
            }
            else {
                return false;
            }
        }

        else if (col == 1 && left == 2){
            if (getRow(row - 1) == NULL){
                insertRow(row - 1);
            }
            if (((getRow(row)->getPiece(col - 1) / 64) + right == 1 || getRow(row)->getPiece(col - 1) == ' ') && ((getRow(row - 1)->getPiece(col) % 4 ) + up == 1 ||
                    getRow(row - 1)->getPiece(col) == ' ')){
                getRow(row)->insert(col, shape);
                std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
                return true;
            }
            else {
                return false;
            }
        } else{
            if (getRow(row - 1) == NULL){
                insertRow(row - 1);
            }
            if ((getRow(row)->getPiece(col + 1) / 64 + right == 1 || getRow(row)->getPiece(col + 1) == ' ') && ((getRow(row)->getPiece(col - 1) / 16) % 4 + left == 1 ||
                    getRow(row)->getPiece(col - 1) == ' ') &&
                    (getRow(row - 1)->getPiece(col) % 4 + up == 1 || getRow(row - 1)->getPiece(col) == ' ')){
                getRow(row)->insert(col, shape);
                std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
                return true;
            }
            else {
                return false;
            }
        }
    }

    if (row == 1 && up == 2 ){
        if (col == width && right == 2){
            if (getRow(row + 1) == NULL){
                insertRow(row + 1);
            }
            if (((getRow(row)->getPiece(col - 1) / 16) % 4 + left == 1 || getRow(row)->getPiece(col - 1) == ' ') && ((getRow( row + 1)->getPiece(col) / 4) % 4 + down == 1 ||
                    getRow(row + 1)->getPiece(col) == ' ')){
                getRow(row)->insert(col, shape);
                std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
                return true;
            }
            else {
                return false;
            }
        }
        else if (col == 1 && left == 2){
            if (getRow(row + 1) == NULL){
                insertRow(row + 1);
            }
            if ( (( getRow(row)->getPiece(col + 1 ) ) / 64 + right == 1 || getRow(row)->getPiece( col + 1) == ' ') && ((getRow(row + 1)->getPiece(col) / 4 )% 4 + down ==1 ||
                                                                                                                       getRow(row + 1)->getPiece(col) == ' ')){
                getRow(row)->insert(col, shape);
                std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
                return true;
            }
            else {
                return false;
            }
        } else{
            if (getRow(row + 1) == NULL){
                insertRow(row + 1);
            }
            if ((getRow(row)->getPiece(col + 1) / 64 + right == 1 || getRow(row)->getPiece(col + 1) == ' ') && ((getRow(row)->getPiece(col - 1) / 16) % 4 + left == 1 ||
                    getRow(row)->getPiece(col - 1) == ' ') &&
                    ((getRow(row + 1)->getPiece(col) / 4) % 4 + down == 1 || getRow( row + 1)->getPiece(col) == ' ')){
                getRow(row)->insert(col, shape);
                std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
                return true;
            }
            else {
                return false;
            }
        }
    }

    if (col == width && right == 2){
        if (getRow(row + 1) == NULL){
            insertRow(row + 1);
        }
        if (getRow(row - 1) == NULL){
            insertRow(row - 1);
        }
        if (((getRow(row)->getPiece(col - 1) / 16) % 4 + left == 1  || getRow(row)->getPiece(col - 1) == ' ')&&
                ((getRow(row + 1)->getPiece(col) / 4) % 4 + down == 1 || getRow(row + 1)->getPiece(col) == ' ') && (getRow(row - 1)->getPiece(col) % 4 + up == 1 ||
                getRow(row - 1)->getPiece(col) == ' ')){
            getRow(row)->insert(col, shape);
            std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
            return true;
        } else{
            return false;
        }
    }

    if (col == 1 && left == 2){
        if (getRow(row + 1) == NULL){
            insertRow(row + 1);
        }
        if (getRow(row - 1) == NULL){
            insertRow(row - 1);
        }
        if ((getRow(row)->getPiece(col + 1) / 64 + right == 1 || getRow(row)->getPiece(col + 1) == ' ') && ((getRow(row + 1)->getPiece(col) / 4) % 4 + down == 1 ||
                getRow(row + 1)->getPiece(col) == ' ') && (getRow(row - 1)->getPiece(col) % 4 + up == 1 ) || getRow(row - 1)->getPiece(col) == ' '){
            getRow(row)->insert(col, shape);
            std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
            return true;
        } else{
            return false;
        }
    }

    if (getRow(row + 1) == NULL){
        insertRow(row + 1);
    }
    if (getRow(row - 1) == NULL){
        insertRow(row - 1);
    }

    if ((getRow(row)->getPiece(col + 1) / 64 + right == 1 || getRow(row)->getPiece(col + 1) == ' ')&& ((getRow(row)->getPiece(col - 1) / 16) % 4 + left == 1 ||
            getRow(row)->getPiece(col - 1) == ' ')&&
            ((getRow(row + 1)->getPiece(col) / 4) % 4 + down == 1 || getRow(row + 1)->getPiece(col) == ' ')&& (getRow(row - 1)->getPiece(col) % 4 + up == 1 ||
            getRow(row - 1)->getPiece(col) == ' ')){
        getRow(row)->insert(col, shape);
        std::cout << "A piece is added to (" << row << "," << col << ")" << std::endl;
        return true;
    } else{return false;}

}

bool PuzzleContainer::removePiece(int row, int col) {

}

int PuzzleContainer::getHeight() {

}

int PuzzleContainer::getWidth() {

}

void PuzzleContainer::showPiece(int row, int col) {

}

void PuzzleContainer::displayContainer() {

}

void PuzzleContainer::showColumn(int col) {

}

void PuzzleContainer::showRow(int row) {

}

void PuzzleContainer::findPiece(char shape) {

}