
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

bool flag = true;
bool playerDone;
bool houseDone;

int answer;
int phand[5];
int hhand[5];
int phandSize;
int hhandSize;
int phandSum;
int hhandSum;
int phit;
int pstand;
int value;


//void ace()
//{
//    if ()
//    {
//        std::cout << "You got a 1 would you like it to be 1 or 11? " << std::endl;
//        std::cin >> value;
//        if (value == 1)
//        {
//            return;
//        }
//        else if (value == 11)
//        {
//
//        }
//    }
//}

void addPlayerCard() //gives player a random number from 1-10
{
    if (phandSize <= 5) 
    {
        phand[phandSize] = 1 + (rand() % 11);
        phandSize++;
    }
    else 
    {
        std::cout << "You have reached the max number of cards " << std::endl;
        playerDone = true;
    }
    
}

void addHouseCard()  //gives house a random number from 1-10
{
    if (hhandSize <= 5) 
    {
        hhand[hhandSize] = 1 + (rand() % 11);
        hhandSize++;

     }
    else 
    {
        houseDone = true;
    }

}

void printHand() //prints what the player has and house has
{
    std::cout << "Your current hand is " << std::endl;
    for (int i = 0; i < phandSize; i++)
    {
        std::cout << "    -" << phand[i] << "-       " << std::endl;
    }
    std::cout << "House current hand is   " << std::endl;
    for (int j = 0; j < hhandSize; j++)
    {
        std::cout << "    -" << hhand[j] << "-      " << std::endl;
    }
}

void sumHands() // tells player the total sum of what they have in hand
{
    hhandSum = 0;
    phandSum = 0;
    for (int i = 0; i < hhandSize; i++)
    {
        hhandSum += hhand[i];
    }
    for (int j = 0; j < phandSize; j++)
    {
        phandSum += phand[j];
    }
    std::cout << "Player hand sum is: " << phandSum << std::endl;
}

void game() {
   
    addPlayerCard();
    addPlayerCard();
    addHouseCard();
    addHouseCard();
    sumHands();
    printHand();

    if (phandSum == 21) // if the player or house get 21 they win
    {
        std::cout << "Player wins!" << std::endl;
    }
    else if (hhandSum == 21)
    {
        std::cout << "House wins!" << std::endl;
    }

    while (houseDone == false || playerDone == false)
    {
        if (playerDone == false) //gives the player option to draw another random number
        {
            std::cout << "Would you like to hit? Yes = 1, No = 2 " << std::endl;
            std::cin >> phit;
            if (phit == 1)
            {
                addPlayerCard();
                printHand();
                sumHands();

                if (phandSum > 21)
                {
                    std::cout << "Your hand is over 21. Player lose " << std::endl;
                    return;
                }
            }
        }

        if (playerDone == false)
        {
            std::cout << "Would you like to stand? Yes = 1, No = 2 " << std::endl;
            std::cin >> pstand;
        }
        if (pstand == 1)
        {
            playerDone = true;
        }
        if (hhandSum < 17 && houseDone != true)
        {
            addHouseCard();
            printHand();
            sumHands();

            if (hhandSum > 21)
            {
                std::cout << "House hand is over 21. House lose " << std::endl;
                return;
            }
        }
        else if (hhandSum >= 17)
        {
            houseDone = true;
        }
        if (phandSum == 21)
        {
            std::cout << "Player win!" << std::endl;
            return;
        }
        else if (hhandSum == 21)
        {
            std::cout << "House win!" << std::endl;
            return;
        }
        if ((playerDone == true && houseDone == true) || (phandSize == 5 && phandSize == 5))
        {
            if (hhandSum < phandSum)
            {
                std::cout << "Sum of your hand exceeds the dealer's sum of " << hhandSum << "! You win!";
                return;
            }
            else if (phandSum == hhandSum)
            {
                std::cout << "Dealer sum of " << hhandSum << " is equal to the sum of your hand. Tie game.";
                return;
            }
            else if (hhandSum > phandSum)
            {
                std::cout << "Sum of your hand is lower than the dealer's sum of " << hhandSum << ". You lose!";
                return;
            }
        }
    }
    std::cout << " " << std::endl;
}

int main()
{
   
    while (flag == true) {
        std::cout << "Welcome to Blackjack! Ready to play? yes = 1, no = 2 " << std::endl;
        std::cin >> answer;
        if (answer == 1) {
            game();
        }
        if (answer == 2) {
            flag = false;
        }
        else {
            std::cout << "Not a option " << std::endl;
        }
    }
    

    

}

