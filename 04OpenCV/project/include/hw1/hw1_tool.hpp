#ifndef HW1_TOOL_HPP
#define HW1_TOOL_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

namespace hw1{
	std::vector<std::string> txtfile(std::string file_path);

	std::vector<std::vector<float>> read_light(std::string file_path);

	void printMat(cv::Mat matrix);

	cv::Mat pseudo_inverse(cv::Mat input);

	
	
	
}

#endif // !HW1_TOOL_HPP