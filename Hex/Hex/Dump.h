#pragma once

#include "Block.h"

#include <fstream>
#include <string>

class HexDump
{
private:
	HexBlock fData;
	std::ifstream fInput;

public:

	// open input file
	bool open(const std::string& aInputFileName);

	// close input file
	void close();

	// generate hex dump to standard output. the method has to repeatedly read
	// a HexBlock (i.e., 16 bytes) and produce the corresponding hex dump line
	// consisting of offset and hex dump line for HexBlock object fData.
	// the method should utilize a do-while loop and run as long as the size
	// of fData is 16.
	void processInput();

	// make objects of type HexDump callable.
	// we use objects of type HexDump functions that take a file name
	// as parameter and return a Boolean value to indicate success or failure
	// of producing a hex dump to standard output. result is false only
	// if we could not open input
	bool operator()(const std::string& aInputFileName);
};

