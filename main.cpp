//
// Created by sergsenta1995 on 06.10.16.
//

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
	cv::Mat image;
	image = cv::imread("/home/sergsenta1995/AIFIL/1.jpg");
	std::string name_image = "Binary image";
	cv::namedWindow(name_image);

	cv::imshow(name_image, image);

	cv::waitKey(0);

	return 0;
}
