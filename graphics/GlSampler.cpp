#include "GlSampler.hpp"
#include "GlSystem.hpp"
#include "../Exception.hpp"

GlSampler::GlSampler(GLuint samplerName) : samplerName(samplerName)
{
}

GlSampler::~GlSampler()
{
	glDeleteSamplers(1, &samplerName);
}

GLint GlSampler::ConvertWrap(Wrap wrap)
{
	switch(wrap)
	{
	case wrapRepeat:
		return GL_REPEAT;
	case wrapRepeatMirror:
		return GL_MIRRORED_REPEAT;
	case wrapClamp:
		return GL_CLAMP_TO_EDGE;
	case wrapBorder:
		return GL_CLAMP_TO_BORDER;
	}
	THROW_PRIMARY_EXCEPTION("Invalid wrap mode");
}

GLuint GlSampler::GetName() const
{
	return samplerName;
}

void GlSampler::Update()
{
	if(!dirty)
		return;

	try
	{
		// разобраться с фильтрацией уменьшения
		{
			GLint filterParam = -1;
			if(mipMapping)
				switch(minFilter)
				{
				case filterPoint:
					switch(mipFilter)
					{
					case filterPoint:
						filterParam = GL_NEAREST_MIPMAP_NEAREST;
						break;
					case filterLinear:
						filterParam = GL_NEAREST_MIPMAP_LINEAR;
						break;
					}
					break;
				case filterLinear:
					switch(mipFilter)
					{
					case filterPoint:
						filterParam = GL_LINEAR_MIPMAP_NEAREST;
						break;
					case filterLinear:
						filterParam = GL_LINEAR_MIPMAP_LINEAR;
						break;
					}
					break;
				}
			else
				switch(minFilter)
				{
				case filterPoint:
					filterParam = GL_NEAREST;
					break;
				case filterLinear:
					filterParam = GL_LINEAR;
					break;
				}
			if(filterParam == -1)
				THROW_PRIMARY_EXCEPTION("Invalid min or mip filter param");
			glSamplerParameteri(samplerName, GL_TEXTURE_MIN_FILTER, filterParam);
			GlSystem::CheckErrors("Can't set texture min filter");
		}

		// разобраться с фильтрацией увеличения
		{
			GLint filterParam = -1;
			switch(magFilter)
			{
			case filterPoint:
				filterParam = GL_NEAREST;
				break;
			case filterLinear:
				filterParam = GL_LINEAR;
				break;
			}
			if(filterParam == -1)
				THROW_PRIMARY_EXCEPTION("Invalid mag filter param");
			glSamplerParameteri(samplerName, GL_TEXTURE_MAG_FILTER, filterParam);
			GlSystem::CheckErrors("Can't set texture mag filter");
		}

		// установить режимы свёртки
		glSamplerParameteri(samplerName, GL_TEXTURE_WRAP_S, ConvertWrap(wrapU));
		GlSystem::CheckErrors("Can't set texture wrap U");
		glSamplerParameteri(samplerName, GL_TEXTURE_WRAP_T, ConvertWrap(wrapV));
		GlSystem::CheckErrors("Can't set texture wrap V");
		glSamplerParameteri(samplerName, GL_TEXTURE_WRAP_R, ConvertWrap(wrapW));
		GlSystem::CheckErrors("Can't set texture wrap W");

		// установить минимальный и максимальный LOD.
		glSamplerParameterf(samplerName, GL_TEXTURE_MIN_LOD, minLOD);
		GlSystem::CheckErrors("Can't set min LOD");
		glSamplerParameterf(samplerName, GL_TEXTURE_MAX_LOD, maxLOD);
		GlSystem::CheckErrors("Can't set max LOD");

		// установить цвет границы
		glSamplerParameterfv(samplerName, GL_TEXTURE_BORDER_COLOR, borderColor);
		GlSystem::CheckErrors("Can't set border color");
	}
	catch(Exception* exception)
	{
		THROW_SECONDARY_EXCEPTION("Can't update OpenGL sampler", exception);
	}
}