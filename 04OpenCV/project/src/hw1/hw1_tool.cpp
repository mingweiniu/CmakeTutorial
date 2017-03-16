#include "..\..\include\hw1\hw1_tool.hpp"
#include <iostream>
#include <vector>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "hw1/hw1_tool.hpp"

std::vector<std::string> hw1::txtfile(std::string file_path)
{
	std::vector<std::string> content;
	std::ifstream file;
	file.open(file_path.c_str());

	std::stringstream read_streams;
	read_streams << file.rdbuf();
	file.close();

	auto buffer_chars = read_streams.str();
	std::string temp_chars;
	for (auto letter : buffer_chars) {
		if (letter == '\n')
			content.push_back(std::move(temp_chars));
		else
			temp_chars += letter;
	}
	return content;
}

std::vector<std::vector<float>> hw1::read_light(std::string file_path)
{

	std::cout << file_path << '\n';
	auto datas = hw1::txtfile(file_path);

	std::vector<std::vector<float>> lights;
	lights.reserve(datas.size());

	for (auto line : datas) {
		std::cout << '\t';
		if (line.find("(") < line.size()) {
			line.erase(line.begin(), line.begin() + line.find("(") + 1);
			std::vector<float> temp;
			temp.reserve(3);
			while (line.find(",") < line.size()) {
				std::string number(line, 0, line.find(","));
				temp.push_back(std::stof(number));
				line.erase(line.begin(), line.begin() + line.find(",") + 1);
			}
			if (line.find(")") < line.size()) {
				line.erase(line.find(")"));
				temp.push_back(std::stof(line));
			}
			std::cout << temp[0] << '\t' << temp[1] << '\t' << temp[2] << '\n';
			std::vector<float> light_vector{ temp[0], temp[1], temp[2] };
			lights.push_back(std::move(light_vector));
		}
	}
	std::cout << "end of file \n";
	return lights;
}

void hw1::printMat(cv::Mat matrix) {

	for (int rowIndex = 0; rowIndex < matrix.rows; rowIndex++) {
		std::cout << '\t';
		for (int colIndex = 0; colIndex < matrix.cols; colIndex++) {
			std::cout << matrix.at<float>(rowIndex, colIndex) << '\t';
		}
		std::cout << '\n';
	}

}
cv::Mat hw1::pseudo_inverse(cv::Mat input)
{
	// not implement yet...

	return cv::Mat();
}






