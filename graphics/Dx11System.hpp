#ifndef ___INANITY_GRAPHICS_DX11_SYSTEM_HPP___
#define ___INANITY_GRAPHICS_DX11_SYSTEM_HPP___

#include "System.hpp"
#include "PixelFormat.hpp"
#include "PresentMode.hpp"
#include "d3d11.hpp"
#include "../ComPointer.hpp"
#include "../String.hpp"

BEGIN_INANITY_GRAPHICS

/// Графическая система, основанная на DirectX 11.
class Dx11System : public System
{
private:
	/// Фабрика объектов DXGI.
	ComPointer<IDXGIFactory> dxgiFactory;
	/// Адаптеры DXGI.
	std::vector<ptr<Adapter> > adapters;
	bool adaptersInitialized;

public:
	/// Преобразовать формат пикселей из общего перечисления в DXGI.
	static DXGI_FORMAT GetDXGIFormat(PixelFormat format);
	/// Преобразовать режим экрана в структуру для DXGI.
	static DXGI_MODE_DESC GetModeDesc(const PresentMode& mode);
	/// Преобразовать номер сематники атрибута в строку.
	static String GetSemanticString(int semantic);

	Dx11System();

	// методы System
	const std::vector<ptr<Adapter> >& GetAdapters();
	ptr<Window> CreateDefaultWindow();
	ptr<Device> CreatePrimaryDevice();
	ptr<ShaderCompiler> CreateShaderCompiler();
	ptr<Shaders::ShaderGenerator> CreateShaderGenerator();

	/// Получить фабрику DXGI.
	/** Создаёт её, если ещё не создана. */
	IDXGIFactory* GetDXGIFactory();
};

END_INANITY_GRAPHICS

#endif
