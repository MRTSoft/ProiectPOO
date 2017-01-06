#include "App.h"

App * App::getInstance()
{
	if (!m_isInstantiated)
	{
		m_singleApp = new App();
		m_isInstantiated = true;
	}
	return m_singleApp;
}

App::~App()
{
	m_isInstantiated = false;
}
