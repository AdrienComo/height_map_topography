#ifndef HEIGHTMAPS_GRAYSCALECONVERT_H
#define HEIGHTMAPS_GRAYSCALECONVERT_H

#include <string>
#include <vector>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class GrayscaleConvert {
public :
    GrayscaleConvert(std::string, std::string);
    void initIMGS();
    void computeSides();

    //TOP - BOTTOM
    void computeWidth();
    void computeHeight(unsigned);
    void drawTopBottom();

    //LEFT - RIGHT
    void computeHeight();
    void computeWidth(unsigned);
    void drawLeftRight();

    unsigned findMax(unsigned, unsigned);

    void display();
    void save();

private:
    unsigned timeWindowON = 3000;
    std::string imgPath, savePath; //image path + save path
    cv::Mat IMG, sideIMG_topBottom, sideIMG_leftRight; //cv::Mat of original and both side images
    unsigned IMG_width, IMG_height; //width & height of original image

    std::vector<unsigned> mapHeightTopBottom; //height map TOP BOTTOM
    std::vector<unsigned> mapHeightLeftRight; //height map LEFT RIGHT
};

#endif //HEIGHTMAPS_GRAYSCALECONVERT_H
