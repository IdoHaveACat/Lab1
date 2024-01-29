#include <iostream>
#include "func.h"


int main() {
    std::cout << "Please note, only integers are supported\n";

    Matrix originalMatrix = createMatrix();

    std::cout << "Initial Matrx :" << std::endl;
    printMatrix(originalMatrix);

    Matrix newMatrix = copyMatrix(originalMatrix);

    std::cout << "Processed Matrx :" << std::endl;
    printMatrix(newMatrix);

    deleteMatrix(originalMatrix);
    deleteMatrix(newMatrix);

    return 0;
}
