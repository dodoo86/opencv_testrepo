#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QtWidgets/qmessagebox.h>
#include "opencv2/core/utility.hpp"
#include <math.h>
#include "Filters.h"

int main() {
    cv::Mat image;

    image = cv::imread("../parrot-raw.png",1);
    if(!image.data)
    {
        printf("No image data !!!");
        return -1;
    }
    auto start = std::chrono::steady_clock::now();

    cv::Mat dst = Filters::demosaicing_nearest_neighbor(image);
    cv::Mat dst_two = Filters::demosaicing_nearest(image);

    auto finish = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << elapsed.count() << " ms" << std::endl;

    cv::namedWindow("Image Resoult", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Image Original", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Second solution", cv::WINDOW_AUTOSIZE);

    cv::imshow("Image Resoult", dst);
    cv::imshow("Image Original", image);
    cv::imshow("Second solution", dst_two);

    cv::waitKey(0);
    return 0;
}