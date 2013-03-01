#include <iostream>

using namespace std;

namespace AlgorithmImpl 
{
	class BitOperation
	{
	public:
		static int bitCount(int v)
		{
			v = ( v & 0x55555555 ) + ( (v>>1) & 0x55555555 );
			v = ( v & 0x33333333 ) + ( (v>>2) & 0x33333333 );
			v = ( v & 0x0f0f0f0f ) + ( (v>>4) & 0x0f0f0f0f );
			v = ( v & 0x00ff00ff ) + ( (v>>8) & 0x00ff00ff );
			v = ( v & 0x0000ffff ) + ( (v>>16) & 0x0000ffff );

			return v;
		}
	};
}