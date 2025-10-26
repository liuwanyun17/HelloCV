#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;


int main (){
    string path="TrafficLight.mp4";
    VideoCapture cap(path);
    Mat img,imgHSV,red_mask01,red_mask02,green_mask,red_mask;
    double fps = cap.get(CAP_PROP_FPS);
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);

    VideoWriter writer("result.avi", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, Size(width, height));
   while(true){
    cap.read(img);
    if(img.empty()) break;  
    
    cvtColor(img,imgHSV,COLOR_BGR2HSV);
    Scalar redmin01(0,100,100);
    Scalar redmax01(10,255,255);
    Scalar redmin02(160,100,100);  
    Scalar redmax02(180,255,255); 
    Scalar greenmin(35 ,50,50);
    Scalar greenmax(90,255,255);
    inRange(imgHSV,redmin01,redmax01,red_mask01);
    inRange(imgHSV,redmin02,redmax02,red_mask02);
    inRange(imgHSV,greenmin,greenmax,green_mask);
    red_mask = red_mask01 | red_mask02; 

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    
    
    morphologyEx(red_mask, red_mask, MORPH_CLOSE, kernel);  
    morphologyEx(red_mask, red_mask, MORPH_OPEN, kernel);   
    
    
    morphologyEx(green_mask, green_mask, MORPH_CLOSE, kernel);
    morphologyEx(green_mask, green_mask, MORPH_OPEN, kernel);
    GaussianBlur(red_mask, red_mask, Size(5, 5), 0);
    GaussianBlur(green_mask, green_mask, Size(9, 9), 0);

    imshow("mask",green_mask);
    
    vector<vector<Point>> red_contours, green_contours;
    vector<Vec4i> red_hierarchy, green_hierarchy;
    
    findContours(red_mask,red_contours,red_hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    for(int i=0;i<red_contours.size();i++){
       int area=contourArea(red_contours[i]);
       if(area>5000){
        vector<Point> conPoly;  
        float peri=arcLength(red_contours[i],true);
        approxPolyDP(red_contours[i],conPoly,0.02*peri,true);
        
        
        if(conPoly.size()>5){
            
            Rect boundRect=boundingRect(conPoly); 
            float aspRatio=(float)boundRect.width/(float)boundRect.height;
            if (aspRatio>0.9&&aspRatio<1.05){
            rectangle(img,boundRect.tl(),boundRect.br(),Scalar(0,0,255),4); 
            putText(img,"Red",Point(200,200),FONT_HERSHEY_DUPLEX,2,Scalar(255,0,0),2);
            }
        }
       }
    }
    
    
    findContours(green_mask,green_contours,green_hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    for(int i=0;i<green_contours.size();i++){
       int area=contourArea(green_contours[i]);
       if(area>5000){
        vector<Point> conPoly;  
        float peri=arcLength(green_contours[i],true);
        approxPolyDP(green_contours[i],conPoly,0.02*peri,true);
        
        if(conPoly.size()>5){
            Rect boundRect=boundingRect(conPoly);
            float aspRatio=(float)boundRect.width/(float)boundRect.height;
            if (aspRatio>0.9&&aspRatio<1.05){
            rectangle(img,boundRect.tl(),boundRect.br(),Scalar(0,0,255),4); 
            putText(img,"Green",Point(200,200),FONT_HERSHEY_DUPLEX,2,Scalar(255,0,0),2);
            }
        }
       }
    }
   writer.write(img);
    
   imshow ("img",img);
   if(waitKey(33)==27) break;  
   }
return 0;
}
