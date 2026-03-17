#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    VideoCapture video(0); // 0 = default webcam
    if(!video.isOpened()){
        cout << "Cannot open webcam" << endl;
        return -1;
    }

    CascadeClassifier facedetect;
    if(!facedetect.load("haarcascade_frontalface_default.xml")){
        cout << "Cannot load XML file" << endl;
        return -1;
    }

    Mat img;

    while (true) {
        video.read(img);
        if(img.empty()) continue;

        vector<Rect> faces;
        facedetect.detectMultiScale(img, faces, 1.3, 5);

        for (auto &face : faces) {
            rectangle(img, face.tl(), face.br(), Scalar(50, 50, 255), 3);
        }

        imshow("Face Detection", img);
        if (waitKey(1) == 27) break; // ESC to exit
    }

    return 0;
}