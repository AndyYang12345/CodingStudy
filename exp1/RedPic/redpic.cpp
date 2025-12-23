#include <opencv2/opencv.hpp>


int main(){
    cv::Mat newImage(480, 640, CV_8UC3, cv::Scalar(0, 0, 255)); // 创建一个红色图像
    cv::imshow("Red Image", newImage); // 显示图像
    cv::waitKey(0); // 等待按键
    return 0;
}