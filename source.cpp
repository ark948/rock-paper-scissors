#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>

int userChoice();
int computerChoice();
int rpsfunc(int userChoice, int computerChoice);

int main()
{
    int userChoiceVar, computerChoiceVar, result;
    std::cout << " Rock-Paper-Scissors by Ark948." << '\n' << " Enter 'r' for Rock, 'p' for Paper and 's' for Scissors or 'q' to exit." << std::endl;

    while (true)
    {
        userChoiceVar = userChoice();
        if (userChoiceVar == 3) {
            std::cout << '\n' << "Bye..." << std::endl;
            break;
        } else if (userChoiceVar == 4) {
            std::cout << " Wrong input. Please try again. ('r' for Rock, 'p' for Paper, 's' for Scissors, 'q' to quit.)" << std::endl;
            continue; // skip current iteration
        }

        computerChoiceVar = computerChoice();
        result = rpsfunc(userChoiceVar, computerChoiceVar);
        
        if (result == 0) std::cout << "IT's a DRAW!" << std::endl;
        else if (result == -1) std::cout << "You LOST!" << std::endl;
        else std::cout << "You WON!" << std::endl;
    }

    std::cout << '\n' << "Exiting the game." << std::endl;
    return 0;
}

int userChoice() {
    // char userInput;
    std::string userInputString;
    char userInput;
    std::cout << '\n' << "> Your choce: ";
    
    // std::cin >> userInput;
    std::getline(std::cin, userInputString);
    if (userInputString.size() > 1) {
        userInput = 4;
    } else if (userInputString.size() == 0) {
        userInput = 4;
    } else {
        userInput = userInputString[0];
    }
    
    switch (userInput) {
        case 'r':
        case 'R':
            std::cout << "Your choice: Rock " << std::endl;
            userInput = 0; // rock
            break;
        case 'p':
        case 'P':
            std::cout << "Your choice: Paper "  << std::endl;
            userInput = 1; // paper
            break;
        case 's':
        case 'S':
            std::cout << "Your chocie: Scissors " << std::endl;
            userInput = 2; // sissors
            break;
        case 'q':
        case 'Q':
            userInput = 3; // quit the program
            break;
        default:
            userInput = 4; // wrong input
            break;
    }
    return userInput;
}

int computerChoice() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    /* using nano-seconds istead of seconds */
    srand((time_t)ts.tv_nsec);
    int computerChoiceRandomVar;
    computerChoiceRandomVar = rand() % 3;
    if (computerChoiceRandomVar == 0) std::cout << "Computer choice: Rock" << std::endl;
    else if (computerChoiceRandomVar == 1) std::cout << "Computer choice: Paper" << std::endl;
    else std::cout << "Computer choice: Scissors" << std::endl;
    return computerChoiceRandomVar;
}

int rpsfunc(int userChoice, int computerChoice) {
    // possible outcomes: -1 win, 0 draw, 1 loss
    // user: 0 rock, 1 paper, 2 scissors
    // computer: 0 rock, 1 paper, 2 scissors
    int gameResult;

    if (userChoice == computerChoice) gameResult = 0;
    else if (userChoice == 0) {
        switch (computerChoice) {
            case 1: gameResult = -1; break;
            case 2: gameResult = 1; break;
            default:
            break;
        }
    } else if (userChoice == 1) {
        switch (computerChoice) {
            case 0: gameResult = 1; break;
            case 2: gameResult = -1; break;
            default:
            break;
        }
    } else if (userChoice == 2) {
        switch (computerChoice) {
            case 0: gameResult = -1; break;
            case 1: gameResult = 1; break;
            default:
            break;
        }
    } else std::cout << "rpsfunc-error" << std::endl;
    return gameResult;
}