#include "NightVision.h"
#include "Utils/ResourceManager/ResourceManager.h"
#include "Utils/JsonGlmHelpers.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/Material.h"

NightVision::NightVision() :
	PostProcessingLayer::Effect(),
	_nvVec(glm::vec3(0.8f, 0.3f, 0.1f))
{
	Name = "Night Vision Effect";
	_format = RenderTargetType::ColorRgb8;

	_shader = ResourceManager::CreateAsset<ShaderProgram>(std::unordered_map<ShaderPartType, std::string>{
		{ ShaderPartType::Vertex, "shaders/vertex_shaders/fullscreen_quad.glsl" },
		{ ShaderPartType::Fragment, "shaders/fragment_shaders/post_effects/night_vision.glsl" }
	});
}

NightVision::~NightVision() = default;

void NightVision::Apply(const Framebuffer::Sptr& gBuffer)
{
	_shader->Bind();
	_shader->SetUniform("u_nvVec", _nvVec);
}

void NightVision::RenderImGui()
{


}

NightVision::Sptr NightVision::FromJson(const nlohmann::json& data)
{
	return NightVision::Sptr();
}

nlohmann::json NightVision::ToJson() const
{
	return nlohmann::json();
}
