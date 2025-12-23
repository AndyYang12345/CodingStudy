
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("image.jpg");
    
    // 检查图像是否成功读取
    if(image.empty()) {
        std::cout << "错误：无法读取图像文件！请确保 'image.jpg' 文件存在于程序运行目录中。" << std::endl;
        return -1;
    }
    
    // 转换为灰度图
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    
    // 显示原图和灰度图
    cv::imshow("原图", image);
    cv::imshow("灰度图", gray);
    
    // 等待按键
    cv::waitKey(0);
    
    return 0;
}