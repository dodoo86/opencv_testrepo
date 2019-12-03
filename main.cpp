#ifdef _WIN32
#define PATH "..\\..\\..\\"
#endif

#ifdef linux
#define PATH "../"
#endif

#ifdef __APPLE__
#define PATH "../"
#endif

#include <stdio.h>
#include <opencv2/opencv.hpp>


using namespace cv;
int main(int argc, char** argv )
{

    Mat image;
    image = imread(PATH "cyberpunk_room.jpg", 1);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}
