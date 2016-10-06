//
// Created by sergsenta1995 on 06.10.16.
//

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

/**
 * @brief Вычисляет ограничивающие прямоугольники из контуров.
 * @param contours Вектор векторов точек, т. е. собственно контур.
 * @return Вектор ограничивающих прямоугольников.
 */
std::vector<cv::Rect> copmute_bounding_rects(const std::vector<std::vector<cv::Point>> &contours)
{
	std::vector<cv::Rect> result;

	for (auto i = 0; i < contours.size(); i++)
	{
		auto contour = contours[i];
		cv::Rect bounding_rect = cv::boundingRect(contour);
		result.push_back(bounding_rect);
	}

	return result;
}

int main(int argc, char** argv)
{
	cv::Mat image;
	image = cv::imread("/home/sergsenta1995/AIFIL/1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	std::string name_image = "Binary image";
	cv::namedWindow(name_image);
	cv::imshow(name_image, image);


	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(
			image.clone(),
			contours,
			CV_RETR_LIST,
			CV_CHAIN_APPROX_SIMPLE);

	if (contours.size() == 0)
	{
		std::cout << "Contours not found." << std::endl;
		cv::waitKey(0);
		return 0;
	}

	cv::waitKey(0);

	return 0;
}
