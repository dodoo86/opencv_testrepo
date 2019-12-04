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
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#define WHITE Scalar(255,255,255)
#define w 400


using namespace cv;
using namespace std;
///CHANGING CONTRAST BRIGHTNES-------------------------------------------------------------------------------------------
/*
int main(int argc, char** argv )
{

    Mat image;
    image = imread("../cyberpunk_room.jpg", 1);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    Mat new_image = Mat::zeros(image.size(),image.type());
    double alpha = 4.0;
    int beta = 2;
    image.convertTo(new_image,-1,alpha,beta);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    imshow("New Image", new_image);
    waitKey(0);
    return 0;
}

*/
///ADDING TWO IMAGES NEXT TO EACH OTHER----------------------------------------------------------------------------------
/*
int main(int argc, char** argv )
{
    Mat3b img1 = imread("../picOne.jpg");
    Mat3b img2 = imread("../picTwo.jpg");

    int rows = max(img1.rows, img2.rows);
    int cols = img1.cols + img2.cols;

    Mat3b res(rows,cols,Vec3b(0,0,0));

    img1.copyTo(res(Rect(0,0,img1.cols,img1.rows)));
    img2.copyTo(res(Rect(img1.cols,0,img2.cols,img2.rows)));

    imshow("Img1",img1);
    imshow("Img2",img2);
    imshow("Result",res);
    waitKey(0);

    return 0;
}
*/
///BLENDING TWO IMAGES---------------------------------------------------------------------------------------------------
/*
int main(int argc, char** argv)
{
    double alpha = 0.5; double beta;
    Mat src1, src2, src3;

    src1 = imread("../minearl2.jpg", 1);
    src2 = imread("../smallfern.jpg", 1);

    if(!src1.data) {printf("Error loading src1 \n"); return -1;}
    if(!src2.data) {printf("Error loading src2 \n"); return -1;}

    beta = (1.0 - alpha);
    addWeighted(src1,alpha,src2,beta,0.0,src3);

    namedWindow("Linear Blender",1);
    imshow("Linear Blender",src3);

    waitKey(0);
    return 0;
}
*/
///OTHER SOLUTION FOR BLENDING IMAGES------------------------------------------------------------------------------------
/*
int main()
{

    Mat src1, src2, src3;
    /// Read image ( same size, same type )
    src1 = imread("../minearl2.jpg");
    src2 = imread("../smallfern.jpg");

    ///Comparing whether the two images are of same size or not
    int width1 , width2 , height1 , height2;
    width1 =src1.cols;
    height1=src1.rows;
    width2 =src2.cols;
    height2=src2.rows;

    if (width1!=width2 && height1!=height2)
    {
        printf("Error:Images must be of the same size \n");
        return -1;
    }

    //Merging two images
    src3=(src1/2) + src2;

    if( !src1.data ) { printf("Error loading src1 \n"); return -1; }
    if( !src2.data ) { printf("Error loading src2 \n"); return -1; }
    if( !src3.data ) { printf("Error loading src1 \n"); return -1; }

    /// Create Windows
    namedWindow("First Image", 1);
    imshow( "First Image", src1 );

    namedWindow("Second Image", 1);
    imshow( "Second Image", src2 );

    namedWindow("Blend1 Image", 1);
    imshow( "Blend1 Image", src3 );

    waitKey(0);
    return 0;
}
*/
///CONVERT IMAGE TO GRAYSCALE-------------------------------------------------------------------------------------------
/*
int main()
{
    Mat image;

    image = imread("../cyberpunk_room.jpg", 0);

    if (!image.data)
    {
        printf("No image data !!!\n");
        return -1;
    }
    namedWindow("Display Gray", WINDOW_AUTOSIZE);
    imshow("Display Gray",image);

    imwrite("../Gray_room.jpg",image);

    waitKey(0);
}
*/
///DRAWING PRACTICE ----------------------------------------------------------------------------------------------------
/*
void Ellipse(Mat img, double angle);
void FilledCircle(Mat img, Point center);
void Mypolygon(Mat img);
void Line(Mat img, Point start,Point end);

int main()
{
    char atom_window[] = "Drawing 1: Atom";
    //char rook_window[] = "Drawing 2: Rook";

    Mat atom_image = Mat::zeros(w,w,CV_8UC3);
    //Mat rook_image = Mat::zeros(w,w,CV_8UC3);

    Ellipse(atom_image, 90);
    Ellipse(atom_image,0);
    Ellipse(atom_image, 45);
    Ellipse(atom_image,-45);

    FilledCircle(atom_image,Point(w/2,w/2));
    FilledCircle(atom_image,Point(w/3,w/3));
    FilledCircle(atom_image,Point(w/1,w/1));

    //Mypolygon(rook_image);

    //rectangle(rook_image,Point(0,7*w/8),Point(w,w),Scalar(0,255,255),FILLED,LINE_8);

    //Line(rook_image,Point(0,15*w/16),Point(w,15*w/16));
    //Line(rook_image,Point(w/4,7*w/8),Point(w/4,w));
    //Line(rook_image,Point(w/2,7*w/8),Point(w/2,w));
    //Line(rook_image,Point(3*w/4,7*w/8),Point(3*w/4,w));

    imshow(atom_window,atom_image);
    moveWindow(atom_window,0,200);
    //imshow(rook_window,rook_image);
    //moveWindow(rook_window,w,200);

    waitKey(0);
    return 0;
}

void Ellipse(Mat img, double angle)
{
    int thickness = 2;
    int lineType = 8;

    ellipse(img, Point(w/2,w/2),Size(w/4,w/16),angle,0,360,Scalar(255,0,0),thickness,lineType);

}

void FilledCircle(Mat img, Point center)
{
    circle(img,center,w/32,Scalar(0,0,255,150),FILLED,LINE_8);
}

void Mypolygon(Mat img)
{
    int lineType = LINE_8;
    Point rook_points[1][20];
    rook_points[0][0]  = Point(    w/4,   7*w/8 );
    rook_points[0][1]  = Point(  3*w/4,   7*w/8 );
    rook_points[0][2]  = Point(  3*w/4,  13*w/16 );
    rook_points[0][3]  = Point( 11*w/16, 13*w/16 );
    rook_points[0][4]  = Point( 19*w/32,  3*w/8 );
    rook_points[0][5]  = Point(  3*w/4,   3*w/8 );
    rook_points[0][6]  = Point(  3*w/4,     w/8 );
    rook_points[0][7]  = Point( 26*w/40,    w/8 );
    rook_points[0][8]  = Point( 26*w/40,    w/4 );
    rook_points[0][9]  = Point( 22*w/40,    w/4 );
    rook_points[0][10] = Point( 22*w/40,    w/8 );
    rook_points[0][11] = Point( 18*w/40,    w/8 );
    rook_points[0][12] = Point( 18*w/40,    w/4 );
    rook_points[0][13] = Point( 14*w/40,    w/4 );
    rook_points[0][14] = Point( 14*w/40,    w/8 );
    rook_points[0][15] = Point(    w/4,     w/8 );
    rook_points[0][16] = Point(    w/4,   3*w/8 );
    rook_points[0][17] = Point( 13*w/32,  3*w/8 );
    rook_points[0][18] = Point(  5*w/16, 13*w/16 );
    rook_points[0][19] = Point(    w/4,  13*w/16 );
    const Point* ppt[1] = { rook_points[0] };
    int npt[] = { 20 };
    fillPoly( img,
              ppt,
              npt,
              1,
              Scalar( 255, 255, 255 ),
              lineType );
}

void Line(Mat img, Point start, Point end)
{
    int thicness = 2;
    int lineType = LINE_8;

    line(img,start,end,Scalar(0,0,0),thicness,lineType);
}
*/