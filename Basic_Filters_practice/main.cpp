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
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QtWidgets/qmessagebox.h>
#include "opencv2/core/utility.hpp"
#include <math.h>

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
    ///GaussianBlur filter
    GaussianBlur(image, new_image, Size(5,5),150,150);

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

    src1 = imread(PATH "minearl2.jpg", 1);
    src2 = imread(PATH"smallfern.jpg", 1);

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
///WEBCAM LINE DETECTION------------------------------------------------------------------------------------------------
/*
static void on_trackbar(int, void*)
{

}


int main(int argc, char* argv[])
{
    Mat frame;
    Mat frame2 ;
    Mat text(100,500,CV_8UC1);

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "Cannot open the video cam" << endl;
        return  0;

    }
    namedWindow("Image", 1);
    int threshval;
    createTrackbar("Threshold", "Image", &threshval, 255, on_trackbar);

    while (1)
    {
        bool bSuccess = cap.read(frame); // read a new frame from video


        if (!bSuccess)
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        cvtColor(frame, frame2, COLOR_BGR2GRAY);
        GaussianBlur(frame2, frame2, Size(5, 5), 0);
        Canny(frame2, frame2, threshval, threshval * 2, 3);
        morphologyEx(frame2, frame2, MORPH_CLOSE, Mat(), Point(-1, -1), 2);
        Mat stat, centroid;
        Mat bw = threshval < 128 ? (frame2< threshval) : (frame2 > threshval);
        Mat labelImage(frame2.size(), CV_32S);
        int nLabels = connectedComponentsWithStats(bw, labelImage, stat, centroid, 8);

        std::vector<Vec3b> colors(nLabels);
        colors[0] = Vec3b(0, 0, 0);//background
        for (int label = 1; label < nLabels; ++label)
        {
            colors[label] = Vec3b((rand() & 255), (rand() & 255), (rand() & 255));
        }
        Mat dst(frame2.size(), CV_8UC3);
        for (int r = 0; r < dst.rows; ++r)
        {
            for (int c = 0; c < dst.cols; ++c)
            {
                int label = labelImage.at<int>(r, c);
                Vec3b &pixel = dst.at<Vec3b>(r, c);
                pixel = colors[label];
            }
        }
        bool detection=false;
        for (int i = 0; i < nLabels; i++)
        {
            if (stat.at<int>(i, CC_STAT_AREA) <80 && stat.at<int>(i, CC_STAT_AREA) >10)
            {

                putText(frame2,"mitter",Point(10,30),FONT_HERSHEY_SIMPLEX,1,Scalar(128));
                detection=true;
                break;

            }
        }
        text.setTo(0);
        if (detection)
            putText(text, "detection true", Point(10, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(128));
        else
            putText(text, "detection false", Point(10, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(128));
        imshow("text", text);

        imshow("Image", frame2);

        if (waitKey(1) == 27)
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }

    }
    return 0;
}
*/
///
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
    double alpha = 1;
    int beta = 2;
    image.convertTo(new_image,-1,alpha,beta);
    putText(image,"Blanlaaksjladsfhldshj", Point(100, 100), FONT_HERSHEY_DUPLEX, 5.0, CV_RGB(0,0,0),20);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    //imshow("New Image", new_image);
    waitKey(0);



    return 0;
}
*/
///DRAWING LINE + QT WINDOW---------------------------------------------------------------------------------------------
/*
void Line(Mat img, Point start,Point end);

int main()
{
    char blank_window[] = "Blank Window";
    Mat blank_image = Mat::zeros(w,w,CV_8UC3);

    Line(blank_image,Point(1,1),Point(250,250));

    imshow(blank_window,blank_image);
    QMessageBox mBox(QMessageBox::Icon::Question, "Hallod", "Adjal mar egy cigit!", QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Ignore);
    mBox.show();
    waitKey(0);

    return 0;
}

void Line(Mat img, Point start, Point end)
{
    int thicness = 2;
    int lineType = LINE_8;

    line(img,start,end,Scalar(155,200,120),thicness,lineType);
}
*/
///RANDOM LINE GENERATOR------------------------------------------------------------------------------------------------
/*
void Drawing_Random_Lines (Mat image, char* window_name, RNG rng,int NumOfLines, int windowHeight,int windowWidth);
static Scalar randomColor(RNG& rng);

int main()
{
    int windowHeight = 480, windowWidth = 640;
    Mat image = Mat::zeros(windowHeight, windowWidth, CV_8UC3);
    namedWindow("Random Lines", WINDOW_AUTOSIZE);
    int n = 1;
    while(1)
    {
        RNG rng(n);
        Drawing_Random_Lines(image,"Random Lines",rng,5,windowHeight,windowWidth);
        imshow("Random Lines",image);
        waitKey(100);
        n++;
    }
    return (0);
}

void Drawing_Random_Lines(Mat image, char* window_name, RNG rng, int NumOfLines, int windowHeight, int windowWidth)
{
    int lineType = 8;
    Point pt1, pt2;

    for (int i = 0; i < NumOfLines; ++i)
    {
    pt1.x = rng.uniform(0, windowWidth);
    pt1.y = rng.uniform(0, windowHeight);
    pt2.x = rng.uniform(0, windowWidth);
    pt2.y = rng.uniform(0, windowHeight);

    line( image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), 8 );
    imshow( window_name, image );

    }
}

static Scalar randomColor(RNG& rng)
{
    int icolor = (unsigned)rng;
    return Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}
*/
///SMOOTING IMAGES------------------------------------------------------------------------------------------------------
/*
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
char window_name[] = "Filter Tests";

int display_caption(char* caption);
int display_dst(int delay);

int main(int argc, char** argv)
{
    namedWindow("window_name", WINDOW_AUTOSIZE);
///Load source image-------------------------------------------------------
    src = imread("../cyberpunk_room.jpg",1);
    if(display_caption("Original Image") != 0)
    {
        printf("Original image cant be found!!!");
        return 0;
    }

    dst = src.clone();
    if(display_dst(DELAY_CAPTION) != 0)
        {
        return 0;
        }
    ///Applying Homogeneous Blur--------------------------------------------
    if(display_caption("Homogeneous Blur") != 0)
        {
        return 0;
        }
    for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
    {
    blur(src, dst, Size(i,i), Point(-1,-1));
    if(display_dst(DELAY_BLUR) != 0)
        {
        return 0;
        }
    }
    ///Applying Gaussian Blur
    if(display_caption("Gaussian Blur") != 0)
        {
        return 0;
        }
    for (int i= 1; i < MAX_KERNEL_LENGTH; i = i+2)
    {
     GaussianBlur(src, dst, Size(i,i),0,0);
     if(display_dst(DELAY_BLUR) != 0)
     {
         return 0;
     }
    }
    ///Applying Median Blur---------------------------------------------------
    if(display_caption("Median Blur") != 0)
    {
        return 0;
    }
    for (int i = 1; i < MAX_KERNEL_LENGTH; i = i+2)
    {
    medianBlur(src, dst,i);
    if(display_dst(DELAY_BLUR) != 0)
    {
        return 0;
    }
    }
    ///Applying Bilateral Filter
    if(display_caption("Bilateral Blur") != 0)
    {
        return 0;
    }
    for (int i = 1; i < MAX_KERNEL_LENGTH; i = i+2)
    {
    bilateralFilter(src, dst,i, i*2,i/2);
    if(display_dst(DELAY_BLUR) != 0)
    {
        return 0;
    }
    }
    ///Wait till user press a key
    display_caption("End: press a key!");

    waitKey(0);
    return 0;
}

int display_caption(char* caption)
{
    dst = Mat::zeros(src.size(), src.type());
    putText(dst, caption, Point(src.cols/4, src.rows/2),FONT_HERSHEY_COMPLEX, 1, Scalar(255,255,255));

    imshow("Window_Name", dst);
    int c = waitKey(DELAY_CAPTION);
    if(c >= 0)
    {
        return -1;
    }
    return 0;
}

int display_dst(int delay)
{
    imshow("Window_name",dst);
    int c = waitKey(delay);
    if(c >= 0)
    {
        return -1;
    }
    return 0;
}
*/
///EDGE DETECTION-------------------------------------------------------------------------------------------------------
/*
Mat frame, frame_gray;
Mat frame_done, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratioo = 3;
int kernel_size = 3;
static Scalar randomColor(RNG& rng);


void CannyThreshold(int, void*)
{
    blur(frame_gray, detected_edges, Size(3,3));

    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratioo , kernel_size);

    frame_done = Scalar::all(0);

    frame.copyTo(frame_done, detected_edges);
    imshow("New Windoww", frame_done);
}

int main(int argc, char** argv)
{
    VideoCapture cap(0);

    if( !cap.isOpened())
    {
        printf("Error opening video stream!!!");
        return -1;
    }
    namedWindow("New Windoww", WINDOW_AUTOSIZE);
    createTrackbar("Min Threshold:", "New Windoww", &lowThreshold, max_lowThreshold, CannyThreshold);

    int n = 1;
    while(1)
    {
        RNG rng(n);
        cap>>frame;
        if(frame.empty()){
            break;
        }
        frame_done.create(frame.size(), frame.type());

        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        ///Display the resulting frame
        blur(frame_gray, detected_edges, Size(3,3));

        Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratioo , kernel_size);

        frame_done = Scalar::all(0);

        frame.copyTo(frame_done, detected_edges);
        imshow("New Windoww", frame_done);

        char c = (char)waitKey(1);
        n++;
        if(c==27){
            break;
        }


    }
    return 0;
}

static Scalar randomColor(RNG& rng)
{
    int icolor = (unsigned)rng;
    return Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}
 */
    /*
    dst.create(src.size(), src.type());

    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    namedWindow(window_name, WINDOW_AUTOSIZE);

    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

    CannyThreshold(0,0);

    waitKey(0);

    return 0;
}
*/
///MORPHOLOGY-----------------------------------------------------------------------------------------------------------
/*
Mat src, dst;

int morph_element = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

const char* window_name = "Morphology";

void Morphology_Operations(int, void*);

int main(int argc, char** argv)
{
    CommandLineParser parser( argc, argv, "{@input | ../cyberpunk_room.jpg | input image}" );
    src = imread(samples::findFile(parser.get<String>( "@input")), IMREAD_COLOR);
    if(src.empty())
    {
        printf("Could not open image !!!");
        cout<<"Usage: "<<argv[0]<<" <Input image>" <<endl;
        return EXIT_FAILURE;
    }
    namedWindow(window_name, WINDOW_AUTOSIZE);

    createTrackbar("Operator:\n 0: Opening - 1: Closing \n 2: Gradient - 3: Top Hat \n 4: Black Hat", window_name, &morph_operator, max_operator, Morphology_Operations);

    createTrackbar( "Element:\n 0: Rect - 1: Cross - 2 Ellipse", window_name, &morph_element, max_elem, Morphology_Operations);

    createTrackbar("Kernel size:\n 2n +1", window_name, &morph_size, max_kernel_size, Morphology_Operations);

    Morphology_Operations(0,0);

    waitKey(0);
    return 0;

}

void Morphology_Operations(int, void*)
{
    int operation = morph_operator +2;

    Mat element = getStructuringElement(morph_element, Size(2*morph_size + 1, 2*morph_size+1),Point(morph_size, morph_size));

    morphologyEx(src, dst, operation, element);
    imshow(window_name, dst);
}
*/
///DOWNSAMPLE AND UPSAMPLE----------------------------------------------------------------------------------------------
/*
Mat src, dst, tmp;
char* window_name = "Pyramind";

int main(int argc, char** argv)
{
    printf("\n Zoom In-Out   \n");
    printf("-----------------\n");
    printf(" * [u] -> Zoom in \n");
    printf(" * [d] -> Zoom out \n");
    printf(" * [ESC] -> Close Program \n \n");

    src = imread("../cyberpunk_room.jpg",1);
    if( !src.data)
    {
        printf("No Data!!!");
        return -1;
    }

    tmp = src;
    dst = tmp;

    namedWindow(window_name, WINDOW_AUTOSIZE);
    imshow(window_name, dst);

    while(true)
    {
        int c;
        c = waitKey(10);

        if((char)c == 27)
        {
            break;
        }
        if((char)c == 'u')
        {
            pyrUp(tmp, dst, Size(tmp.cols*2, tmp.rows*2));
            printf("** Zoom in: Image x 2 \n");
        }
        else if((char)c == 'd')
        {
            pyrDown(tmp, dst, Size( tmp.cols/2, tmp.rows/2));
            printf("** Zoom out: Image / 2 \n");
        }

        imshow(window_name, dst);
        tmp = dst;
    }
return 0;
}
*/

