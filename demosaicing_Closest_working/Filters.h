#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QtWidgets/qmessagebox.h>
#include "opencv2/core/utility.hpp"
#ifndef DEMOSAICING_CLOSEST_WORKING_FILTERS_H
#define DEMOSAICING_CLOSEST_WORKING_FILTERS_H


class Filters {
public:
    Filters();
    static cv::Mat demosaicing_nearest_neighbor(cv::Mat image);
    static cv::Mat demosaicing_nearest(const cv::Mat& image);
    static void RED_BLUE_handler(const std::vector<cv::Mat> &channels, cv::Mat &result, int flag, int i, int j);
    static void GREEN_handler(const std::vector<cv::Mat> &channels, cv::Mat &result, int i, int j);
};


#endif //DEMOSAICING_CLOSEST_WORKING_FILTERS_H
