#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;

void ShowImage(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::imshow("Loaded Image", image);
    cv::waitKey(0);
}

void DisplayVideo(){
    string videoPath = "example.mp4";
    cv::VideoCapture cap(videoPath);
    cv::Mat frame;
    while(true){
        cap >> frame;
        if(frame.empty()) break;
        cv::imshow("Video Playback", frame);
        if(cv::waitKey(30) >= 0) break;
    }
    cap.release();
    cv::destroyAllWindows();
}

void GetWebCam(){
    cv::VideoCapture cap(0);
    cv::Mat frame;
    while(true){
        cap >> frame;
        if(frame.empty()) break;
        cv::imshow("Webcam Feed", frame);
        if(cv::waitKey(30) >= 0) break;
    }
    cap.release();
    cv::destroyAllWindows();
}

void toGrayScale(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::imshow("Grayscale Image", grayImage);
    cv::waitKey(0);
}

void BlurImage(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(15,15), 5);
    cv::imshow("Blurred Image", blurredImage);
    cv::waitKey(0);
}

cv::Mat getCannyEdge(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::Mat grayImage, edges;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::Canny(grayImage, edges, 100, 200);
    cv::imshow("Canny Edges", edges);
    cv::waitKey(0);
    return edges;
}

void ErosionDilation(cv::Mat inputImage){
    cv::Mat binaryImage, erodedImage, dilatedImage;
    cv::threshold(inputImage, binaryImage, 128, 255, cv::THRESH_BINARY);
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::erode(binaryImage, erodedImage, element);
    cv::dilate(binaryImage, dilatedImage, element);
    cv::imshow("Eroded Image", erodedImage);
    cv::imshow("Dilated Image", dilatedImage);
    cv::waitKey(0);
}

void resizeImage(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::Mat resizedImage;
    cv::resize(image, resizedImage, cv::Size(), 0.5, 0.5, cv::INTER_LINEAR);
    cv::imshow("Resized Image", resizedImage);
    cv::waitKey(0);
}

void getROI(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::Rect roi(50, 50, 200, 200); // x, y, width, height
    cv::Mat imageROI = image(roi);
    cv::imshow("Region of Interest", imageROI);
    cv::waitKey(0);
}

void drawShapes(){
    cv::Mat canvas(400,400,CV_8UC3,cv::Scalar(0,255,255));
    cv::circle(canvas, cv::Point(100,100), 50, cv::Scalar(0,255,0), -1);
    cv::rectangle(canvas, cv::Point(200,50), cv::Point(300,150), cv::Scalar(255,0,0), 3);
    cv::line(canvas, cv::Point(50,300), cv::Point(350,300), cv::Scalar(0,0,255), 2);
    cv::imshow("Shapes", canvas);
    cv::waitKey(0);
}

// helper struct + callback
struct TrackbarData {
    int *hmin, *hmax, *smin, *smax, *vmin, *vmax;
    const char *winName;
};

void on_trackbar(int, void* userdata) {
    TrackbarData* d = static_cast<TrackbarData*>(userdata);
    *(d->hmin) = cv::getTrackbarPos("Lower Hue", d->winName);
    *(d->hmax) = cv::getTrackbarPos("Upper Hue", d->winName);
    *(d->smin) = cv::getTrackbarPos("Lower Sat", d->winName);
    *(d->smax) = cv::getTrackbarPos("Upper Sat", d->winName);
    *(d->vmin) = cv::getTrackbarPos("Lower Val", d->winName);
    *(d->vmax) = cv::getTrackbarPos("Upper Val", d->winName);
}

void detectColor(){
    string imagePath = "example.png";
    cv::Mat image = cv::imread(imagePath);
    cv::Mat hsvImage, mask;
    int hmin = 35, smin = 100, vmin = 100;
    int hmax = 85, smax = 255, vmax = 255;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    const char* win = "Trackbar";
    cv::namedWindow(win, cv::WINDOW_AUTOSIZE);

    // Use NULL for the value pointer (deprecated to pass variable address)
    TrackbarData tb{ &hmin, &hmax, &smin, &smax, &vmin, &vmax, win };
    cv::createTrackbar("Lower Hue",  win, NULL, 179, on_trackbar, &tb);
    cv::createTrackbar("Upper Hue",  win, NULL, 179, on_trackbar, &tb);
    cv::createTrackbar("Lower Sat",  win, NULL, 255, on_trackbar, &tb);
    cv::createTrackbar("Upper Sat",  win, NULL, 255, on_trackbar, &tb);
    cv::createTrackbar("Lower Val",  win, NULL, 255, on_trackbar, &tb);
    cv::createTrackbar("Upper Val",  win, NULL, 255, on_trackbar, &tb);

    // Initialize positions to desired defaults
    cv::setTrackbarPos("Lower Hue", win, hmin);
    cv::setTrackbarPos("Upper Hue", win, hmax);
    cv::setTrackbarPos("Lower Sat", win, smin);
    cv::setTrackbarPos("Upper Sat", win, smax);
    cv::setTrackbarPos("Lower Val", win, vmin);
    cv::setTrackbarPos("Upper Val", win, vmax);

    while(true){
        cv::imshow("HSV Image", hsvImage);
        cv::Scalar lowerBound(hmin, smin, vmin);
        cv::Scalar upperBound(hmax, smax, vmax);
        cv::inRange(hsvImage, lowerBound, upperBound, mask);
        cv::imshow("Color Detection Mask", mask);

        int key = cv::waitKey(1);
        if(key == 27) break; // ESC to exit
    }

    cv::destroyAllWindows();
}

int main(){
    detectColor();
    return 0;
}