#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <vector>
void print_guesses(std::vector <int> guesses)
{
    std::cout << "list of guesses" << std::endl;
    for (int i = 0; i< guesses.size();i++)
    {
        std::cout << guesses[i] << "\t";
    }
    return;
}

void playgame()
{
    srand ( time(NULL) ); //initialize the random seed
    int number = rand() % 21; //generates a random number between 0 and 2
    int guess, i ;
    std::vector <int> guesses; // vector declaration
    i = 0;
    std::cout << "YOU ARE A BANISHED WARRIOR WHO LOOKS FOR A PURPOSE\n A GODDESS COMES IN YOUR DREAM\n";
    std::cout << "SHE TELLS YOU ABOUT A CITY, WHERE YOU WILL FIND WHAT YOU SEEK\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------\n";
    std::cout << "THE MAGIC GATE FOR THE CITY HAS A LOCK" << std::endl << "TO OPEN IT YOU HAVE TO SAY THE SACRED NO.\n";
    std::cout << "THE INNOCENT GATEKEEPER CANNOT SAY THE NO.DUE TO THE SPELL\n BUT HE WILL GIVE YOU HINT, YOU HAVE TO GUESS..\n";
    //std::cout << number << "xxxxx\n";
    for(;;)
    {
        std::cout << "guess the no.\n";
        std::cin >> guess;
        guesses.push_back(guess) ;
        i++;
        if (guess > 20) std::cout << "GATEKEEPER: 'THE SACRED NUMBER IS VERY SMALL MY LORD...'" << std::endl;
        else if (guess > number) std::cout << "GATEKEEPER: 'LITTLE LESS, MY WARRIOR..'" << std::endl;
        else if (guess < number) std::cout << "GATEKEEPER: 'THE SACRED NUMBER IS BIG, GENTLEMAN...'" << std::endl;
        else if (guess == number) 
        {
            std::cout << "the no. was " << number << "!\n" ;
            std::cout << "THE GATE OPENED, BUT THE SPELL KILLED THE GATEKEEPER\nGATEKEEPER: 'I AM HAPPY TO DIE HELPING A WARRIOR ...'" << std::endl;
            std::cout << "GATEKEEPER: 'IT'S A SHAME I DIDNT EVEN ASKED YOUR NAME, SIRE..'\n";
            std::cout << "'... it's Samraj...'" << std::endl;
            break;
        }
        
    }
    print_guesses(guesses); 
    std::cout << "LEVEL 1 COMPLETE!\n"; 
    return;
}

int main() 
{
    int choice ;
    do
    {
        std::cout << "------------------------\nTHE FORBIDDEN KINGDOM\n------------------------\n";
        std::cout << "welcome to the game!\nenter\n\t0 to play\n\t1 to quit\n" ;
        std::cin >> choice;
        if (choice == 1) return 0;
        else if (choice == 0) 
        {
            playgame();
            break;
        }
    } while (choice != 0);
    return 0;
}