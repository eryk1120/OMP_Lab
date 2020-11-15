#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

//function solving task6
cv::Mat task6(cv::Mat image)
{
  for (int c=image.cols/2-5 ; c<=image.cols/2+5 ; c++) // for iterating over columns
  {
    for (int r =image.rows/2-5 ; r <= image.rows/2+5 ; r++) // for iterating over rows
    {
        image.at<cv::Vec3b>(c,r)={0,0,255};     //changing value of vector at c,r position
    }
  }
  return image; //returning image with red square
}
//function solving task7
cv::Mat task7(cv::Mat image)
{
  for (int r=image.rows/2-5 ; r<=image.rows/2+5 ; r++)// for iterating over columns
  {
    cv::Vec3b* ptr = image.ptr<cv::Vec3b>(r); // getting pointer for column [c]
    for (int c = image.cols/2-5 ; c <= image.cols/2+5 ; c++)// for iterating over columns
    {
        ptr[c] = {0,0,255}; //changing value in r position in pointer at column c
    }
  }
  return image; //ret img
}
//function solving task8

//function solving task9
cv::Mat task9(cv::Mat image)
{
  cv::Mat upper=image.clone(); //cloning image to upper
//inverting upper side of image
  for(int r = 0; r < upper.rows/2; r++) {
         // We obtain a pointer to the beginning of row r
         cv::Vec3b* ptr = upper.ptr<cv::Vec3b>(r);

         for(int c = 0; c < upper.cols; c++) {
             // We invert the blue and red values of the pixel
             ptr[c] = cv::Vec3b(255-ptr[c][0], 255-ptr[c][1], 255-ptr[c][2]);
         }
     }
     //inverting left side
  cv::Mat left=image.clone(); //cloning image to left
  for (int c=0 ; c<=left.cols/2 ; c++) // for iterating over columns
    {
       for (int r =0 ; r < left.rows ; r++) // for iterating over rows
    {
       left.at<cv::Vec3b>(r,c)[0]=255-left.at<cv::Vec3b>(r,c)[0];//changing value of vector at c,r position
       left.at<cv::Vec3b>(r,c)[1]=255-left.at<cv::Vec3b>(r,c)[1];
       left.at<cv::Vec3b>(r,c)[2]=255-left.at<cv::Vec3b>(r,c)[2];
    }
  }
//medium of two
cv::Mat med=image.clone(); //cloning image to left
for (int c=0 ; c<med.cols ; c++) // basicly
  {
     for (int r =0 ; r < left.rows ; r++) // for iterating over rows
  {
     med.at<cv::Vec3b>(r,c)[0]=(left.at<cv::Vec3b>(r,c)[0]+255+upper.at<cv::Vec3b>(r,c)[0])/2;//changing value of vector at c,r position
     med.at<cv::Vec3b>(r,c)[1]=(left.at<cv::Vec3b>(r,c)[1]+255+upper.at<cv::Vec3b>(r,c)[1])/2;
     med.at<cv::Vec3b>(r,c)[2]=(left.at<cv::Vec3b>(r,c)[2]+255+upper.at<cv::Vec3b>(r,c)[2])/2;
  }
}
  return med;
}



int main( int argc, char** argv )
{
    // input part of the filename
    if( argc != 2)
    {
     std::cout <<" Usage: display_image ImageToLoadAndDisplay" << std::endl;
     return -1;
    }
    cv::Mat image;
    image = imread(argv[1], cv::IMREAD_COLOR); // Read the file
    if( image.empty() ) // Check for invalid input
    {
        std::cout << "Could not open or find the image" << std::endl ;
        return -1;
    }
    // end of  parsing the user input

    //execution of task 6
    // datatype in image.at<cv::Vec3b> defines datatype passed to cv::Mat::at
    // Vec3b is vector of unsigned chars with depth 3 (3 cause RGB)
    image = task9(image); //uncomment this line to





    cv::Mat resizedIMG;
    cv::namedWindow( "Display window" ); // Create a window for display.
    cv::resize(image, resizedIMG, cv::Size(600, 600)); //resizing image cause it doesnt fit in my screen
    //cv::resizeWindow("Display window" ,1000,1000);
    cv::imshow( "Display window",resizedIMG ); // Show our image inside it.
    cv::waitKey(0); // Wait for a keystroke in the window
    return 0;
}
