#ifndef ___INANITY_GUI_FONT_FACE_HPP___
#define ___INANITY_GUI_FONT_FACE_HPP___

#include "gui.hpp"

BEGIN_INANITY_GUI

class FontShape;
class Canvas;
class FontGlyphs;

/// Abstract font face class.
class FontFace : public Object
{
public:
	/// Create font shape for the given font size.
	virtual ptr<FontShape> CreateShape(int size) = 0;
	/// Create font glyphs for the given font size.
	/** Size in pixels. */
	virtual ptr<FontGlyphs> CreateGlyphs(Canvas* canvas, int size) = 0;
};

END_INANITY_GUI

#endif
