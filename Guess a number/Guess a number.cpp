#include <iostream>
#include <ctime>
#include <cstdlib>

int getRandomNumber(int max);
int difficulty();


int ranMax;
int guessNumber;
int level;
int highscore = 100; //saves the least amount of guesses

int guesscount; //Track number of guesses

int main()
{
    srand(time(nullptr)); //gives a new random seed if i understood correctly

    do // choose difficulty
    {
        difficulty();
    } while (level < 1 && level > 3); // suppose to make difficulty() loop if no valid answer given... doesnt work


    while(highscore != 1) // start of big game loop
    {
        guesscount = 0; //Guesscount reset

        if (highscore != 100) //Shows the higescore
        {
            std::cout << "\n\nThe High-Score is " << highscore << " guesses!" << std::endl;
        }


    guessNumber = getRandomNumber(ranMax);  //gives random number

    //std::cout << guessNumber << std::endl; //Cheating

    bool Correct = 0; // To reset the guessing loop 

    std::cout << "\n\nLet's begin!" << std::endl;

    do
    {
        int guess;

        std::cout << "Guess a number" << std::endl;
        std::cin >> guess;
        guesscount++;

        if (guess < guessNumber)
        {
            std::cout << "The number is too low" << std::endl;
        }
        else if (guess > guessNumber)
        {
            std::cout << "The number is too high" << std::endl;
        }
        else if (guess == guessNumber)
        {
            std::cout << "\nCorrect! You did it! The number was " << guessNumber << "!\n";
            Correct = 1;
        }

    } while (Correct == 0);

    std::cout << "You used " << guesscount;
    if (guesscount == 1)
    {
        std::cout << " guess. Amazing!" << std::endl;
    }
    else
    {
        std::cout << " guesses." << std::endl;
    }


    if (guesscount < highscore)
    {
        std::cout << "\nWOW! New HIGH-SCORE!" << std::endl;
        highscore = guesscount;
        std::cout << "--: " << highscore << " :--" << std::endl;
    }
    else if (guesscount == highscore)
    {
        std::cout << "\nGood job! You tied with the High-score!" << std::endl;
    }


    } //end of big game loop

    
    
    std::cout << "\nCan't beat that! Congratulations and goodbye.";

}




int getRandomNumber(int max)
{
    int randomNumber = rand() % max + 1;
    return randomNumber;
}



//selecting level

int difficulty()
{
    
        std::cout << "What difficulty would you like?" << std::endl;
        std::cout << "1 = Easy 1-5" << std::endl;
        std::cout << "2 = Medium 1-10" << std::endl;
        std::cout << "3 = Hard 1-30" << std::endl;
        std::cin >> level;

        switch (level)
        {

        case 1:
            std::cout << "You chose: Easy 1-5" << std::endl;
            ranMax = 5;
            break;

        case 2:
            std::cout << "You chose: Medium 1-10" << std::endl;
            ranMax = 10;
            break;

        case 3:
            std::cout << "You chose: Hard 1-30" << std::endl;
            ranMax = 30;
            break;

        default:
            std::cout << "That was not an option...";
            level = 0;      //sets value for difficulty loop
            break;

        }

        return level;

    
}