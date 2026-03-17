#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Open default webcam (0). Change to 1 if using external webcam.
    VideoCapture video(0);
    if(!video.isOpened()){
        cout << "Cannot open webcam" << endl;
        return -1;
    }

    // Load Haar Cascade XML for face detection
    CascadeClassifier facedetect;
    if(!facedetect.load("haarcascade_frontalface_default.xml")){
        cout << "Cannot load XML file" << endl;
        return -1;
    }

    Mat img;

    while(true) {
        video.read(img);  // Capture frame
        if(img.empty()) continue;

        vector<Rect> faces;

        // Detect faces
        facedetect.detectMultiScale(img, faces, 1.1, 4);

        // Draw rectangles around each detected face
        for(auto &face : faces){
            rectangle(img, face.tl(), face.br(), Scalar(50,50,255), 3);
        }

        // Show "Face Found" if any face detected
        if(faces.size() > 0){
            putText(img, "Face Found", Point(10,50), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0,255,0), 2);
        }

        // Display the image
        imshow("Face Detection", img);

        // Press ESC to exit
        if(waitKey(1) == 27) break;
    }

    return 0;
}