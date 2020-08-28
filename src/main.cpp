#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::ofstream file {"output.ppm", std::ios::trunc};

	std::ostream& output = file;

	const std::size_t imageWidth = 256;
	const std::size_t imageHeight = 256;

	output << "P3" << std::endl << imageWidth << ' ' << imageHeight 
		<< std::endl << "255" << std::endl;

	for (std::size_t y = 0; y < imageHeight; ++y)
	{
		for (std::size_t x = 0; x < imageWidth; ++x)
		{
			double r = static_cast<double>(x) / (imageWidth);
			double g = static_cast<double>(y) / (imageHeight);
			double b = 0.25;
			output << static_cast<int>(r * 255.999) << ' '
				<< static_cast<int>(g * 255.999) << ' '
				<< static_cast<int>(b * 255.999) << std::endl;
		}
	}

	return EXIT_SUCCESS;
}