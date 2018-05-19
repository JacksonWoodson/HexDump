#pragma once

#include <istream>
#include <ostream>

class HexBlock
{
private:
	unsigned char fBuffer[16];
	unsigned long fSize;

public:

	// default constructor: set buffer elements to zero and size to 16
	HexBlock();

	// read up to 16 bytes (i.e. raw characters) into buffer
	// records the number of characters read in size (<= 16)
	std::istream& read(std::istream& aIStream);

	// getter to return characters in buffer
	unsigned long size() const;

	// formatted output operator: produces a hex dump line
	friend std::ostream& operator<<(std::ostream& aOStream, const HexBlock& aObject);
};
