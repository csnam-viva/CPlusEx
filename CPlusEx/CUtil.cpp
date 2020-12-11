#include "pch.h"
#include "CUtil.h"


void CUtil::csDebugOutput(char* format, ...)
{
	char buf[1024];
	va_list marker;

	va_start(marker, format);
	vsprintf_s(buf,sizeof(buf), format, marker);
	OutputDebugString(buf);
}