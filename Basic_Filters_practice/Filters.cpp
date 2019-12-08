

#include "Filters.h"

#include <utility>

void Filters::Line(cv::Mat img, cv::Point start, cv::Point end)
{
    int thicness = 2;
    int lineType = cv::LINE_8;

    line(img,std::move(start),std::move(end),cv::Scalar(155,200,120),thicness,lineType);
}

cv::Scalar Filters::randomColor(cv::RNG &rng)
{
    int icolor = (unsigned)rng;
    return cv::Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}

void Filters::Drawing_Random_Lines(cv::Mat image, char *window_name, cv::RNG rng, int NumOfLines, int windowHeight,int windowWidth)
{
    int lineType = 8;
    cv::Point pt1, pt2;

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

Filters::Filters()
= default;

