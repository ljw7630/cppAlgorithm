#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace AlgorithmImpl
{
	class BigInteger
	{
	private:
		string value;

		void integerToString(int v, string &str)
		{
			str.clear();

			if(v == 0)
			{
				str.push_back('0');
				return;
			}
			char sign = '\0';
			if(v < 0)
			{
				sign = '-';
				v = -v;
			}
			
			while(v)
			{
				str.push_back(v%10+'0');
				v /= 10;
			}
			if(sign == '-')
				str.push_back(sign);
			reverse(str.begin(), str.end());
		}

		string reversedVectorToString(const vector<int> &vec)
		{
			string str;
			reversedVectorToString(vec, str);
			return str;
		}

		void reversedVectorToString(const vector<int> &vec, string &str)
		{
			if(vec.size() == 0)
				throw exception();
			if(vec.size() == 1 && vec[0]==-1)
				throw exception();

			str.clear();			
			int begin = vec.size()-1;
			if(vec[begin] == -1)
			{
				begin = vec.size()-2;
				str.push_back('-');
			}
			for(int idx = begin; idx > -1;--idx)
			{
				str.push_back(vec[idx]+'0');
			}
		}

		void stringToReversedVector(const string &str, vector<int> &output)
		{						
			output.clear();
			output.reserve(str.size());
			int begin = 0;
			if(str[0] == '-') 
				begin = 1;
			for(int idx = str.size()-1; idx>=begin;--idx)
			{
				output.push_back(str[idx] - '0');
			}

			// trim the heading 0s
			for(int idx = output.size()-1; idx > -1; --idx)
			{
				if(output[idx]==0)
					output.pop_back();
				else
					break;
			}

			if(begin)
				output.push_back(-1);
		}

	public:
		BigInteger(int v)
		{			
			integerToString(v, this->value);
		}

		BigInteger()
		{
			*this = BigInteger(0);
		}

		BigInteger(string str)
		{
			this->value = str;
		}

		BigInteger(const BigInteger &integer)
		{
			this->value = integer.value;
		}

		BigInteger & operator= (const BigInteger &other)
		{
			if(this != &other)
			{
				this->value = other.value;
			}

			return *this;
		}

		const string& getValue()
		{
			return value;
		}

		void print()
		{
			cout << value << endl;
		}

		BigInteger add(const BigInteger &param)
		{
			if(value.size() == 0)
				return param;
			if(param.value.size() == 0)
				return *this;

			if( (value.size()==1 && value[0]=='-' )
				|| (param.value.size()==1 && param.value[0]=='-') )
				throw exception();

			vector<int> leftOperand, rightOperand, result;
			stringToReversedVector(value, leftOperand);
			stringToReversedVector(param.value, rightOperand);

			if(leftOperand[leftOperand.size()-1] == -1 && rightOperand[rightOperand.size()-1] == -1)
			{
				leftOperand.pop_back();
				rightOperand.pop_back();
				add(leftOperand, rightOperand, result);
				result.push_back(-1);
			}			
			else if(leftOperand[leftOperand.size()-1] != -1 && rightOperand[rightOperand.size()-1] != -1)
			{
				add(leftOperand, rightOperand, result);
			}
			else
			{			
				if(leftOperand[leftOperand.size()-1] == -1)
				{
					leftOperand.pop_back();
					substract(rightOperand, leftOperand, result);
				}
				else
				{
					rightOperand.pop_back();
					substract(leftOperand, rightOperand, result);
				}
			}

			return BigInteger(reversedVectorToString(result));
		}

		BigInteger substract(BigInteger &param)
		{
			if(value.size() == 0)
				return param;
			if(param.value.size() == 0)
				return *this;

			if( (value.size()==1 && value[0]=='-' )
				|| (param.value.size()==1 && param.value[0]=='-') )
				throw exception();

			vector<int> leftOperand, rightOperand, result;
			stringToReversedVector(value, leftOperand);
			stringToReversedVector(param.value, rightOperand);

			if(leftOperand[leftOperand.size()-1] == -1 && rightOperand[rightOperand.size()-1] == -1)
			{
				rightOperand.pop_back();
				leftOperand.pop_back();
				substract(rightOperand, leftOperand, result);
			}
			else if(leftOperand[leftOperand.size()-1] != -1 && rightOperand[rightOperand.size()-1] != -1)
			{
				substract(leftOperand, rightOperand, result);
			}
			else
			{
				if(leftOperand[leftOperand.size()-1] == -1)
				{
					leftOperand.pop_back();
					add(leftOperand, rightOperand, result);
					result.push_back(-1);
				}
				else
				{
					rightOperand.pop_back();
					add(leftOperand, rightOperand, result);
				}
			}

			return BigInteger(reversedVectorToString(result));
		}

	private:
		void add(const vector<int> &p1,const vector<int> &p2, vector<int> &output)
		{
			output.clear();
			vector<int> param1, param2;
			if(p1.size() < p2.size())
			{
				param1 = vector<int>(p2);
				param2 = vector<int>(p1);
			}
			else
			{
				param1 = vector<int>(p1);
				param2 = vector<int>(p2);
			}

			output.reserve(param1.size()+1);

			int carry = 0;
			for(int i=0;i<param2.size();++i)
			{
				int tmp = (param1[i]+param2[i]+carry);
				carry = tmp / 10;
				output.push_back(tmp%10);
			}

			for(int i = param2.size(); i<param1.size();++i)
			{
				int tmp = (carry+param1[i]);
				carry = tmp / 10;
				output.push_back(tmp%10);
			}
			if(carry)
				output.push_back(carry);			
		}

		void substract(const vector<int> &p1, const vector<int> &p2, vector<int> &output)
		{
			int cmpValue = comparePositiveValue(p1, p2);
			if(!cmpValue)
			{
				output.push_back(0);
				return;
			}
			int sign = 0;
			vector<int> param1, param2;
			if(cmpValue < 0)
			{
				sign = -1;
				
				param1 = vector<int> (p2);
				param2 = vector<int> (p1);
			}
			else
			{
				param1 = vector<int> (p1);
				param2 = vector<int> (p2);
			}
			int carry = 0;
			for(int i=0;i<param2.size();++i)
			{
				int tmp = (param1[i] + carry) - param2[i];
				if(tmp < 0)
				{
					tmp += 10;
					carry=-1;
				}
				else
				{
					carry = 0;
				}
				output.push_back(tmp%10);				
			}
						
			for(int i=param2.size();i<param1.size();++i)
			{			
				if(carry==0)
					output.push_back(param1[i]);
				else
				{
					int tmp = carry + param1[i];
					if(tmp<0)
						tmp+=10;
					else
					{
						carry = 0;
					}
					output.push_back(tmp%10);
				}
			}
			for(int i=output.size()-1;i>-1;--i)
			{
				if(output[i] == 0)
				{
					output.pop_back();
				}
				else
				{
					break;
				}
			}

			if(sign==-1)
				output.push_back(sign);
		}

		int comparePositiveValue(const vector<int> &param1, const vector<int> &param2)
		{
			if(param1.size()!=param2.size())
			{
				if(param1.size() < param2.size())
					return -1;
				else
					return 1;
			}
			for(int idx = param1.size()-1; idx>-1;--idx)
			{
				if(param1[idx] > param2[idx])
					return 1;
				else if(param1[idx] < param2[idx])
					return -1;
			}
			return 0;
		}

		int compareAbsoluteValue(const vector<int> &param1, const vector<int> &param2)
		{
			vector<int> a(param1);
			vector<int> b(param2);

			if(a[a.size()-1]==-1)
				a.pop_back();
			if(b[b.size()-1]==-1)
				b.pop_back();

			if(a.size() > b.size())
				return 1;
			else if(a.size() < b.size())
				return -1;
			else
			{
				return comparePositiveValue(param1, param2);
			}
		}
	};
}