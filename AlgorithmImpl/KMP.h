#include <iostream>
#include <vector>

using namespace std;

namespace AlgorithmImpl
{
	class KMP
	{
	public:
		static vector<int> buildMatchTable(char * text, char * stringOfInterest){
			string strText(text);
			string strOfInterest(stringOfInterest);
			return buildMatchTable(strText, strOfInterest);
		}

		static vector<int> buildPrefixTable(const string &stringOfInterest){
			vector<int> prefix;
			prefix.push_back(-1);
			int backTrack = -1;
			for(int i=1;i<stringOfInterest.size();++i){
				while( backTrack != -1 && stringOfInterest[backTrack+1] != stringOfInterest[i]){
					backTrack = prefix[backTrack];
				}
				if( stringOfInterest[backTrack+1] == stringOfInterest[i])
					backTrack ++;
				prefix.push_back( backTrack );
			}

			return prefix;
		}

		static vector<int> buildMatchTable(const string &text, const string &stringOfInterest){
			vector<int> prefix = buildPrefixTable(stringOfInterest);
			vector<int> matchTable(text.size(), -1);
			if( stringOfInterest.size() == 0)
				return matchTable;
			int backTrack = -1;
			for(int i = 0; i < text.size(); ++i){
				while( backTrack != -1 && stringOfInterest[backTrack+1] != text[i] ){
					backTrack = prefix[backTrack];
				}
				if( stringOfInterest[backTrack+1] == text[i] ){
					backTrack++;
				}
				matchTable[i] = backTrack;
				if( backTrack == stringOfInterest.size() - 1 ){
					backTrack = prefix[backTrack];
				}
			}

			return matchTable;
		}
	};
}