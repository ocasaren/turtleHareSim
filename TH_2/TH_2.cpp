#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <thread>


using namespace std;


const int FINISH_L = 70;

void moveTortoise(int* const);
void moveHare(int* const);
void printCurrentPositions(const int* const, const int* const);

int main()
{
    int tortoise = 1;
    int hare = 1;

    srand(time(0));

    cout << "BANG!!!!!\n"
        << "AND THEY ARE OFF!!!!!\n";

   
    while (tortoise != FINISH_L && hare != FINISH_L)
    {
        moveTortoise(&tortoise);
        moveHare(&hare);
        printCurrentPositions(&tortoise, &hare);

    } 

   
} 


void moveTortoise(int* const tPtr)
{
    int x = 1 + rand() % 10; 

    if (x >= 1 && x <= 5) 
        *tPtr += 3;
    else if (x == 6 || x == 7) 
        *tPtr -= 6;
    else 
        ++(*tPtr);

    if (*tPtr < 1)
       *tPtr = 1;



    else if (*tPtr > FINISH_L)
        *tPtr = FINISH_L;

} 

void moveHare(int* const hPtr)
{
    int y = 1 + rand() % 10; 

    if (y == 3 || y == 4) 
        *hPtr += 9;
    else if (y == 5)
        *hPtr -= 12;
    else if (y >= 6 && y <= 8) 
        ++(*hPtr);
    else if (y > 8) 
        *hPtr -= 2;

    if (*hPtr < 1)
        *hPtr = 1;
    else if (*hPtr > FINISH_L)
        *hPtr = FINISH_L;
} 

void printCurrentPositions(const int* const ttPtr,
    const int* const hhPtr)
{
    if (*hhPtr == *ttPtr)
        cout << setw(*hhPtr) << "OUCH!!!";
    else if (*hhPtr < *ttPtr)
        cout << setw(*hhPtr) << 'H'
        << setw(*ttPtr - *hhPtr) << 'T';
    else
        cout << setw(*ttPtr) << 'T'
        << setw(*hhPtr - *ttPtr) << 'H';

    cout << '\n';



    this_thread::sleep_for(chrono::seconds(1));

    
} 