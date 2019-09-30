#include "basic.h"

Image::Image() : Image(D_Rows, D_Cols)
{
}

Image::Image(int intRows, int intCols)
{
    enforceRange(intRows, 1, Max_size);
    enforceRange(intCols, 1, Max_size);
    _rows = intRows;
    _cols = intCols;

    _pixels = new RGBColor*[_rows];
    for (int r = 0; r < _rows; r++)
    {
        _pixels[r] = new RGBColor[_cols];
        for (int c = 0; c < _cols; c++)
        {
            RGBColor color;
            color.intBlue = 0;
            color.intGreen = 0;
            color.intRed = 0;
            _pixels[r][c] = color;
        }
    }
}

///definition of the accessor method for getting the columns
int Image::getCols() const{
    return (_cols);
}
///definition of the accessor method for getting the Rows
int Image::getRows() const{
    return (_rows);
}
///definition of the accessor method for getting the pixel
RGBColor Image::getPixel(int intRow, int intCol, RGBColor color) const
{
    enforceRange(intRow , 1, Max_size);
    enforceRange(intCol, 1, Max_size);

    return (_pixels[intRow][intCol]);
}

///mutetor method that will be used to set the pixels
void Image::setPixels(int intRow, int intCol, RGBColor color)
{
    enforceRange(intRow, 1, Max_size - 1);
    enforceRange(intCol, 1, Max_size - 1);

    _pixels[intRow][intCol] = color;
}

void Image::enforceRange(int value, int intMin, int intMax) const
{
    if (value < intMin)
    {
        cout << "Value is < " << intMin;
        exit(FAIL);
    }
    if (value > intMax)
    {
        cout << "Value is > " << intMax;
        exit(FAIL);
    }
}

///Distructor
Image::~Image(){
    for (int r = 0; r < _rows; r++)
        delete [] _pixels[r];
    delete [] _pixels;
    _pixels = nullptr;
}
