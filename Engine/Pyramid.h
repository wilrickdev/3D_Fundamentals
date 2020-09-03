#pragma once

#include <vector>
#include "IndexedLineList.h"
#include "Vec3.h"

class Pyramid
{
public:
	Pyramid(float size)
	{
		const float side = size / 2.0f;
		vertices.emplace_back(-side, -side, side);  // L front
		vertices.emplace_back(side, -side, side);   // R front
		vertices.emplace_back(-side, -side, -side); // L back
		vertices.emplace_back(side, -side, -side);  // R back
		vertices.emplace_back(0.0, side, 0.0f);
	}

	IndexedLineList GetLines() const
	{
		return {
			vertices,{
				0,1, 1,3, 3,2, 2,0,
				0,4, 1,4, 2,4, 3,4
			}
		};
	}
private:
	std::vector<Vec3> vertices;
};