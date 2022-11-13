#pragma once

#include "CWidget.h"

namespace graphics
{
    class CButton : public CWidget
    {
private:
        std::string m_sLabel;
public:
        CButton();
        ~CButton();

        std::string getLabel() const;

        void setLabel(const std::string &sLabel);
    };
}