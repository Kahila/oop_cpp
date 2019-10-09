#ifndef OVERLOAD_H_INCLUDED
#define OVERLOAD_H_INCLUDED
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

struct RGB_color
{
    int intBlue;
    int intGreen;
    int intRed;
};

class Image{
    friend ostream& operator<<(ostream& osLHS, const Image& ObjRHS);
public:
    Image();
    Image(int Rows, int Cols);
    Image(int intRows, int intCols, RGB_color color);
    Image(const Image& objOriginal);

    int getRows() const;
    int getCols() const;
    RGB_color getColor(int intRow, int intCols) const;

    const Image& operator=(const Image& ObjRHS);
    Image& operator++();

    void setPixels(int intCol, int intRow, RGB_color color);

    static const int Max_int = 1000000;
    static const int DEFAULT_rows = 768;
    static const int Default_cols = 1024;
    ~Image();
private:
    void enforceRange(int value, int intMin, int intMax) const;
    bool validPixel(int Picel_value) const;
    void set_pixel(int intRow, int intCol, RGB_color color);
    void allocate_pixels(int intRows, int intCols, RGB_color recColor);
    int _cols;
    int _rows;
    void freePixels();
    RGB_color **Color;
};


#endif // OVERLOAD_H_INCLUDED
