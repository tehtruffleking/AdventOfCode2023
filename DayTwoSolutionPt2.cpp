#include <iostream>
#include <fstream>

#define RED 0
#define GREEN 1
#define BLUE 2

int main()
{
    bool gameState = true;
    bool numberSeen = false;
    bool grFlag = false;
    
    int result = 0;
    int numberOfCubes = 0;
    int gameNumber = 1;
    int sumOfPowers = 0;
    
    int colorCount[3] = {12, 13, 14};
    int minimumSet[3] = {0, 0, 0};
    
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
    
    char currentCharacter = myFile.get();
    
    while (myFile.good())
    {
        //std::cout << currentCharacter;
        switch (currentCharacter)
        {
            case EOF:
                break;
            case ':':
            case ',':
            case ';':
                numberSeen = false;
                numberOfCubes = 0;
                break;
            case '\n':
                //std::cout << "red floor: " << minimumSet[0] << "\tgreen floor: " << minimumSet[1] << "\t  blue floor: " << minimumSet[2] << "\n";
                if (gameState == true)
                {
                    //std::cout << "made it to end of a line\n";
                    result += gameNumber++;
                }
                else
                {
                    gameState = true;
                    gameNumber++;
                }
                sumOfPowers += (minimumSet[0] * minimumSet[1] * minimumSet[2]);
                
                minimumSet[0] = 0;
                minimumSet[1] = 0;
                minimumSet[2] = 0;
                
                //std::cout << "power: " << sumOfPowers << "\n";
                numberSeen = false;
                numberOfCubes = 0;
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
                
                if (grFlag == false)
                {
                    //std::cout << "red count:\t" << numberOfCubes << "\n";
                    if (numberOfCubes > minimumSet[RED])
                    {
                        minimumSet[RED] = numberOfCubes;
                    }
                }
                grFlag = false;
                //std::cout << "grFlag: " << grFlag << " ";
                
                numberSeen = false;
                numberOfCubes = 0;
                break;
            case 'g':
                //std::cout << "green count:\t" << numberOfCubes << "\n";
                grFlag = true;
                if (colorCount[GREEN] < numberOfCubes)
                {
                    //std::cout << "game " << gameNumber << " is false\n";
                    gameState = false;
                }
                
                if (numberOfCubes > minimumSet[GREEN])
                {
                    minimumSet[GREEN] = numberOfCubes;
                }
                
                numberSeen = false;
                numberOfCubes = 0;
                break;
            case 'b':
                //std::cout << "blue count:\t" << numberOfCubes << "\n";
                if (colorCount[BLUE] < numberOfCubes)
                {
                    //std::cout << "game " << gameNumber << " is false\n";
                    gameState = false;
                }
                
                if (numberOfCubes > minimumSet[BLUE])
                {
                    minimumSet[BLUE] = numberOfCubes;
                }
                
                numberSeen = false;
                numberOfCubes = 0;
                break;
            default:
                break;
        }
        currentCharacter = myFile.get();
    }
    
    std::cout << "\nSum of true games: " << result << "\nSum of minimum powers: " << sumOfPowers;
    myFile.close();
    
    return 0;
}
