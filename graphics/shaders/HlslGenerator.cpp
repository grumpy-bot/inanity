#include "HlslGenerator.hpp"
#include "HlslGeneratorInstance.hpp"
#include "../ShaderSource.hpp"
#include "Expression.hpp"
#include "AttributeNode.hpp"
#include "TempNode.hpp"
#include "UniformGroup.hpp"
#include "UniformNode.hpp"
#include "SamplerNode.hpp"
#include "TransitionalNode.hpp"
#include "OperationNode.hpp"

ptr<ShaderSource> HlslGenerator::Generate(Expression code, ShaderType shaderType)
{
	HlslGeneratorInstance instance(code.GetNode(), shaderType);

	return instance.Generate();
}