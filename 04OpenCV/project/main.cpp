#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //!_CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <cstdlib>

#include <algorithm>
#include <iostream>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "hw1/hw1_tool.hpp"

int main(int argc, char** argv)
{
	const int pic_times = 6;
	// read light matrix from file
	std::string Light_path{ "../test/bunny/LightSource.txt" };
	auto text = hw1::txtfile(Light_path);
	auto light = hw1::read_light(Light_path);

	// set light matrix
	auto light_mat = cv::Mat(light.size(), light[0].size(), CV_32F);
	for (int row = 0; row < light.size(); ++row) {
		for (int col = 0; col < light[0].size(); ++col) {
			light_mat.at<float>(row, col) = light[row][col];
		}
	}

	// get pseudo inverse of light matrix
	auto light_inv = cv::Mat(light_mat.cols, light_mat.rows, CV_32F);
	// not implement yet...
	//light_inv = hw1::pseudo_inverse(light_mat);

	

	// reading 6 picture datas
	std::vector<std::string> path_of_pictures;
	path_of_pictures.reserve(pic_times);
	std::string bmp_dir{ "../test/bunny/pic" };
	for (auto i = 0; i < pic_times;++i) {
		std::string temp{ bmp_dir + std::to_string(i+1) + ".bmp" };
		path_of_pictures.push_back(std::move(temp));
	}
	
	std::vector<cv::Mat> images;
	images.reserve(pic_times);
	for (auto img_path : path_of_pictures) {
		images.emplace_back(cv::imread(img_path.c_str(), cv::IMREAD_GRAYSCALE));
	}
	

	
	auto Image = cv::imread("../test/bunny/pic1.bmp", cv::IMREAD_GRAYSCALE);
	auto tempImage = Image.clone();
	decltype(Image) smallImage(Image.rows / 2, Image.cols / 2, CV_8U);
		
	for (int rowIndex = 0; rowIndex < smallImage.rows; rowIndex++) {
		for (int colIndex = 0; colIndex < smallImage.cols; colIndex++) {
			smallImage.at<uchar>(rowIndex, colIndex) = tempImage.at<uchar>(rowIndex * 2, colIndex * 2);
		}
	}

	auto smallImageT = cv::Mat(smallImage.rows, smallImage.cols, CV_8U);
	cv::transpose(smallImage, smallImageT);
	cv::Mat temp = smallImage.mul(smallImageT);


	for (int rowIndex = 0; rowIndex < temp.rows; rowIndex++) {
		for (int colIndex = 0; colIndex < temp.cols; colIndex++) {
			std::cout << temp.at<uchar>(rowIndex, colIndex);
		}
	}
	decltype(tempImage) result(tempImage.rows + smallImage.rows, tempImage.cols, CV_8U, cv::Scalar(0));
	tempImage.copyTo(result(cv::Rect(0, 0, tempImage.cols, tempImage.rows)));
	smallImage.copyTo(result(cv::Rect(0, tempImage.rows, smallImage.cols, smallImage.rows)));

	cv::imshow("CV", result);
	cv::waitKey();
	
	system("PAUSE");
}