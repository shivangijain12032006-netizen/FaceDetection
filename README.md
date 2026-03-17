# Face Detection

This is a C++ project using OpenCV that detects human faces from webcam input.  
It highlights detected faces and displays "Face Found" when at least one face is detected.

## Features
- Real-time webcam face detection
- Draws rectangles around detected faces
- Displays "Face Found" message when faces are present

## Requirements
- Mac or Linux
- OpenCV installed
- C++17 compatible compiler (clang++)

## How to Run
1. Compile with OpenCV flags:

   ```bash
   clang++ -std=c++17 FaceDetection.cpp -o FaceDetection `pkg-config --cflags --libs opencv4`


