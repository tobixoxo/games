#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
void enter_score(int score, int compscore)
{
    std::ofstream file("rpsScore.txt",std::ios::app);
    file<< "your score: " << score << " comp score: " << compscore <<  std::endl;
    file.close();
    return;
}

int main()
{
    srand ( time(NULL) ); //initialize the random seed

    std::cout << "hey, welcome this is rock paper scissors!\n" ;
    std::cout << "type \n 1. rock \n 2. paper \n 3. scissors \n 4. exit [ for exit] \n : ";
    std::string user_move;
    int comp_move, comp_score = 0, user_score = 0 ;
    std::string move[3] = {"rock","scissors","paper"};

    do 
    {
        int comp_move = rand() % 3; //generates a random number between 0 and 2
        
        std::cin >> user_move;
        std::cout << "computer gave : " << move[comp_move] << std::endl;
        if (move[comp_move] == user_move) 
        {
            std::cout << user_score << "-" << comp_score << std::endl;
            continue;
        }
        else if (move[comp_move] == "rock")
        {
            if (user_move == "paper") user_score += 1;
            else if (user_move == "scissors") comp_score += 1;
            std::cout << user_score << "-" << comp_score << std::endl;
        }

        else if (move[comp_move] == "paper")
        {
            if (user_move == "scissors") user_score += 1;
            else if (user_move == "rock") comp_score += 1;
            std::cout << user_score << "-" << comp_score << std::endl;
        }

        else if (move[comp_move] == "scissors")
        {
            if (user_move == "rock") user_score += 1;
            else if (user_move == "paper") comp_score += 1;
            std::cout << user_score << "-" << comp_score << std::endl;
        }
    }while (user_move != "exit");
    
    if (user_score > comp_score) {
        std::cout << "you win!! your score : " << user_score << "computer score : " << comp_score ; 
    }

    if (user_score < comp_score) {
        std::cout << "you lose, better luck next time, your score : " << user_score << "computer score : " << comp_score ; 
    }

    if (user_score == comp_score) {
        std::cout << "this was a tie! your score : " << user_score << " computer score : " << comp_score ; 
    }
    enter_score(user_score,comp_score);

    return 0;
}   
