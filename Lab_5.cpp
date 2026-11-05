#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std :: string getfilename() {
    char temp [101];
    printf("what is the file name?: ");
    scanf("%100s", temp);
    return std::string(temp);
}


int stringtonum(std::string stnum){
    int num = std::stoi(stnum);
    return num;
}

double stringtodouble(std::string stnum, double sum){
    int power = 0;
    bool counting=true;
    int tenpower;
    for(size_t i = 0; i<stnum.size();){
        if (!(stnum[i]==".")&&(counting == true)){
            power++;
        }
        else{
            counting = false;
        }
    }
    for(size_t i = 0; i<stnum.size();){
        tenpower=1;
        if(power>=0){
            for(int i2 = 0; i<power; i++){
                tenpower=tenpower*10;
            }
        }
        else{

        }
        power--;
        sum = sum+(tenpower*stnum[i])
    }
    return num;
}

int main(){
    std :: string filename = getfilename();
    std :: ifstream file(filename);
    std :: string line;
    int linenum = 0;
    while (std::getline(file, line)){
        linenum++;
        int good = 1;
        std::istringstream ss(line);
        std::string word;
        std::string stnum1;
        std::string stnum2;
        int counter = 0;
        while (ss >> word){
            if (counter==0){
                stnum1 = word;
            }
            else if (counter==1){
                stnum2 = word;
            }
            else{
                good = 0;
                printf("ERROR: expected exactly two numbers\n");
            }
            counter++;
        }
        if (counter < 2){
            good = 0;
            printf("ERROR: expected exactly two numbers\n");
        }
        if (good==1){
            int isdouble1 = 0;
            int hasposneg1 = 0;
            for (char c : stnum1){
                if (c=='.'){
                    isdouble1++;
                }
                else if(c=='+' || c=='-'){
                    hasposneg1++;
                }
                else if (!(c >= '0' && c <= '9')){
                    hasposneg1 = 2;
                }
            }
            int isdouble2 = 0;
            int hasposneg2 = 0;
            for (char c : stnum2){
                if (c=='.'){
                    isdouble2++;
                }
                else if(c=='+' || c=='-'){
                    hasposneg2++;
                }
                else if (!(c >= '0' && c <= '9')){
                    hasposneg2 = 2;
                }
            }

            if(isdouble1 > 1||isdouble2>1||hasposneg1>1||hasposneg2>1){
                printf("ERROR: invalid number ");
                if(isdouble1>1||hasposneg1>1){
                    printf("\"%s\" ", stnum1.c_str());
                }
                if(isdouble2>1||hasposneg2>1){
                    printf("\"%s\" ", stnum2.c_str());
                }
                printf("\n");
            }

            else {
                double num1;
                double num2;
                if(isdouble1==1||isdouble2==1){
                    double sum;
                }
                if (isdouble2==1){
                    sum = stringtodouble(stnum1, sum);
                }
                else{
                    num1 = stringtonum(stnum1);
                }
                if (isdouble2==1){
                    num2 = stringtodouble(stnum2);
                }
                else{
                    num2 = stringtonum(stnum2);
                }
                std::string stsum;
                if(isdouble1==1||isdouble2==1){
                    sum = num1+num2;
                    stsum = std::to_string(sum);
                }
                else{
                    int sum = num1+num2;
                    stsum = std::to_string(sum);
                }
                printf("line %i: %s + %s = %s\n", linenum, stnum1.c_str(), stnum2.c_str(), stsum.c_str());
                }
            }
        }
}