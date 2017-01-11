#include "App.h"
#include "tinyxml2.h"

void App::loadXmlData(const char * pXmlName)
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError xmlErr;
	xmlErr = xmlDoc.LoadFile(pXmlName);

	if (xmlErr = tinyxml2::XMLError::XML_SUCCESS)
	{
		
	}
	else
	{
		//TODO Error handling code here
	}

}
