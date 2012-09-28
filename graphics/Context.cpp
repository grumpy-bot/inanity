#include "Context.hpp"
#include "RenderBuffer.hpp"
#include "DepthStencilBuffer.hpp"
#include "Texture.hpp"
#include "Sampler.hpp"
#include "UniformBuffer.hpp"
#include "VertexShader.hpp"
#include "PixelShader.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"

Context::Context()
{
}

const ContextState& Context::GetBoundState() const
{
	return boundState;
}

ContextState& Context::GetTargetState()
{
	return targetState;
}
