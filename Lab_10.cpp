#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

class Matrix {
    private:
        size_t size;
        int mt[100][100];

    public:
        Matrix(size_t s){
            size = s;
        }
        size_t getsize(){
            return size;
        }
        int getnum(size_t i, size_t i2){
            return mt[i][i2];
        }
        void enternum(size_t i, size_t i2, size_t num){
            mt[i][i2] = num;
        }
        Matrix operator+(Matrix mt2){
            Matrix newmt = Matrix(size);
            for(size_t i = 0; i<size; i++){
                for(size_t i2 = 0; i2<size;i2++){
                    newmt.enternum(i, i2, mt[i][i2]+mt2.getnum(i, i2));
                }
            }
            return newmt;
        }
        Matrix operator*(Matrix mt2){
            Matrix newmt = Matrix(size);
            int newnum;
            for(size_t i = 0; i<size; i++){
                for(size_t i2 = 0; i2<size;i2++){
                    newnum = 0;
                    for(size_t i3 = 0; i3<size;i3++){
                        newnum = newnum + mt[i][i3]*mt2.getnum(i3, i2);
                    }
                    newmt.enternum(i, i2, newnum);
                }
            }
            return newmt;
        }
        void diagonalsum(){
            int primsum = 0;
            for(size_t i=0;i<size;i++){
                primsum = primsum + mt[i][i];
            }
            int secsum = 0;
            for(size_t i=0;i<size;i++){
                secsum = secsum + mt[i][size-1-i];
            }
            printf("Primary Sum: %i\n", primsum);
            printf("Secondary Sum: %i\n", secsum);
        }
        void swaprow(size_t col1, size_t col2){
            int temp;
            for(size_t i=0; i<size; i++){
                temp = mt[col1][i];
                mt[col1][i]=mt[col2][i];
                mt[col2][i]=temp;
            }
        }
        void swapcol(size_t col1, size_t col2){
            int temp;
            for(size_t i=0; i<size; i++){
                temp = mt[i][col1];
                mt[i][col1]=mt[i][col2];
                mt[i][col2]=temp;
            }
        }
        void printmatrix(){
            for(size_t i=0;i<size;i++){
                for(size_t i2=0;i2<size;i2++){
                    printf("%6i ", mt[i][i2]);
                }
                printf("\n");
            }
        }
};
Matrix updatematrix(Matrix mt2, int value=100, size_t row=0, size_t col=0){
    size_t size = mt2.getsize();
    if(row<size && col<size){
        mt2.enternum(row,col,value);
    }
    return mt2;
}
std :: string getfilename() {
    char temp [101];
    printf("what is the file name?: ");
    scanf("%100s", temp);
    return std::string(temp);
}

int main(){
    std :: string filename = getfilename();
    std :: ifstream file(filename);
    std :: string line;
    size_t linenum = 1;
    size_t size;
    std::getline(file,line);
    size = std::stoull(line);
    Matrix matrix1 = Matrix(size);
    Matrix matrix2 = Matrix(size);
    size_t col;

    while (std::getline(file, line)){
        std::istringstream stream(line);
        std::string num;
        col = 0;
        if(linenum <= size){
            while(stream >> num){
                matrix1.enternum(linenum-1, col, std::stoi(num));
                col++;
            }
        }
        else if (linenum <= size*2){
            while (stream >> num){
                matrix2.enternum(linenum-size-1, col, std::stoi(num));
                col++;
            }
        }
        linenum++;
    }
    printf("Matrix A:\n")
    matrix1.printmatrix();
    printf("Matrix B:\n")
    matrix1.printmatrix();
    Matrix summatrix = matrix1+matrix2;
    printf("A + B:\n");
    summatrix.printmatrix();
    Matrix productmatrix = matrix1*matrix2;
    printf("A * B:\n");
    productmatrix.printmatrix();
    printf("Diagonal sums of Matrix A:\n");
    matrix1.diagonalsum();
    matrix2.swaprow(0,2);
    printf("Swapped 1st and third rows on Matrix B:\n");
    matrix2.printmatrix();
    matrix1.swapcol(0,1);
    printf("Swapped 1st and second columns on Matrix A:\n");
    matrix1.printmatrix();
    matrix1 = updatematrix(matrix1);
    printf("Updated Matrix A");
    matrix1.printmatrix();
}