#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // print welcome message
    std::cout << "\nYou are an elite hacker trying to break into a level " << Difficulty << " server.\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    /* declare variables */
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    //print sum and product
    std::cout << "There are three numbers in the code.";
    std::cout << "\nThe codes add up to: " << CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cout << "Enter the 3 codes separated by white space:\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check Correctness
    if (GuessSum != CodeSum || GuessProduct != CodeProduct)
    {
        std::cout << " *** ERROR. ERROR. ERROR. Try again! ***\n";
        return false;
    }
    else if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "*** You're in. *** \n";
        return true;
    }
    else{
        std::cout << "?????\n";
        return false;
    }
}


int main()
{    
    srand(time(NULL)); // Create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete;
        bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clear the error
        std::cin.ignore(); // discards the buffer
        
        if (bLevelComplete) 
        {
            // Increase Level Difficulty
            std::cout << "*** Increasing Difficulty. ***\n";
            LevelDifficulty++;
        }
        

    }

    std::cout << "\n*** GREAT WORK MR HACKER. NOW RUN! *** \n";
    return 0;                            
}