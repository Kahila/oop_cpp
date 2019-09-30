#include "basic.h"

int main()
{
    Image objFlag(768, 1024);
    RGBColor recGreen;
    RGBColor recWhite;

    ///setting the RGB color to green
    recGreen.intGreen = 135;
    recGreen.intBlue = 80;
    recGreen.intRed = 0;

    ///setting the RGB color to white
    recWhite.intBlue = 255;
    recWhite.intGreen = 255;
    recWhite.intRed = 255;

    ///setting which RGB color should go where
    for (int r = 0; r < objFlag.getRows(); r++)
    {
        for (int c = 0; c < objFlag.getCols(); c++)
        {
            RGBColor color;
            if (c < objFlag.getCols()/3)
                color = recGreen;
            else if (c > objFlag.getCols() && c <= objFlag.getCols()*0.6666)
                color = recWhite;
            else
                color = recGreen;
            objFlag.setPixels(r, c, color);
        }
    }
    return 0;
}
