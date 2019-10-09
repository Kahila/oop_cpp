#include "overload.h"

///int value is by how much the brightness should be increased
void increaseBrightness(Image& objImage, int intValue);

int main()
{
    Image object1(5, 5);
    Image object2(100, 100, {200, 50, 4});

    object1 = object2; ///using overloading to make a deep coper
    increaseBrightness(object1, 73);
    cout << object1 << endl;
    return 0;
}

void increaseBrightness(Image& objImage, int intValue)
{
    for(int i = 0; i < intValue; i++)
        ++objImage;///using the overloaded pre-increment operator to increment the pixels
}
