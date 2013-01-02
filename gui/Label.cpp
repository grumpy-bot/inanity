#include "Label.hpp"
#include "Visualizer.hpp"
#include "Visuals.hpp"
#include "Notifications.hpp"

Label::Label(ptr<Visualizer> visualizer) : Element(visualizer)
{
}

const String& Label::GetText() const
{
	return text;
}

void Label::SetText(const String& text)
{
	this->text = text;
}

void Label::Draw(Visualizer* visualizer, Position offset)
{
	offset += position;
	visualizer->DrawRectText(VisualFonts::Label, text, offset.x, offset.y, offset.x + size.x, offset.y + size.y);
}