#ifndef OPENCV_TESTREPO_FILTERS_H
#define OPENCV_TESTREPO_FILTERS_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QtWidgets/qmessagebox.h>
#include "opencv2/core/utility.hpp"
#include <math.h>


class Filters {
public:
    Filters();
    static void Line(cv::Mat img, cv::Point start, cv::Point end);
    static void Drawing_Random_Lines (cv::Mat image, char* window_name, cv::RNG rng,int NumOfLines, int windowHeight,int windowWidth);
    static cv::Scalar randomColor(cv::RNG& rng);

protected:
    cv::Mat img;
    cv::Point end;
    cv::Point startl;
};


#endif //OPENCV_TESTREPO_FILTERS_H
