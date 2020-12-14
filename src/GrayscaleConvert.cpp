#include "GrayscaleConvert.h"

GrayscaleConvert::GrayscaleConvert(std::string _imgPath, std::string _savePath) {
    imgPath  = _imgPath;
    savePath = _savePath;
    initIMGS();
}

void GrayscaleConvert::initIMGS() {
    IMG = cv::imread(imgPath, 1);
    if(!IMG.data) {
        std::cout <<  "Could not open image" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    IMG_width  = IMG.cols;
    IMG_height = IMG.rows;

    mapHeightTopBottom.reserve(IMG_width);
    mapHeightLeftRight.reserve(IMG_height);
    std::fill(mapHeightTopBottom.begin(),mapHeightTopBottom.end(),0);
    std::fill(mapHeightLeftRight.begin(),mapHeightLeftRight.end(),0);

    computeSides();
}

void GrayscaleConvert::computeSides() {
    //TOP-BOTTOM
    sideIMG_leftRight = cv::Mat(cv::Size(IMG_width+1,255), CV_8UC3, cv::Scalar(0,0,0));
    computeWidth();
    drawLeftRight();

    //LEFT-RIGHT
    sideIMG_topBottom = cv::Mat(cv::Size(255,IMG_height+1), CV_8UC3, cv::Scalar(0,0,0));
    computeHeight();
    drawTopBottom();

    display();
    save();
}

//LEFT - RIGHT //
void GrayscaleConvert::computeWidth() {
    for(unsigned x=0;x<IMG_width;++x)
        computeHeight(x);
}

void GrayscaleConvert::computeHeight(unsigned x) {
    unsigned max = 0;
    for (unsigned y=0;y<IMG_height;++y) {
        cv::Vec3b col = IMG.at<cv::Vec3b>(y, x);
        max = std::max(max, unsigned(col[0]));
    }
    mapHeightLeftRight.push_back(max);
}

void GrayscaleConvert::drawLeftRight() {
    for(unsigned x=0;x<IMG_width;++x)
        for(unsigned c=0;c<3;++c)
            sideIMG_leftRight.at<cv::Vec3b>(255 - mapHeightLeftRight.at(x), x)[c] = 255;
}

//TOP - BOTTOM //
void GrayscaleConvert::computeHeight() {
    for(unsigned y=0;y<IMG_height;++y)
        computeWidth(y);
}

void GrayscaleConvert::computeWidth(unsigned y) {
    unsigned max = 0;
    for (unsigned x=0;x<IMG_width;++x) {
        cv::Vec3b col = IMG.at<cv::Vec3b>(y, x);
        max = std::max(max, unsigned(col[0]));
    }
    mapHeightTopBottom.push_back(max);
}

void GrayscaleConvert::drawTopBottom() {
    for(unsigned y=0;y<IMG_height;++y)
        for(unsigned c=0;c<3;++c)
            sideIMG_topBottom.at<cv::Vec3b>(y, mapHeightTopBottom.at(y))[c] = 255;
}

void GrayscaleConvert::display() {
    /* ORIGINAL */
    cv::namedWindow("Original", cv::WINDOW_NORMAL);
    cv::resizeWindow("Original", IMG_width, IMG_height);
    cv::imshow("Original", IMG);
    cv::waitKey(timeWindowON);
    /* ----- */

    /* LEFT - RIGHT */
    cv::namedWindow("LEFT - RIGHT", cv::WINDOW_NORMAL);
    cv::resizeWindow("LEFT - RIGHT", IMG_width, 255);
    cv::imshow("LEFT - RIGHT", sideIMG_leftRight);
    cv::waitKey(timeWindowON);
    /* ----- */

    /* TOP-BOTTOM */
    cv::namedWindow("TOP-BOTTOM", cv::WINDOW_NORMAL);
    cv::resizeWindow("TOP-BOTTOM", 255, IMG_height);
    cv::imshow("TOP-BOTTOM", sideIMG_topBottom);
    cv::waitKey(timeWindowON);
    /* ----- */
}

void GrayscaleConvert::save() {
    std::string str = imgPath.substr(0, imgPath.find(".", 0));
    std::size_t found = str.find_last_of("/\\");
    str = str.substr(found+1);

    cv::imwrite(savePath + str + "_leftRight.png",sideIMG_leftRight);
    cv::imwrite(savePath + str + "_topBottom.png",sideIMG_topBottom);
}

