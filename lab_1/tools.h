#pragma once
#ifndef SICT_TOOLS_H__
#define SICT_TOOLS_H__

namespace sict {
	// Displays the user interface menu
	int menu();

	// Performs a fool-proof integer entry
	int getInt(int min, int max);

}
#endif // !__TOOLS_H__
