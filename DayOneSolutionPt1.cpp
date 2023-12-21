#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int placeFlag = 0;
    int myCalibrationNumber[2];
    int myResult = 0;
    
    std::ifstream myFile;
    myFile.open("AoCInputDay1.txt", std::ios::in);
    
    if ( !myFile.is_open() )
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
        switch (currentCharacter)
        {
            case '1':
                placeFlag == 0 ? myCalibrationNumber[0] = 1 : myCalibrationNumber[1] = 1;
                ++placeFlag;
                break;
            case '2':
                placeFlag == 0 ? myCalibrationNumber[0] = 2 : myCalibrationNumber[1] = 2;
                ++placeFlag;
                break;
            case '3':
                placeFlag == 0 ? myCalibrationNumber[0] = 3 : myCalibrationNumber[1] = 3;
                ++placeFlag;
                break;
            case '4':
                placeFlag == 0 ? myCalibrationNumber[0] = 4 : myCalibrationNumber[1] = 4;
                ++placeFlag;
                break;
            case '5':
                placeFlag == 0 ? myCalibrationNumber[0] = 5 : myCalibrationNumber[1] = 5;
                ++placeFlag;
                break;
            case '6':
                placeFlag == 0 ? myCalibrationNumber[0] = 6 : myCalibrationNumber[1] = 6;
                ++placeFlag;
                break;
            case '7':
                placeFlag == 0 ? myCalibrationNumber[0] = 7 : myCalibrationNumber[1] = 7;
                ++placeFlag;
                break;
            case '8':
                placeFlag == 0 ? myCalibrationNumber[0] = 8 : myCalibrationNumber[1] = 8;
                ++placeFlag;
                break;
            case '9':
                placeFlag == 0 ? myCalibrationNumber[0] = 9 : myCalibrationNumber[1] = 9;
                ++placeFlag;
                break;
            default:
                break;
        }
        currentCharacter = myFile.get();
        
        if (currentCharacter == '\n' || currentCharacter == EOF)
        {
            if (placeFlag == 1)
            {
                myResult += myCalibrationNumber[0] * 11;
            }
            else
            {
                myResult += myCalibrationNumber[0] * 10 + myCalibrationNumber[1];
            }
            placeFlag = 0;
        }
    }
    
    myFile.close();
    
    std::cout << myResult;

    return 0;
}
