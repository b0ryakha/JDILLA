#include "GUI/CButton.h"
#include "GUI/CWidget.h"

graphics::CButton::CButton()
{
    this->setSize(graphics::CWidgetSettings::m_buttonSize.x, graphics::CWidgetSettings::m_buttonSize.y);
}

graphics::CButton::~CButton()
{

}