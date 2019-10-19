#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <regex>
#include <sys/stat.h>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "sort.h"

/**
 * @brief Check if file is exist.
 * 
 * @param filename The name of the file.
 * @return exist: true; not exist: false.
 */
bool isFileExist(const char* filename);

/**
 * @brief Check the main program arguments
 * 
 * @param argc the number of main program arguments
 * @param argv the main program arguments array
 */
void checkProgramArg(int argc, char** argv);

/**
 * @brief Splite string to double vector.
 * eg. "4.4,45.6" -> vector<double>(){ 4.4, 45.6 };
 * 
 * @param numberString string with numbers and character
 * @param character specific character
 * @return std::vector<double> The vector of double.
 */
std::vector<double> splitNumberByChar(std::string numberString, char character);

/**
 * @brief Transfer shape argument content to vector of Shape*
 * 
 * @param inputContents The shape text in input file.
 * @param shapes The reference of a vector that storage Shapes.
 */
void shapeArgumentToShapes(
    std::vector<std::string> inputContents,
    std::vector<Shape*>& shapes);

/**
 * @brief Write result to output file.
 * 
 * @param fileName 
 * @param shapes 
 * @param outputFileStream 
 * @param resultFunc The function that which computed result to use.
 */
void writeToFile(
    char* fileName,
    std::vector<Shape*> shapes,
    std::ofstream* outputFileStream,
    std::function<double (Shape*)> resultFunc);

// main function
int main(int argc, char** argv)
{
    checkProgramArg(argc, argv);

    std::ifstream* inputFileStream = new std::ifstream();
    std::ofstream* outputFileStream = new std::ofstream();

    std::string content;
    std::vector<std::string> inputContents;
    std::vector<Shape*> shapes;

    // read input file content to vector.
    inputFileStream->open(argv[1], std::ios::in);
    while(std::getline(*inputFileStream, content))
    {
        inputContents.push_back(content);
    }

    // after read all content, close input file stream.
    inputFileStream->close();

    // transfer arguments to Shapes.
    shapeArgumentToShapes(inputContents, shapes);

    // new a sort object
    Sort* sort = new Sort(&shapes);

    // check sorting method
    if (std::string(argv[3]) == "area")
    {
        if (std::string(argv[4]) == "inc")
        {
            sort->sortArea(sortAreaAsc);
        }
        else
        {
            sort->sortArea(sortAreaDesc);
        }

        writeToFile(argv[2], shapes, outputFileStream, [](Shape* shape) {
            return shape->area();
        });
    }
    else
    {
        if (std::string(argv[4]) == "inc")
        {
            sort->sortPerimeter(perimeterAscendingComparison);
        }
        else
        {
            sort->sortPerimeter(perimeterDescendingComparison);
        }

        writeToFile(argv[2], shapes, outputFileStream, [](Shape* shape) {
            return shape->perimeter();
        });
    }

    delete inputFileStream;
    delete outputFileStream;

    return 0;
}

// check the main program arguments
void checkProgramArg(int argc, char** argv)
{
    // check arguments number
    if (argc != 5)
    {
        std::cout << "Wrong arguments number." << std::endl;

        exit(1);
    }

    // check arguments
    if (!isFileExist(argv[1]))
    {
        std::cout << "Cannot find input file:" << argv[1] << std::endl;

        exit(1);
    }
    
    if (std::string(argv[3]) != "area" && std::string(argv[3]) != "perimeter")
    {
        std::cout << "Invaild sorting method: " << argv[3] << std::endl;

        exit(1);
    }

    if (std::string(argv[4]) != "inc" && std::string(argv[4]) != "dec")
    {
        std::cout << "Invalid ordering method: " << argv[4] << std::endl;

        exit(1);
    }
}

// Check file is exist or not.
bool isFileExist(const char* filename)
{
    struct stat buf;
    if (stat(filename, &buf) != -1)
    {
        return true;
    }

    return false;
}

// split string to vector of double
std::vector<double> splitNumberByChar(std::string numberString, char character)
{
    std::stringstream sstream(numberString);
    std::vector<double> numbers;
    std::string number;
    while(std::getline(sstream, number, character))
    {
        numbers.push_back(stod(number));
    }

    return numbers;
}

// transfer shape argument content to vector of Shape*
void shapeArgumentToShapes(
    std::vector<std::string> inputContents,
    std::vector<Shape*>& shapes)
{
    // regex for check shapes in input content.
    // std::regex circleReg ( R"rgx(^Circle \([0-9]{1,}[.]?[0-9]*\)$)rgx" );
    // std::regex rectangleReg ( R"rgx(^Rectangle \([0-9]{1,}[.]?[0-9]*[,][0-9]{1,}[.]?[0-9]*\)$)rgx" );
    // std::regex triangleReg ( R"rgx(^Triangle \([0-9]{1,}[.]?[0-9]*([,][0-9]{1,}[.]?[0-9]*){5}\)$)rgx" );

    for (std::string shapeString : inputContents)
    {
        // check which shapes
        if (/*std::regex_match(shapeString, circleReg)*/ shapeString.substr(0, 6) == "Circle")
        {
            shapeString.erase(shapeString.end() - 1);
            std::string radius = shapeString.substr(8);
            shapes.push_back(new Circle(std::stod(radius)));
        }
        else if (/*std::regex_match(shapeString, rectangleReg)*/ shapeString.substr(0, 9) == "Rectangle")
        {
            shapeString.erase(shapeString.end() - 1);
            std::string numberString = shapeString.substr(11);
            std::vector<double> numbers = splitNumberByChar(numberString, ',');

            shapes.push_back(new Rectangle(numbers[0], numbers[1]));
        }
        else if (/*std::regex_match(shapeString, triangleReg)*/ shapeString.substr(0, 8) == "Triangle")
        {
            shapeString.erase(shapeString.end() - 1);
            std::string numberString = shapeString.substr(10);
            std::vector<double> numbers = splitNumberByChar(numberString, ',');

            shapes.push_back(new Triangle(
                numbers[0],
                numbers[1],
                numbers[2],
                numbers[3],
                numbers[4],
                numbers[5]));
        }
        else
        {
            std::cout << "Wrong shape: " << shapeString << std::endl;

            exit(1);
        }
    }
}

void writeToFile(
    char* fileName,
    std::vector<Shape*> shapes,
    std::ofstream* outputFileStream,
    std::function<double (Shape*)> resultFunc)
{
    outputFileStream->open(fileName, std::ios::out);
    *outputFileStream << '[';
    for (Shape* shape : shapes)
    {
        if (shape != shapes.back())
        {
            *outputFileStream << resultFunc(shape) << ',';
        }
        else
        {
            *outputFileStream << resultFunc(shape) << ']';
        }
    }

    outputFileStream->close();
}