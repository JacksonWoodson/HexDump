#include "Block.h"
#include <iomanip>

using namespace std;

HexBlock::HexBlock() : fBuffer(), fSize(16)
{}                                                                          

istream& HexBlock::read(istream& aIStream)
{
	// read next 16 bytes, must cast to (char*)
	aIStream.read((char*)fBuffer, 16);                                    
	fSize = aIStream.gcount();                                            

	return aIStream;                                                      
}

unsigned long HexBlock::size() const
{
	return fSize;                                                         
}

ostream& operator<<(ostream& aOStream, const HexBlock& aObject)
{
	// output hex group
	for (long i = 0; i < aObject.fSize; i++)                              
	{
		aOStream << " " << setw(2) << setfill('0') << hex
			<< (int)aObject.fBuffer[i];                                
		if (i == 7)
			aOStream << " |";                                          
	}

	// output padding, if necessary
	if (aObject.fSize < 8)
		aOStream << "  ";                                                  

	for (long i = aObject.fSize; i < 16; i++)
		aOStream << "   ";                                                 
																		
	aOStream << "  ";                                                       

	for (long i = 0; i < aObject.fSize; i++)                              
	{
		aOStream << (!isgraph(aObject.fBuffer[i]) ? '.' :
			(char)aObject.fBuffer[i]);     
	}
	return aOStream;                                                      
}