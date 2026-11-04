#include<iostream>
#include<thread>
#include<chrono>
#include "mylib.h"
//M = n(n2+1)/2 dh magmo3 kol row & col & diag
int calculateMagicSum(int n) {
    return n * ((n * n) + 1) / 2;
}

// void matrix(int n) {
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             //siamese method
//             int value = (1+((2*j+i-2)%n)+n*((j+i+(n-3)/2)%n)); 
//             std::cout << value << " ";
//         }
//         std::cout << std::endl;
//     }
// }

void printMatrix(int n){
    int posX=n/2+1;
    int posY=1;
    int boxSize=n*n;
    for(int i=1;i<=boxSize;i++){
        gotoxy(posX,posY);
        std::cout<< i;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        if(i%n==0){
            posY++;
            if(posY>n){
                posY=1;
            }
        }else{
            posX++;
            posY--;
            if(posX>n){
                posX=1;
            }
            if(posY<1){
                posY=n;
            }
        }
    }
 
}

int main(){
    int n {};
    std::cout << "Enter the size of the magic square: ";
    std::cin >> n;
    if(n <= 0 || n % 2 == 0 ){
        std::cout << "Size must be a positive odd integer." << std::endl;
        return 1;
    }
    std::cout<<"\033[2J";
    printMatrix(n);
    return 0;
}