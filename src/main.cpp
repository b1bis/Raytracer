#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Vec3.hpp"
#include "Ray.hpp"
#include "Color.hpp"
#include "HittableList.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"	

Color ComputeColor(const Ray& ray, const Hittable& scene, int depth)
{
	if (depth <= 0)
		return Color(0, 0, 0);
	HitInfo info;
	if (scene.Hit(ray, 0.001, std::numeric_limits<double>::infinity(), info))
	{
		Ray scattered;
		Color attenuation;
		if (info.material->Scatter(ray, info, attenuation, scattered))
			return attenuation * ComputeColor(scattered, scene, depth-1);
		return Color(0, 0, 0);
	}
	Vec3 unitDirection = ray.GetDirection();
	unitDirection.Normalize();
	double t = 0.5 * (unitDirection.GetY() + 1);
	return (1 - t) * Color(1, 1, 1) + t * Color(0.5, 0.7, 1.0);
}

int main(int argc, char** argv)
{
	std::ofstream file{"output.ppm", std::ios::trunc};

	std::ostream& progress = std::cerr;
	std::ostream& output = file;

	constexpr double ratio = 16.0 / 9.0;
	constexpr std::size_t imageWidth = 1000;
	constexpr std::size_t imageHeight = static_cast<std::size_t>(imageWidth / ratio);
	constexpr unsigned samplePerPixel = 50;
	constexpr int maxDepth = 50;

	constexpr double viewportHeight = 2.0;
	constexpr double focalLenght = 1.0;
	Camera camera{ ratio, viewportHeight, focalLenght };

	output << "P3" << std::endl << imageWidth << ' ' << imageHeight
		<< std::endl << "255" << std::endl;

	HittableList scene;

	std::shared_ptr<Material> groundMaterial = std::make_shared<Metal>(Color(0.8, 0.8, 0));
	std::shared_ptr<Material> leftMaterial	 = std::make_shared<Metal>(Color(0.7, 0.3, 0.3));
	std::shared_ptr<Material> centerMaterial = std::make_shared<Metal>(Color(0.0, 0.8, 0.8));
	std::shared_ptr<Material> rightMaterial	 = std::make_shared<Metal>(Color(0.8, 0.6, 0.2));

	scene.Add(std::make_shared<Sphere>(Vec3(0, -100.5, -1), 100, groundMaterial));
	scene.Add(std::make_shared<Sphere>(Vec3(-1, 0, -1), 0.5, leftMaterial));
	scene.Add(std::make_shared<Sphere>(Vec3(0, 0, -1), 0.5, centerMaterial));
	scene.Add(std::make_shared<Sphere>(Vec3(1, 0, -1), 0.5, rightMaterial));
	

	std::default_random_engine engine(static_cast<unsigned>(std::time(nullptr)));
	std::uniform_real_distribution<double> dis(0.0, 1.0);
	std::vector<double> pregenerate;
	constexpr std::size_t pregenerateNumbers = 10000;

	for (std::size_t i = 0; i < pregenerateNumbers; ++i)
	{
		pregenerate.push_back(dis(engine));
	}

	auto first = pregenerate.begin();

	for (std::size_t y = imageHeight; y > 0; --y)
	{
		progress << "Scanline remaining : " << y << std::endl;
		for (std::size_t x = 0; x < imageWidth; ++x)
		{
			Color pixelColor;
			for (std::size_t s = 0; s < samplePerPixel; ++s)
			{
				double factorX = static_cast<double>(x + *first) / (imageWidth - 1);
				if (first + 1 == pregenerate.end()) first = pregenerate.begin();

				double factorY = static_cast<double>(y + *(first + 1)) / (imageHeight - 1);
				if (first + 2 == pregenerate.end()) first = pregenerate.begin();
				first += 2;
				pixelColor += ComputeColor(camera.GetRay(factorX, factorY), scene, maxDepth);
			}
			pixelColor.WritePPM(output, samplePerPixel);
			output << std::endl;
		}
	}

	progress << "Done." << std::endl;

	return EXIT_SUCCESS;
}