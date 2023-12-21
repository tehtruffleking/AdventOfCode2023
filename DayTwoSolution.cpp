#include <iostream>
#include <fstream>

#define RED 0
#define GREEN 1
#define BLUE 2

int numericCaseHelper(int, bool);

int main()
{
    bool gameState = true;
    bool numberSeen = false;
    int result = 0;
    int numberOfCubes = 0;
    int gameNumber = 1;
    
    int colorCount[3] = {12, 13, 14};
    
    std::ifstream myFile;
    myFile.open("AoCDay2Input.txt", std::ios::in);
    //myFile.open("DayTwoTest.txt", std::ios::in);
    
    if (!myFile.is_open())
    {
        std::cout << "File failed to open.\n"; 
    }
    else
    {
        std::cout << "File successfully opened.\n";
    }
    
    char currentCharacter;
    
    while (myFile.good())
    {
        currentCharacter = myFile.get();
        
        while (gameState == true)
        {
            switch (currentCharacter)
            {
                case EOF:
                    gameState = false;
                    break;
                case ':':
                case ',':
                case ';':
                    numberSeen = false;
                    numberOfCubes = 0;
                    break;
                case '\n':
                    if (gameState == true)
                    {
                        result += gameNumber++;
                    }
                    numberSeen = false;
                    break;
                case '0':
                    if (!numberSeen)
                    {
                        numberOfCubes = 0;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                    }
                    break;
                case '1':
                    if (!numberSeen)
                    {
                        numberOfCubes = 1;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 1;
                    }
                    break;
                case '2':
                    if (!numberSeen)
                    {
                        numberOfCubes = 2;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 2;
                    }
                    break;
                case '3':
                    if (!numberSeen)
                    {
                        numberOfCubes = 3;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 3;
                    }
                    break;
                case '4':
                    if (!numberSeen)
                    {
                        numberOfCubes = 4;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 4;
                    }
                    break;
                case '5':
                    if (!numberSeen)
                    {
                        numberOfCubes = 5;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 5;
                    }
                    break;
                case '6':
                    if (!numberSeen)
                    {
                        numberOfCubes = 6;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 6;
                    }
                    break;
                case '7':
                    if (!numberSeen)
                    {
                        numberOfCubes = 7;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 7;
                    }
                    break;
                case '8':
                    if (!numberSeen)
                    {
                        numberOfCubes = 8;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 8;
                    }
                    break;
                case '9':
                    if (!numberSeen)
                    {
                        numberOfCubes = 9;
                        numberSeen = true;
                    }
                    else
                    {
                        numberOfCubes *= 10;
                        numberOfCubes += 9;
                    }
                    break;
                case 'r':
                    if (colorCount[RED] < numberOfCubes)
                    {
                        //std::cout << "game " << gameNumber << " is false\n";
                        gameState = false;
                    }
                    numberSeen = false;
                    numberOfCubes = 0;
                    break;
                case 'g':
                    if (colorCount[GREEN] < numberOfCubes)
                    {
                        //std::cout << "game " << gameNumber << " is false\n";
                        gameState = false;
                    }
                    numberSeen = false;
                    numberOfCubes = 0;
                    break;
                case 'b':
                    if (colorCount[BLUE] < numberOfCubes)
                    {
                        //std::cout << "game " << gameNumber << " is false\n";
                        gameState = false;
                    }
                    numberSeen = false;
                    numberOfCubes = 0;
                    break;
                default:
                    break;
            }
            currentCharacter = myFile.get();
            
        }
        
        switch (currentCharacter)
        {
            case '\n':
                gameState = true;
                gameNumber++;
                numberSeen = false;
                break;
            default:
                break;
        }
    }
    
    std::cout << result;
    myFile.close();
    
    return 0;
}
