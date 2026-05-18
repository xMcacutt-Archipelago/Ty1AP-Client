#include "pch.h"
#include "MusicRando.h"

typedef void(__cdecl* GenerateShuffleFn)(unsigned int);

void MusicRando::TriggerShuffle(std::string seedStr)
{
	HMODULE mrMod = GetModuleHandleA("Ty1 Music Rando.dll");
	if (!mrMod) {
		LoggerWindow::Log("Music Rando is enabled in yaml but the mod is not enabled. Please install and enable the Ty1 Music Rando mod.");
		return;
	}

	GenerateShuffleFn Shuffle = (GenerateShuffleFn)GetProcAddress(mrMod, "GenerateShuffleWithSeed");
	if (Shuffle) {
		std::hash<std::string> stringHasher;
		unsigned int seed = static_cast<unsigned int>(stringHasher(seedStr));
		Shuffle(seed);
	}
}
