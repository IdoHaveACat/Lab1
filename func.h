#include <iostream>

struct Matrix {
    int** data;
    int size;
};

//
int inputNumber() {
        std::string input;
        int number;
        std::cout << " : ";

        while (1) {
            std::getline(std::cin, input);
            try {
                number = std::stoi(input); // Попытка преобразования строки в инт number
                break;
            } catch (std::invalid_argument const& e) {
                std::cout << "Erroneous input.\n";
                std::cout << "Input num : ";
            }}
        return number;
    }

Matrix createMatrix(short n = 0) {
    Matrix matrix;
    std::cout << "Declare established SIZE of a symmetric matrix you would wish to be ";
    matrix.size = inputNumber();

    matrix.data = new int*[matrix.size]; // выделение памяти под ключи
    for (int i = 0; i < matrix.size; ++i) {
        matrix.data[i] = new int[matrix.size];
    } // выделение n строк под n столбцов

    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            std::cout << "Enter matrix element [" << i << "][" << j << "] ";
            matrix.data[i][j] = inputNumber();
    }};

    return matrix;
}

void deleteMatrix(Matrix& matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        delete[] matrix.data[i];
    }
    delete[] matrix.data;
}
void printMatrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            std::cout << matrix.data[i][j] << ' ';
            if (!matrix.data[i][j+1]){
                break;
            }
        }
        std::cout << std::endl;
    }
}

//Находим наибольший элемент и сохраняем егонный индекс, апосля чего загружаем все до этого индекса включительно в новую матрицу.
Matrix copyMatrix(const Matrix& originalMatrix) {
    Matrix newMatrix;
    newMatrix.size = originalMatrix.size;
    newMatrix.data = new int*[newMatrix.size];

    for (int i = 0; i < newMatrix.size; ++i) {
        int maxElement = originalMatrix.data[i][0];
        short maxElIndx = 0;
        for (int j = 0; j < originalMatrix.size; ++j) {
            if (originalMatrix.data[i][j] > maxElement) {
                maxElement = originalMatrix.data[i][j];
                maxElIndx = j;}
        }


        newMatrix.data[i] = new int[maxElement + 1];

        for (int j = 0; j <= maxElIndx; ++j) {
            newMatrix.data[i][j] = originalMatrix.data[i][j];
        }
    }

    return newMatrix;
}
