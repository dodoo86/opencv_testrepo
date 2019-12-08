#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QtWidgets/qmessagebox.h>
#include "opencv2/core/utility.hpp"
#include <math.h>

cv::Mat demosaicing_nearest_neighbor(cv::Mat image)
{
    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    int rows = image.rows;
    int colums = image.cols;

    cv::Mat ch1, ch2, ch3, dst;
    ch1 = channels[0];
    ch2 = channels[1];
    ch3 = channels[2];

    for (int i = 1; i < rows - 2; ++i) {
        for (int j = 1; j < colums - 2; ++j)
        {
            if(ch2.at<uchar>(i, j)==0)
            {
                ch2.at<uchar>(i, j) = ch2.at<uchar>(i, j - 1);
            }

            if(ch1.at<uchar>(i, j) == 0)
            {
                ch1.at<uchar>(i, j) = ch1.at<uchar>(i, j -1);
            }

            if(ch3.at<uchar>(i, j) == 0)
            {
                ch3.at<uchar>(i, j) = ch3.at<uchar>(i, j -1);
            }
        }
    }
    for (int i = 1; i < rows - 2; ++i) {
        for (int j = 1; j < colums - 2; ++j)
        {
            if(ch1.at<uchar>(i, j) == 0)
            {
                ch1.at<uchar>(i, j) = (ch1.at<uchar>(i + 1, j) + ch1.at<uchar>(i - 1, j))/2;
            }

            if(ch3.at<uchar>(i, j) == 0)
            {
                ch3.at<uchar>(i, j) = (ch3.at<uchar>(i + 1, j) + ch3.at<uchar>(i - 1, j))/2;
            }
        }
    }
    cv::merge(channels, dst);
    cv::blur(dst, dst, cv::Size(4,4), cv::Point(-1, -1),1);
    return dst;
}


int main() {
    cv::Mat image;

    image = cv::imread("../parrot-raw.png",1);
    if(!image.data)
    {
        printf("No image data !!!");
        return -1;
    }
    auto start = std::chrono::steady_clock::now();

    cv::Mat dst = demosaicing_nearest_neighbor(image);

    auto finish = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << elapsed.count() << " ms" << std::endl;

    cv::namedWindow("Image Resoult", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Image Original", cv::WINDOW_AUTOSIZE);


    cv::imshow("Image Resoult", dst);
    cv::imshow("Image Original", image);
    cv::waitKey(0);
    return 0;
}