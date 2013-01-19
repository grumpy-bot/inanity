#ifndef ___INANITY_GRAPHICS_GEOMETRY_HPP___
#define ___INANITY_GRAPHICS_GEOMETRY_HPP___

#include "graphics.hpp"
#include "../scripting_decl.hpp"

BEGIN_INANITY

class InputStream;
class OutputStream;

END_INANITY

BEGIN_INANITY_GRAPHICS

class VertexBuffer;
class IndexBuffer;

/// Класс геометрии.
/** Просто объединяет вершинный и индексный буферы. */
class Geometry : public Object
{
private:
	ptr<VertexBuffer> vertexBuffer;
	ptr<IndexBuffer> indexBuffer;

public:
	Geometry(ptr<VertexBuffer> vertexBuffer, ptr<IndexBuffer> indexBuffer);

	ptr<VertexBuffer> GetVertexBuffer() const;
	ptr<IndexBuffer> GetIndexBuffer() const;

	void Serialize(ptr<OutputStream> outputStream) const;
	static ptr<Geometry> Deserialize(ptr<InputStream> inputStream);

	SCRIPTABLE_CLASS(Geometry);
};

END_INANITY_GRAPHICS

#endif
