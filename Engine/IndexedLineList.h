#pragma once
#include <vector>
#include "Vec3.h"
#include <cctype>

template<class T>
class IndexedLineList
{
private:
	std::vector<T> vertices;
	std::vector<size_t> indices;

public:
	IndexedLineList() = default;
	IndexedLineList(std::vector<T> verts_in, std::vector<size_t> indices_in)
		: vertices(std::move(verts_in))
		, indices(std::move(indices_in))
	{
		assert(vertices.size() > 1);
		assert((indices.size() % 2) == 0);
	};
	std::vector<T>& getVertices()  { return vertices; }
	std::vector<size_t>& getIndices()  { return indices; }

};
using IndexedLineList3I = IndexedLineList<Vei3>;
using IndexedLineList3F = IndexedLineList<Vec3>;