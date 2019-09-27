// --------------------------------------------------------------
// Name    Yuki Waka       Date   2019/08/08   student#: 141082180   
/////////////////////////////////////////////////////////////////
#ifndef _ERROR_H_
#define _ERROR_H_

namespace aid
{
	class Error
	{
		char* errM;

	public:
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator= (const Error& em) = delete;
		virtual ~Error();

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator << (std::ostream&, const Error&);
}
#endif 