#include "overload.h"

Image::Image() : Image(Default_cols, DEFAULT_rows)
{
}

void Image::enforceRange(int value, int Min, int Max) const
{
    if (value < Min || value > Max)
    {
        cout << "invalid input plz check your input Range\n";
        exit(0);
    }
}

ostream& operator<<(ostream& osLHS, const Image& ObjRHS)
{
    osLHS << "P3" << endl
          << ObjRHS._rows << ' ' << ObjRHS._cols << endl
          << 255 << endl;
    for (int r = 0; r < ObjRHS._rows; r++)
    {
        for (int c = 0; c < ObjRHS._cols; c++)
        {
            osLHS << ObjRHS.Color[r][c].intBlue << ' '
                  << ObjRHS.Color[r][c].intGreen << ' '
                  << ObjRHS.Color[r][c].intRed << ' ';
        }
        osLHS << endl;
    }
    return osLHS;///support chaining.
}

Image::Image(int intRows, int intCols, RGB_color recColor) : Image(intRows, intCols)
{
    for (int r = 0; r < _rows; r++)
    {
        for (int c = 0; c < _cols; c++)
        {
            Color[r][c] = recColor;
        }
    }
}

Image::Image(const Image& objOriginal)
{
    *this = objOriginal;
}

void Image::freePixels()
{
    for (int c = 0; c < _cols; c++)
        delete [] Color[c];
    delete [] Color;
}

bool Image::validPixel(int pixel) const
{
    if (pixel > 255 || pixel < 0)
    {
        return false;
    }
    return true;
}

void Image::setPixels(int intRow, int intCol, RGB_color recColor)
{
    enforceRange(intRow, 0, Max_int - 1);
    enforceRange(intCol, 0, Max_int - 1);
    enforceRange(recColor.intBlue, 0, 255);
    enforceRange(recColor.intGreen, 0, 255);
    enforceRange(recColor.intRed, 0, 255);

    Color[intRow][intCol] = recColor;
}

void Image::allocate_pixels(int intRows, int intCols, RGB_color recColor)
{
    enforceRange(intRows, 0, Max_int - 1);
    enforceRange(intCols, 0, Max_int - 1);
    enforceRange(recColor.intBlue, 0, 255);
    enforceRange(recColor.intGreen, 0, 255);
    enforceRange(recColor.intRed, 0, 255);

    _cols = intCols;
    _rows = intRows;

    Color = new RGB_color*[_rows];
    for (int r = 0; r < _rows; r++)
    {
        Color[r] = new RGB_color[_cols];
        for (int c = 0; c < _cols; c++)
        {
            Color[r][c] = recColor;
        }
    }
}

int Image::getRows() const{
    return _rows;
}

int Image::getCols() const{
    return _cols;
}

RGB_color Image::getColor(int intRow, int intCol) const
{
    enforceRange(intCol, 0, Max_int - 1);
    enforceRange(intRow, 0, Max_int - 1);
    return Color[intRow][intCol];
}

const Image& Image::operator=(const Image& objRHS)
{
    if (this != &objRHS)
    {
        freePixels();///freeing the pixels allocated for the current array
        _rows = objRHS._rows;///updating rows
        _cols = objRHS._cols;///updating colums
        allocate_pixels(_rows, _cols, {0, 0, 0});

        for (int r = 0; r < _rows; r++)
        {
            for (int c = 0; c < _cols; c++)
            {
                Color[r][c] = objRHS.Color[r][c];
            }
        }
    }
    else{
        cout << "self assignment detected\n";
    }
    return *this;
}

Image& Image::operator++()
{
    for (int r = 0; r < _rows; r++)
    {
        for (int c = 0; c < _cols; c++)
        {
            if (validPixel(Color[r][c].intBlue + 1))
                Color[r][c].intBlue++;
            if (validPixel(Color[r][c].intGreen + 1))
                Color[r][c].intGreen++;
            if (validPixel(Color[r][c].intRed + 1))
                Color[r][c].intRed++;
        }
    }
    return *this;
}

Image::~Image()
{
    freePixels();
}

Image::Image(int intCols, int intRows)
{
    enforceRange(intCols, 1, Max_int);
    enforceRange(intRows, 1, Max_int);

    _cols = intCols;
    _rows = intRows;

    Color = new RGB_color*[_rows];
    for(int r = 0; r < intRows; r++)
    {
        Color[r] = new RGB_color[intCols];
        for (int c = 0; c < intCols; c++)
        {
            Color[r][c] = {0, 0, 0};
        }
    }
}
