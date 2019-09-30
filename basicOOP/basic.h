#ifndef BASIC_H_INCLUDED
#define BASIC_H_INCLUDED
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

struct RGBColor
{
    int intRed;
    int intBlue;
    int intGreen;
};

enum StatusCode {SUCCESS,FAIL};

///the class that will be used for abstraction
class Image
{
public:
    Image();///default constructor
    Image(int intRows, int intCols);///perameterised constructor
    string toPPM();///method that will return a string with the RGB colors

    ///accessor methods
    int getRows() const;
    int getCols() const;
    RGBColor getPixel(int intRows, int intCols, RGBColor color) const;

    ///mutator method
    void setPixels(int intRows, int intClo, RGBColor Colors);

    ///setting constant value for total rows, columns and the max size
    static const int D_Rows = 600;
    static const int D_Cols = 800;
    static const int Max_size = 100000;

    ///destructor
    ~Image();
private:
    ///method that will be used to check if the given value is within the rang of rows and columns
    void enforceRange(int intValue, int intMin, int intMax) const;
    RGBColor **_pixels;
    int _rows;
    int _cols;
};
#endif // BASIC_H_INCLUDED
