#ifndef __UTILS_H__
#define __UTILS_H__
//	Library includes


//	Local includes


const unsigned int END = (2^32) - 1;

struct ItemRegion
{
	ItemRegion()
	{
		XSize = 0;
		YSize = 0;
		XPos = END;
		YPos = END;
	}

	ItemRegion(const unsigned int& _XSize, const unsigned int& _YSize, const unsigned int& _XOffset, const unsigned int& _YOffset)
	{
		XSize = _XSize;
		YSize = _YSize;
		XPos = _XOffset;
		YPos = _YOffset;
	}

	unsigned int XSize = 0;
	unsigned int YSize = 0;
	unsigned int XPos = END;
	unsigned int YPos = END;
};



#endif