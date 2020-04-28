#ifndef SHAPE_H
#define SHAPE_H

#include <Eigen/Dense>



//SOURCE  https://github.com/cemuyuk/RayTracing


//namespace
namespace Raytracer148 {
	struct Ray {
		//Eigen vars	
		Eigen::Vector3d origin, direction;
	};
	class Shape;
	struct HitRecord {
		
		Eigen::Vector3d position, normal;
		double t;
		Shape* sh=nullptr;
	};

	class Shape {
	public:
		
		Eigen::Vector3d ka,kd,ks;
		
		virtual ~Shape(){}
		
		virtual HitRecord intersect(const Ray &ray) = 0;  
	};
}

#endif
