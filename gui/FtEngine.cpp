#include "FtEngine.hpp"
#include "FtFontFace.hpp"
#include "../File.hpp"
#include "../Exception.hpp"
#include <iostream>

BEGIN_INANITY_GUI

FtEngine::FtEngine()
{
	if(FT_Init_FreeType(&library))
		THROW("Can't init FreeType");
}

FtEngine::~FtEngine()
{
	FT_Done_FreeType(library);
}

ptr<FontFace> FtEngine::LoadFontFace(ptr<File> file)
{
	BEGIN_TRY();

	FT_Face face;
	if(FT_New_Memory_Face(library, (const FT_Byte*)file->GetData(), (FT_Long)file->GetSize(), 0, &face))
		THROW("Can't create font face");

	return NEW(FtFontFace(this, face, file));

	END_TRY("Can't load Freetype font");
}

END_INANITY_GUI
