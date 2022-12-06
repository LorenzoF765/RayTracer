#pragma once
#include "../Math/Color.h"
#include "../Math/Ray.h"

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;
};