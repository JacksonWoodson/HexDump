#include "Dump.h"

#include <iostream>
#include <iomanip>

using namespace std;

bool HexDump::open(const std::string& aInputFileName)
{
	fInput.open(aInputFileName, ifstream::binary);                            

	if (fInput.fail())                                                        
	{
		cerr << "Cannot open input file: " << aInputFileName << endl;
		return false;                                                           
	}

	return true;                                                                
}

void HexDump::close()
{
	fInput.close();                                                             
}

void HexDump::processInput()
{
	unsigned long lCount = 0L;                                                  

	cout << uppercase; 	
	do                                                                          
	{
		// fetch next data block
		fData.read(fInput);                                                   	

		if (fData.size() == 0)
			break

		cout << setw(8) << setfill('0') << hex << lCount << ": "
		cout << fData << endl;                                                  
		
		lCount += 16L;                                                          																			
	} while (fData.size() == 16);                                             
}

bool HexDump::operator()(const std::string& aInputFileName)
{
	if (open(aInputFileName))                                               
	{
		processInput();
		close();
		return true;                                                        
	}
	return false;                                                               
}