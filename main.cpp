//
// Created by sergsenta1995 on 06.10.16.
//

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


/**
 * @brief Вычисляет ограничивающие прямоугольники из контуров.
 * @param image Входное изображение.
 * @return Вектор ограничивающих прямоугольников.
 */
std::vector<cv::Rect> copmute_bounding_rects(const cv::Mat &image)
{
	std::vector<std::vector<cv::Point>> contours;
	cv::Mat invert_image;
	cv::threshold(image, invert_image, 70, 255, CV_THRESH_BINARY_INV);
	cv::findContours(
			invert_image,
			contours,
			CV_RETR_EXTERNAL,
			CV_CHAIN_APPROX_SIMPLE);

	std::vector<cv::Rect> result;
	if (contours.size() == 0)
	{
		std::cout << "Contours not found." << std::endl;
		return result;
	}

	for (auto contour : contours)
	{
		cv::Rect bounding_rect = cv::boundingRect(contour);
		result.push_back(bounding_rect);
	}

	return result;
}


/**
 * @brief Рисует прямоугольники на изображении.
 * @param bounding_rects Вектор (ограничивающих) прямоугольников.
 * @param image Входное изображение, на котором будем рисовать.
 */
void draw_bounding_rects(const std::vector<cv::Rect> &bounding_rects, const cv::Mat &image)
{
	std::string name_bounding_rects_image = "Bounding rect";
	cv::namedWindow(name_bounding_rects_image);
	cv::Mat result_image = image.clone();
	for (auto rect : bounding_rects)
		cv::rectangle(result_image, rect, cv::Scalar(50));

	cv::imshow(name_bounding_rects_image, result_image);
}


/**
 * @brief Находит на чёрно-блом изображении символы, и возвращает их ограничивающие прямоугольники.
 * @param argc Количество аргументов командной строки - 2 (первый по умолчанию).
 * @param argv Аргументы командной строки: необходимо передать путь к изображению.
 */
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error. Command line argument < 2." << std::endl;
		std::cout << "Program aborted." << std::endl;
		return 0;
	}
	cv::Mat image;
	image = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	if (image.empty() == true)
	{
		std::cout << "Error. Image not found." << std::endl;
		std::cout << "Program aborted." << std::endl;
		return 0;
	}
	std::string name_image = "Binary image";
	cv::namedWindow(name_image);
	cv::imshow(name_image, image);

	std::vector<cv::Rect> bounding_rects = copmute_bounding_rects(image);
	draw_bounding_rects(bounding_rects, image);

	cv::waitKey(0);

	return 0;
}
